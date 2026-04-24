# Acrome Inverted Pendulum — PPO Reinforcement Learning Controller

## 项目简介

本项目将 Acrome 倒立摆系统从传统 LQR 控制器替换为 PPO（近端策略优化）强化学习控制器，实现 Sim2Real 部署。硬件平台为树莓派 + Acrome 控制板，开发环境为 MATLAB R2025a + Simulink。

---

## 硬件配置

```
PC (Mac) ←─ 网线 ─→ 树莓派 (aarch64) ←─ 串口 ─→ Acrome 控制板 ←→ 电机 + 传感器
```

| 项目 | 参数 |
|------|------|
| 串口 | /dev/serial0，115200bps，8N1 |
| 控制频率 | 250Hz（TAU = 0.004s） |
| 电机电压 | 12V |
| PWM 范围 | ±1800（训练用 ±800） |
| 树莓派 IP | 192.168.137.73 |
| 用户名/密码 | acrome / raspberry |

---

## 文件结构

```
/rl/pendulum/Code/
├── PendulumQuickStart.slx               # 原厂 LQR Simulink 模型
├── PendulumQuickStart_RL.slx            # 添加 RL 控制器的 Simulink 模型
├── Potentiometer_Calibration.slx        # 电位器校准模型
├── Linear_System_Model_LQR_Matrixes.m  # 原厂 LQR 参数脚本
├── cart_pole_modelsimulink.m            # PPO 训练用物理模型
├── continueppo.m                        # PPO 训练主文件
├── actor_net_cont.mat                   # 最终训练网络
├── actor_net_best.mat                   # 训练过程最佳网络
└── calibrateVal.mat                     # 电位器校准数据
```

---

## 已确认的系统参数

### 物理参数（原厂 Simulink 工作区读出）

| 参数 | 值 | 说明 |
|------|----|------|
| Mc | 0.4719 kg | 小车质量 |
| Mp | 0.1679 kg | 摆杆质量 |
| Lp | 0.2125 m | 摆杆质心距离（0.425/2） |
| Jp | 0.01 kg·m² | 转动惯量 |
| Bp | 0.024 Nms/rad | 旋转阻尼 |
| Beq | 30 N·s/m | 等效阻尼（含反电动势） |
| Kt | 0.08505 N·m/A | 电机力矩常数 |
| Kb | 0.11693 V·s/rad | 反电动势常数 |
| Rm | 2.12 Ω | 电机电阻 |
| rmp | 0.013745 m | 皮带轮半径 |

### 传感器换算

**串口数据包（10 字节）**

```
帧头：0x55  0xBF
Byte[2:3]：RodAnalog（int16，小端序）→ 摆杆电位器原始值
Byte[4:5]：cartEnc  （int16，小端序）→ 小车编码器原始值
Byte[6:9]：CRC32 校验
```

**小车位置**

```
x(m) = cartEnc × (−0.001)

编码器范围：约 −327 到 +330 counts
物理中心：  约 9 counts（实测，每次开机略有变化）
LQR 平衡时：20—70 counts 之间漂移
方向定义：  小车往右 → cartpos 增大 → x 减小（x 正方向 = 往左）
```

**摆杆角度**

```
theta(deg) = (RodAnalog − 2074) / 4085 × 360
theta(rad) = theta(deg) × π/180

竖直向上 = 0°  = 0 rad
自然下垂 ≈ 178°
竖直时 RodAnalog ≈ 2074（校准后）
```

### PWM 与力的换算（实测反推）

```
1 N → 62.6 PWM
PWM = F × 62.6

验证：LQR 平衡时 u ≈ 5N → PWM ≈ 313，实测 PWM ≈ 300  ✅
```

### LQR 参数（原厂）

```
K     = [−38.73,  164.21,  −76.34,  41.06]
状态   = [x(m),   theta(rad),  x_dot(m/s),  theta_dot(rad/s)]
Q     = diag([3000, 5000, 1, 1])
R     = 2
```

---

## Simulink 信号流

```
串口接收（10 字节）
    ↓
Touchscreen（解包）
    ├── RodAnalog → Convert（Analog to Angle）→ RodAngle（度）
    └── cartEnc   → [Pos]（counts）
    ↓
Pendulum Control
    ├── cartpos × (−0.001)          → x（m）         → LQR & RL
    ├── RodAngle → Saturation       → [Angle]（度）   → LQR & RL
    ├── [Pos] → Transfer Fcn → ×0.001 → x_dot（m/s） → LQR & RL
    │   Transfer Fcn：1Hz 截止，阻尼比 0.9
    └── [Angle] → 2nd Order → ×(π/180) → θ_dot（rad/s）→ LQR & RL
        2nd Order：0.5Hz 截止，阻尼比 0.9
    ↓
LQR controller
    u = −K × [x; θ; ẋ; θ̇]
    u(N) → F/Volt → ×100 → PWM Gain → PWM（±1800）
    ↓
Switch（手动切换）
    Switch = 1 → LQR 输出 → torque
    Switch = 0 → RL  输出 → torque
    ↓
Servo Motor（串口发送，9 字节）
```

### 滤波器参数

| 滤波器 | 截止频率 | 分子 | 分母 |
|--------|---------|------|------|
| Transfer Fcn（位置微分） | 1 Hz | `[(2π)² 0]` | `[1, 11.31, 39.48]` |
| 2nd Order（角度微分） | 0.5 Hz | `[(π)² 0]` | `[1, 5.655, 9.87]` |

---

## PPO 训练

### 物理模型（cart_pole_modelsimulink.m）

```matlab
% PWM → 力（正号，实测校准）
F = pwm / 62.6;

% 反电动势阻力 + 纯机械摩擦
back_emf = Kb * Kt * xDot / (Rm * rmp^2);
b_mech   = 30 - Kb * Kt / (Rm * rmp^2);   % ≈ 5 N·s/m

% 运动方程（+号重力项：θ=0 为不稳定平衡点，即竖直向上）
F_vector = [F - back_emf - b_mech*xDot + ml*thetaDot^2*sin_th;
            −d*thetaDot + Mp*g*l*sin_th];
```

### 网络结构

```
输入层：4 维（[x, ẋ/5, θ, θ̇/10]）
隐藏层1：64 节点，ReLU
隐藏层2：64 节点，ReLU
输出层：2 维（[mu, log_std]）
```

### 训练超参数

| 参数 | 值 |
|------|----|
| ACTOR_LR | 1e-4 |
| CRITIC_LR | 1e-3 |
| GAMMA | 0.99 |
| LAMBDA | 0.95 |
| ENTROPY_BETA | 0.005 |
| CLIP_EPSILON | 0.2 |
| K_EPOCHS | 10 |
| BATCH_SIZE | 128 |
| MAX_STEPS | 5000 |
| MAX_ACTION | 800 PWM |

### 状态定义与归一化

```matlab
state = [x; xDot/5.0; theta; thetaDot/10.0]
% x     单位 m，  归一化系数 1（不归一化）
% xDot  单位 m/s，归一化系数 5
% theta 单位 rad，归一化系数 1（不归一化）
% thetaDot 单位 rad/s，归一化系数 10
```

### 奖励函数

```matlab
if abs(thetaNext) > 0.2 || abs(xNext) > 0.2
    r = -20;   % 终止惩罚
else
    r_survive = 10.0;
    r_theta   = -5.0  * (thetaNext / 0.2)^2;      % 角度惩罚
    r_x       = -2.0  * (xNext    / 0.2)^2;       % 位置惩罚
    r_force   = -0.5  * (|action| / MAX_ACTION)^2; % 力惩罚
    r_smooth  = -1.0  * (action_diff / 2.0)^2;     % 平滑惩罚
    r = r_survive + r_theta + r_x + r_force + r_smooth;
end
```

### 训练结果（仿真）

- 收敛轮数：约 300 episodes
- 仿真测试角度：±0.01 rad 以内
- PWM 输出：起步约 ±500，平滑收敛，无 bang-bang

---

## RL_Controller 部署代码

```matlab
function pwm = fcn(cartpos_counts, rodAngle, cartVel_ms, rodVel_rads)
%#codegen
persistent actorNet isLoaded
if isempty(isLoaded)
    actorNet = coder.loadDeepLearningNetwork('actor_net_best.mat', 'actorNet');
    isLoaded = true;
end

X_OFFSET     = 9.0;   % 小车中心编码器值（实测，每次开机可能略有不同）
THETA_OFFSET = 0.0;   % 摆杆角度偏置（度），如有系统偏差可在此调整

% 状态换算（与训练完全一致）
x     = (cartpos_counts - X_OFFSET) * (-0.001); % counts → m
v     = cartVel_ms / 5.0;                        % m/s → 归一化
theta = (rodAngle - THETA_OFFSET) * (pi / 180); % 度 → 弧度
omega = rodVel_rads / 10.0;                      % rad/s → 归一化

state     = [x; v; theta; omega];
MAX_ACTION = 800.0;

dlState   = dlarray(single(state), 'CB');
out_actor = extractdata(predict(actorNet, dlState));
mu        = tanh(double(out_actor(1)));

% 位置偏差动态缩放（防止切换时冲击过猛）
scale = 1.0 - 0.5 * (abs(x) / 0.25);
scale = max(scale, 0.3);

pwm = -mu * MAX_ACTION * scale;
```

---

## 实机操作流程

### 每次开机校准（必须）

```bash
# 1. 打开 Potentiometer_Calibration.slx
# 2. 编译部署，连接树莓派
# 3. 手转摆杆完整一圈（360°）
# 4. 摆杆放到自然下垂位置，点界面上的 Save
# 5. MATLAB Command Window 运行：
SaveCalibrateData

# 6. Mac 终端传输校准文件到树莓派：
scp /Users/chenyihong/rl/pendulum/Code/calibrateVal.mat \
    acrome@192.168.137.73:/home/acrome/MATLAB_ws/R2025a/Users/chenyihong/rl/pendulum/Code/
```

### LQR 启动步骤

```
1. 打开 PendulumQuickStart_RL.slx
2. 点"编译、部署和启动"
3. 点"监控并调节"
4. Enable       → On
5. 等 homed = 1
6. Home         → On（小车归零）
7. Move Center  → On（小车移到中间）
8. Mode         → Pendulum Control
9. Enable Control → On
10. 手推摆杆到竖直位置，LQR 自动接管平衡
```

### LQR / RL 切换

```
Switch = 1  →  LQR 控制（默认）
Switch = 0  →  RL  控制

切换建议：
  - LQR 跑稳后，等 cartpos 在 20—50 之间再切换到 RL
  - 如 RL 失稳，立即切回 Switch = 1
```

---

## 当前进展与问题

### 已完成

- LQR 在真机上稳定运行（摆杆可长时间平衡）
- 串口通信协议完全逆向（10 字节数据包格式确认）
- 所有传感器换算公式从 Simulink 源码提取并验证
- PPO 训练在仿真里收敛（约 300 episodes）
- RL_Controller 集成到 Simulink，输出方向与 LQR 一致
- RL_Controller在真机上可以进行运行，前提是手挡住 作为微控 不然会撞到边界

### 待解决

- **Sim2Real Gap**：仿真物理模型与真机动态不一致，切换到 RL 后控制震荡、小车撞边界
- 真机 LQR 仿真验证失败（物理模型中任意符号组合均无法让 LQR 仿真稳定）

---

## 下一步方案：行为克隆 + PPO 微调

**核心思路**：不依赖物理模型，直接用真机 LQR 运行数据训练网络。

### 步骤

**Step 1：真机数据采集**

LQR 在真机上运行 60 秒，在 Simulink 数据检查器里记录：

| 信号 | 说明 |
|------|------|
| Gain:1 | x（m） |
| Convert:1 | RodAngle（度） |
| Gain3:1 | x_dot（m/s） |
| Gain6:1 | theta_dot（rad/s） |
| PWM Gain:1 | LQR 输出 PWM |

**Step 2：行为克隆训练**

```matlab
% 监督学习：让网络模仿 LQR
% 输入：[x, xDot/5, theta, thetaDot/10]
% 输出：PWM
% 损失：MSE(网络输出, LQR_PWM)
```

**Step 3：PPO 微调**

在行为克隆基础上继续用 PPO 优化，改善位置回中能力。

**优势**：
- 完全绕过 Sim2Real Gap
- 网络初始化接近 LQR，不会乱输出满量程
- 训练数据来自真机，方向和量级完全正确

---

## 常用命令

```bash
# SSH 连接树莓派
ssh acrome@192.168.137.73
# 密码：raspberry

# 查看程序是否运行
ps aux | grep Pendulum

# 停止程序
sudo killall PendulumQuickStart.elf

# 传输文件到树莓派
scp <本地路径> acrome@192.168.137.73:<目标路径>

# 查看串口设备
ls -la /dev/serial*
```

---

## 环境依赖

| 平台 | 依赖 |
|------|------|
| Mac（开发端） | MATLAB R2025a，Simulink，Deep Learning Toolbox，MATLAB Support Package for Raspberry Pi |
| 树莓派 | Python 3.11，pyserial，GCC 12.2，make |
