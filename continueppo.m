%**************************************************************************
% Continuous PPO for Research
% 面向研究的连续近端策略优化算法
% 
% 核心升级：
% 1. 动作空间连续化：网络输出高斯分布的均值 (mu) 和对数标准差 (log_std)
% 2. 彻底解决离散控制下的高频 Bang-Bang 震荡问题，动作如丝般顺滑
%**************************************************************************
clc; clear; close all;

% =========================================================================
% 1. 超参数 (Continuous PPO Hyperparameters)
% =========================================================================
ACTOR_LR     = 1e-4;      
CRITIC_LR    = 1e-3;      
GAMMA        = 0.99;      
LAMBDA       = 0.95;      
ENTROPY_BETA = 0.005;     % 连续空间的熵系数通常可以设小一点
CLIP_EPSILON = 0.2;       
K_EPOCHS     = 10;        
BATCH_SIZE   = 128;       
MAX_EPISODES = 5000;
MAX_STEPS    = 2000;

% 【核心修改】不再定义离散的 ACTION_SPACE，只需定义最大力矩
MAX_ACTION   = 800;       % PWM 最大绝对值

% =========================================================================
% 2. 构建网络
% =========================================================================
% 【核心修改】Actor 网络输出层改为 2 个节点：分别代表 mu(均值) 和 log_std(对数标准差)
actorLayers = [
    featureInputLayer(4, 'Normalization', 'none', 'Name', 'state_in')
    fullyConnectedLayer(64, 'Name', 'fc1')
    reluLayer('Name', 'relu1')
    fullyConnectedLayer(64, 'Name', 'fc2')
    reluLayer('Name', 'relu2')
    fullyConnectedLayer(2, 'Name', 'fc_out') % 输出维度为 2 [mu; log_std]
];
actorNet = dlnetwork(actorLayers);

criticLayers = [
    featureInputLayer(4, 'Normalization', 'none', 'Name', 'state_in')
    fullyConnectedLayer(64, 'Name', 'fc1')
    reluLayer('Name', 'relu1')
    fullyConnectedLayer(64, 'Name', 'fc2')
    reluLayer('Name', 'relu2')
    fullyConnectedLayer(1, 'Name', 'v_out')
];
criticNet = dlnetwork(criticLayers);

avgGradA = []; avgSqGradA = [];
avgGradC = []; avgSqGradC = [];
global_step = 0;

% =========================================================================
% 3. 绘图与日志
% =========================================================================
history_steps = [];
figure(1);
hLine = plot(NaN, NaN, '-b.');
title('Continuous PPO 训练监控 (平滑连续控制)');
xlabel('回合数 Episodes'); ylabel('存活步数 Steps');
grid on;
fprintf('开始 Continuous PPO 训练...\n');

% =========================================================================
% 4. 主训练循环
% =========================================================================
for episode = 1:MAX_EPISODES
    % 初始随机偏角
    theta = (rand() - 0.5) * 0.1;  
    thetaDot = 0; x = 0; xDot = 0;
    
    % 轨迹缓存
    states_hist          = zeros(4, MAX_STEPS);
    actions_norm_hist    = zeros(1, MAX_STEPS); % 记录归一化的动作 [-1, 1]
    old_log_probs_hist   = zeros(1, MAX_STEPS); % 【修改】连续空间记录的是 log 概率
    rewards_hist         = zeros(1, MAX_STEPS);
    dones_hist           = zeros(1, MAX_STEPS);
    values_hist          = zeros(1, MAX_STEPS);
    
    steps = 0; done = false;
    
    % ---------------------------------------------------------------------
    % 阶段 A: Rollout (高斯分布采样)
    % ---------------------------------------------------------------------
    while ~done && steps < MAX_STEPS
        steps = steps + 1;
        
        currentState = [x; xDot/5.0; theta; thetaDot/10.0];
        states_hist(:, steps) = currentState;
        dlState = dlarray(currentState, 'CB');
        
        % 获取 Actor 和 Critic 输出
        out_actor = extractdata(predict(actorNet, dlState));
        v_current = extractdata(predict(criticNet, dlState));
        
        % 【核心修改】连续动作的生成逻辑
        mu = tanh(out_actor(1));             % 取第一个输出作为均值，用 tanh 限制在 [-1, 1]
        log_std = min(max(out_actor(2), -20), 2); % 取第二个输出作为标准差，做限幅防爆
        sigma = exp(log_std);
        
        % 从高斯分布中采样动作：a = mu + sigma * N(0,1)
        action_norm = mu + sigma * randn(); 
        action_norm = min(max(action_norm, -1), 1); % 物理限幅 [-1, 1]
        
        % 计算该动作的对数概率 (Gaussian Log-Probability)
        var = sigma^2;
        log_prob = -0.5 * ((action_norm - mu)^2) / var - log_std - 0.5 * log(2*pi);
        
        % 映射到真实物理推力
        currentAction = action_norm * MAX_ACTION;
        
        % 记录数据
        actions_norm_hist(steps)  = action_norm;
        old_log_probs_hist(steps) = log_prob;
        values_hist(steps)        = v_current;
        
        % 物理模型推演
        [thetaNext, thetaDotNext, ~, xNext, xDotNext] = ...
            cart_pole_modelsimulink(currentAction, theta, thetaDot, x, xDot);
            
        % --- 奖励计算 ---
        if abs(thetaNext) > 0.2 || abs(xNext) > 0.5
            r = -20; 
            done = true;
        else
            r_survive = 10.0; 
            r_theta   = -5.0 * (thetaNext / 0.2)^2; 
            r_x       = -2.0 * (xNext / 0.5)^2; 
            r_force   = -0.5 * (abs(currentAction) / MAX_ACTION)^2; 
            
            % 平滑惩罚 (依然有效，但在连续空间下网络会学得更好)
            if steps > 1
                prev_action_norm = actions_norm_hist(steps-1);
                action_diff = abs(action_norm - prev_action_norm);
                r_smooth = -1.0 * (action_diff / 2.0)^2; % 最大差值是 2 (-1到1)
            else
                r_smooth = 0;
            end
            
            r = r_survive + r_theta + r_x + r_force + r_smooth;
            done = false;
        end
        
        rewards_hist(steps) = r;
        dones_hist(steps)   = done;
        theta = thetaNext; thetaDot = thetaDotNext; x = xNext; xDot = xDotNext;
    end
    
    % 截断缓存
    states_hist        = states_hist(:, 1:steps);
    actions_norm_hist  = actions_norm_hist(1:steps);
    rewards_hist       = rewards_hist(1:steps);
    dones_hist         = dones_hist(1:steps);
    old_log_probs_hist = old_log_probs_hist(1:steps);
    values_hist        = values_hist(1:steps);
    
    % ---------------------------------------------------------------------
    % 阶段 B: GAE 计算
    % ---------------------------------------------------------------------
    dlNextState = dlarray([x; xDot/5.0; theta; thetaDot/10.0], 'CB');
    v_last = extractdata(predict(criticNet, dlNextState));
    values_extended = [values_hist, v_last]; 
    
    advantages = zeros(1, steps);
    gae_running = 0;
    for t = steps:-1:1
        delta = rewards_hist(t) + GAMMA * values_extended(t+1) * (1 - dones_hist(t)) - values_extended(t);
        gae_running = delta + GAMMA * LAMBDA * (1 - dones_hist(t)) * gae_running;
        advantages(t) = gae_running;
    end
    td_targets = advantages + values_hist;
    
    if length(advantages) > 5
        advantages = (advantages - mean(advantages)) / (std(advantages) + 1e-8);
    end
    
    % ---------------------------------------------------------------------
    % 阶段 C: PPO 网络更新
    % ---------------------------------------------------------------------
    for epoch = 1:K_EPOCHS
        indices = randperm(steps);
        for start_idx = 1:BATCH_SIZE:steps
            end_idx = min(start_idx + BATCH_SIZE - 1, steps);
            batch_idx = indices(start_idx:end_idx); 
            
            mb_states       = dlarray(states_hist(:, batch_idx), 'CB');
            mb_actions      = dlarray(actions_norm_hist(batch_idx), 'CB');
            mb_oldLogProbs  = dlarray(old_log_probs_hist(batch_idx), 'CB');
            mb_targets      = dlarray(td_targets(batch_idx), 'CB');
            mb_advantages   = dlarray(advantages(batch_idx), 'CB');
            
            global_step = global_step + 1;
            
            [lossA, lossC, gradA, gradC] = dlfeval(@ppoGradientsContinuous, ...
                actorNet, criticNet, ...
                mb_states, mb_actions, mb_oldLogProbs, mb_targets, mb_advantages, ...
                ENTROPY_BETA, CLIP_EPSILON);
            
            max_grad = 0.5; 
            gradA = dlupdate(@(g) min(max(g, -max_grad), max_grad), gradA);
            gradC = dlupdate(@(g) min(max(g, -max_grad), max_grad), gradC);
            
            [actorNet,  avgGradA, avgSqGradA] = adamupdate(actorNet,  gradA, avgGradA, avgSqGradA, global_step, ACTOR_LR);
            [criticNet, avgGradC, avgSqGradC] = adamupdate(criticNet, gradC, avgGradC, avgSqGradC, global_step, CRITIC_LR);
        end
    end
    
    % --- 日志打印 ---
    history_steps(end+1) = steps;
    if mod(episode, 10) == 0
        set(hLine, 'XData', 1:episode, 'YData', history_steps);
        drawnow;
        fprintf('Ep %4d | Steps %4d | ActorLoss %7.4f | CriticLoss %7.4f\n', ...
            episode, steps, extractdata(lossA), extractdata(lossC));
    end
    
    if mean(history_steps(max(1, end-50):end)) >= MAX_STEPS - 10
        fprintf('\n*** Continuous PPO 训练收敛！完美平衡！ ***\n');
        break;
    end
    
    if episode > 30 && mean(history_steps(max(1, end-30):end)) > 1800
        ACTOR_LR = max(ACTOR_LR * 0.99, 1e-5); 
        CRITIC_LR = max(CRITIC_LR * 0.99, 1e-4); 
        ENTROPY_BETA = max(ENTROPY_BETA * 0.99, 0.0001); 
        CLIP_EPSILON = max(CLIP_EPSILON * 0.99, 0.05);
    end
end
save('actor_net_cont.mat', 'actorNet');
fprintf('连续 Actor 网络已保存！\n');

% =========================================================================
% 5. 训练完成后的测试与可视化 (无探索模式)
% =========================================================================
fprintf('\n开始测试连续策略...\n');
theta = (rand() - 0.5) * 0.1;  
thetaDot = 0; x = 0; xDot = 0;
test_steps = 2000;

record_theta = zeros(1, test_steps);
record_force = zeros(1, test_steps);

for t = 1:test_steps
    record_theta(t) = theta;
    
    currentState = [x; xDot/5.0; theta; thetaDot/10.0];
    dlState = dlarray(currentState, 'CB');
    
    out_actor = extractdata(predict(actorNet, dlState));
    
    % 【核心区别】测试阶段关闭探索：直接取高斯分布的均值 (mu) 作为唯一动作
    mu = tanh(out_actor(1)); 
    currentAction = mu * MAX_ACTION;
    
    record_force(t) = currentAction;
    
    [thetaNext, thetaDotNext, ~, xNext, xDotNext] = ...
        cart_pole_modelsimulink(currentAction, theta, thetaDot, x, xDot);
        
    if abs(thetaNext) > 0.2 || abs(xNext) > 0.5
        fprintf('测试在第 %d 步提前结束（越界）。\n', t);
        record_theta = record_theta(1:t);
        record_force = record_force(1:t);
        break;
    end
    
    theta = thetaNext; thetaDot = thetaDotNext; x = xNext; xDot = xDotNext;
end

% 绘图保持不变
figure('Name', '验证 Continuous PPO', 'Position', [100, 100, 800, 600]);
subplot(2, 1, 1);
plot(1:length(record_theta), record_theta, 'b-', 'LineWidth', 1.5);
hold on; yline(0, 'k--', 'LineWidth', 1); yline(0.2, 'r:', 'LineWidth', 1.5); yline(-0.2, 'r:', 'LineWidth', 1.5);
title('摆杆角度 (\theta) 随时间变化'); xlabel('步数'); ylabel('角度 (rad)'); ylim([-0.25, 0.25]); grid on;
subplot(2, 1, 2);
plot(1:length(record_force), record_force, 'r-', 'LineWidth', 1.2);
title('智能体输出动作 (Force/PWM) 随时间变化'); xlabel('步数'); ylabel('输出推力'); 
ylim([-MAX_ACTION*1.1, MAX_ACTION*1.1]); grid on;
sgtitle('连续动作空间 PPO：丝滑控制体验');

% =========================================================================
% 局部函数：连续 PPO 梯度计算
% =========================================================================
function [lossActor, lossCritic, gradActor, gradCritic] = ...
        ppoGradientsContinuous(actorNet, criticNet, mbStates, mbActions, mbOldLogProbs, mbTargets, mbAdvantages, entropyBeta, clipEps)
    
    % 前向传播获取均值和对数标准差
    out_actor = forward(actorNet, mbStates);
    mu = tanh(out_actor(1, :));
    log_std = min(max(out_actor(2, :), -20), 2); % 限幅防止数值爆炸
    sigma = exp(log_std);
    
    vValues = forward(criticNet, mbStates);
    lossCritic = 0.5 * mse(vValues, mbTargets);
    
    % 计算当前策略下，采样到这些动作的对数概率
    var = sigma.^2;
    log_probs = -0.5 * ((mbActions - mu).^2) ./ var - log_std - 0.5 * log(2*pi);
    
    % 计算重要性采样比例 rho (指数相减)
    rho = exp(log_probs - mbOldLogProbs);
    
    % Surrogate Loss
    surrogate1 = rho .* mbAdvantages;
    rho_clipped = max(min(rho, 1 + clipEps), 1 - clipEps);
    surrogate2  = rho_clipped .* mbAdvantages;
    
    lossActor = -mean(min(surrogate1, surrogate2));
    
    % 连续高斯分布的熵公式：0.5 + 0.5*ln(2*pi) + ln(sigma)
    entropy = mean(0.5 + 0.5 * log(2*pi) + log_std);
    lossActor = lossActor - entropyBeta * entropy;
    
    gradActor  = dlgradient(lossActor,  actorNet.Learnables);
    gradCritic = dlgradient(lossCritic, criticNet.Learnables);
end