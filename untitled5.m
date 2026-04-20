load('actor_net.mat');
% 测试训练好的网络，从theta=0.05开始
theta = 0.05; thetaDot = 0; x = 0; xDot = 0;
survived = 0;

for t = 1:2000
    currentState = [x; xDot; theta; thetaDot];
    dlState = dlarray(currentState, 'CB');
    actionProbs = extractdata(predict(actorNet, dlState));
    [~, maxIdx] = max(actionProbs);
    ACTION_SPACE = [400 200 100 50 20 10 0 -10 -20 -50 -100 -200 -400];
    currentAction = ACTION_SPACE(maxIdx);
    
    [thetaNext, thetaDotNext, ~, xNext, xDotNext] = ...
        cart_pole_modelsimulink(currentAction, theta, thetaDot, x, xDot);
    
    if abs(thetaNext) > 0.2 || abs(xNext) > 0.5
        fprintf('第 %d 步倒下了\n', t);
        break;
    end
    survived = survived + 1;
    theta = thetaNext; thetaDot = thetaDotNext;
    x = xNext; xDot = xDotNext;
end
fprintf('存活了 %d 步\n', survived);