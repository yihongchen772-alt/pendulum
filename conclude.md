# Acrome Inverted Pendulum — PPO Reinforcement Learning Controller

## Project Overview

This project replaces the factory LQR controller on the Acrome inverted pendulum system with a PPO (Proximal Policy Optimization) reinforcement learning controller, achieving Sim2Real deployment. The hardware platform is Raspberry Pi + Acrome control board, developed in MATLAB R2025a + Simulink.

---

## Hardware Configuration

```
PC (Mac) ←─ Ethernet ─→ Raspberry Pi (aarch64) ←─ Serial ─→ Acrome Board ←→ Motor + Sensors
```

| Item | Value |
|------|-------|
| Serial Port | /dev/serial0, 115200 bps, 8N1 |
| Control Frequency | 250 Hz (TAU = 0.004 s) |
| Motor Voltage | 12 V |
| PWM Range | ±1800 (training: ±800) |
| Raspberry Pi IP | 192.168.137.73 |
| Username / Password | acrome / raspberry |

---

## File Structure

```
/rl/pendulum/Code/
├── PendulumQuickStart.slx               # Factory LQR Simulink model
├── PendulumQuickStart_RL.slx            # Simulink model with RL controller integrated
├── Potentiometer_Calibration.slx        # Potentiometer calibration model
├── Linear_System_Model_LQR_Matrixes.m  # Factory LQR parameter script
├── cart_pole_modelsimulink.m            # Physical simulation model for PPO training
├── continueppo.m                        # PPO training main script
├── actor_net_cont.mat                   # Final trained actor network
├── actor_net_best.mat                   # Best network from training run
└── calibrateVal.mat                     # Potentiometer calibration data
```

---

## Confirmed System Parameters

### Physical Parameters (read from factory Simulink workspace)

| Parameter | Value | Description |
|-----------|-------|-------------|
| Mc | 0.4719 kg | Cart mass |
| Mp | 0.1679 kg | Pendulum mass |
| Lp | 0.2125 m | Pendulum CoM distance (0.425/2) |
| Jp | 0.01 kg·m² | Moment of inertia |
| Bp | 0.024 Nms/rad | Rotational damping |
| Beq | 30 N·s/m | Equivalent damping (incl. back-EMF) |
| Kt | 0.08505 N·m/A | Motor torque constant |
| Kb | 0.11693 V·s/rad | Back-EMF constant |
| Rm | 2.12 Ω | Motor resistance |
| rmp | 0.013745 m | Belt pulley radius |

### Sensor Conversion

**Serial Data Packet (10 bytes)**

```
Frame header : 0x55  0xBF
Byte[2:3]    : RodAnalog (int16, little-endian) → pendulum potentiometer raw value
Byte[4:5]    : cartEnc   (int16, little-endian) → cart encoder raw value
Byte[6:9]    : CRC32 checksum
```

**Cart Position**

```
x (m) = cartEnc × (−0.001)

Encoder range   : approximately −327 to +330 counts
Physical center : approximately 9 counts (measured; may vary at each power-on)
LQR balance     : drifts between 20–70 counts
Direction       : cart moves right → cartpos increases → x decreases
                  (positive x direction = leftward)
```

**Pendulum Angle**

```
theta (deg) = (RodAnalog − 2074) / 4085 × 360
theta (rad) = theta (deg) × π/180

Vertically upright   = 0°  = 0 rad
Natural hanging down ≈ 178°
RodAnalog at upright ≈ 2074 (after calibration)
```

### PWM-to-Force Conversion (empirically calibrated)

```
1 N → 62.6 PWM
PWM = F × 62.6

Validation: LQR balance u ≈ 5 N → PWM ≈ 313; measured PWM ≈ 300  ✅
```

### LQR Parameters (Factory)

```
K     = [−38.73,  164.21,  −76.34,  41.06]
State  = [x (m),  theta (rad),  x_dot (m/s),  theta_dot (rad/s)]
Q     = diag([3000, 5000, 1, 1])
R     = 2
```

---

## Simulink Signal Flow

```
Serial Receive (10 bytes)
    ↓
Touchscreen (unpack)
    ├── RodAnalog → Convert (Analog to Angle) → RodAngle (deg)
    └── cartEnc   → [Pos] (counts)
    ↓
Pendulum Control
    ├── cartpos × (−0.001)              → x (m)         → LQR & RL
    ├── RodAngle → Saturation           → [Angle] (deg)  → LQR & RL
    ├── [Pos] → Transfer Fcn → ×0.001  → x_dot (m/s)   → LQR & RL
    │   Transfer Fcn: 1 Hz cutoff, damping ratio 0.9
    └── [Angle] → 2nd Order → ×(π/180) → θ_dot (rad/s) → LQR & RL
        2nd Order: 0.5 Hz cutoff, damping ratio 0.9
    ↓
LQR Controller
    u = −K × [x; θ; ẋ; θ̇]
    u (N) → F/Volt → ×100 → PWM Gain → PWM (±1800)
    ↓
Switch (manual toggle)
    Switch = 1 → LQR output → torque
    Switch = 0 → RL  output → torque
    ↓
Servo Motor (serial transmit, 9 bytes)
```

### Filter Parameters

| Filter | Cutoff Frequency | Numerator | Denominator |
|--------|-----------------|-----------|-------------|
| Transfer Fcn (position derivative) | 1 Hz | `[(2π)² 0]` | `[1, 11.31, 39.48]` |
| 2nd Order (angle derivative) | 0.5 Hz | `[(π)² 0]` | `[1, 5.655, 9.87]` |

---

## PPO Training

### Physical Model (cart_pole_modelsimulink.m)

```matlab
% PWM to force (positive sign, empirically calibrated)
F = pwm / 62.6;

% Back-EMF drag + pure mechanical friction
back_emf = Kb * Kt * xDot / (Rm * rmp^2);
b_mech   = 30 - Kb * Kt / (Rm * rmp^2);   % ≈ 5 N·s/m

% Equations of motion (+ gravity term: θ=0 is unstable equilibrium, i.e. upright)
F_vector = [F - back_emf - b_mech*xDot + ml*thetaDot^2*sin_th;
            −d*thetaDot + Mp*g*l*sin_th];
```

### Network Architecture

```
Input Layer  : 4-dimensional [x, ẋ/5, θ, θ̇/10]
Hidden Layer 1: 64 nodes, ReLU
Hidden Layer 2: 64 nodes, ReLU
Output Layer : 2-dimensional [mu, log_std]
```

### Training Hyperparameters

| Parameter | Value |
|-----------|-------|
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

### State Definition and Normalization

```matlab
state = [x; xDot/5.0; theta; thetaDot/10.0]
% x        unit: m,     normalization factor: 1 (none)
% xDot     unit: m/s,   normalization factor: 5
% theta    unit: rad,   normalization factor: 1 (none)
% thetaDot unit: rad/s, normalization factor: 10
```

### Reward Function

```matlab
if abs(thetaNext) > 0.2 || abs(xNext) > 0.2
    r = -20;   % termination penalty
else
    r_survive = 10.0;
    r_theta   = -5.0  * (thetaNext / 0.2)^2;       % angle penalty
    r_x       = -2.0  * (xNext    / 0.2)^2;        % position penalty
    r_force   = -0.5  * (|action| / MAX_ACTION)^2; % effort penalty
    r_smooth  = -1.0  * (action_diff / 2.0)^2;     % smoothness penalty
    r = r_survive + r_theta + r_x + r_force + r_smooth;
end
```

### Training Results (Simulation)

- Convergence: ~300 episodes
- Simulation angle: within ±0.01 rad
- PWM output: starts at ~±500, smooth convergence, no bang-bang

---

## RL Controller Deployment Code

```matlab
function pwm = fcn(cartpos_counts, rodAngle, cartVel_ms, rodVel_rads)
%#codegen
persistent actorNet isLoaded
if isempty(isLoaded)
    actorNet = coder.loadDeepLearningNetwork('actor_net_best.mat', 'actorNet');
    isLoaded = true;
end

X_OFFSET     = 9.0;   % Cart center encoder value (measured; may vary at each power-on)
THETA_OFFSET = 0.0;   % Pendulum angle offset (deg); adjust if systematic bias present

% State conversion (must match training exactly)
x     = (cartpos_counts - X_OFFSET) * (-0.001); % counts → m
v     = cartVel_ms / 5.0;                        % m/s → normalized
theta = (rodAngle - THETA_OFFSET) * (pi / 180); % deg → rad
omega = rodVel_rads / 10.0;                      % rad/s → normalized

state     = [x; v; theta; omega];
MAX_ACTION = 800.0;

dlState   = dlarray(single(state), 'CB');
out_actor = extractdata(predict(actorNet, dlState));
mu        = tanh(double(out_actor(1)));

% Dynamic scaling based on position offset (prevents impact at switch-over)
scale = 1.0 - 0.5 * (abs(x) / 0.25);
scale = max(scale, 0.3);

pwm = -mu * MAX_ACTION * scale;
```

---

## Real-Machine Operation Procedure

### Potentiometer Calibration (required at every power-on)

```bash
# 1. Open Potentiometer_Calibration.slx
# 2. Compile, deploy, and connect to Raspberry Pi
# 3. Manually rotate pendulum one full revolution (360°)
# 4. Position pendulum at natural hanging-down position; click Save in the UI
# 5. Run in MATLAB Command Window:
SaveCalibrateData

# 6. Transfer calibration file to Raspberry Pi from Mac terminal:
scp /Users/chenyihong/rl/pendulum/Code/calibrateVal.mat \
    acrome@192.168.137.73:/home/acrome/MATLAB_ws/R2025a/Users/chenyihong/rl/pendulum/Code/
```

### LQR Startup Procedure

```
1. Open PendulumQuickStart_RL.slx
2. Click "Build, Deploy and Start"
3. Click "Monitor and Tune"
4. Enable        → On
5. Wait until homed = 1
6. Home          → On (cart homes to zero)
7. Move Center   → On (cart moves to center)
8. Mode          → Pendulum Control
9. Enable Control → On
10. Manually push pendulum to upright; LQR takes over automatically
```

### LQR / RL Switching

```
Switch = 1  →  LQR control (default)
Switch = 0  →  RL  control

Switching guidelines:
  - Switch to RL only after LQR has stabilized and cartpos is between 20–50 counts
  - If RL becomes unstable, immediately switch back to Switch = 1
```

---

## Current Progress and Issues

### Completed

- LQR running stably on real hardware (pendulum can balance for extended periods)
- Serial communication protocol fully reverse-engineered (10-byte packet format confirmed)
- All sensor conversion formulas extracted and verified from Simulink source
- PPO training converged in simulation (~300 episodes)
- RL_Controller integrated into Simulink with output direction matching LQR
- RL_Controller can run on real hardware when manually constrained to prevent rail collision

### Outstanding Issues

- **Sim2Real Gap**: physical model dynamics differ from real hardware — RL causes oscillation and cart rail collision after switching
- LQR simulation validation failed: no sign combination in physical model produces stable LQR simulation

---

## Next Steps: Behavior Cloning + PPO Fine-Tuning

**Core idea**: bypass the physical model entirely and train the network directly from real-hardware LQR data.

### Steps

**Step 1 — Real-Machine Data Collection**

Run LQR on real hardware for 60 seconds; record the following signals in Simulink Data Inspector:

| Signal | Description |
|--------|-------------|
| Gain:1 | x (m) |
| Convert:1 | RodAngle (deg) |
| Gain3:1 | x_dot (m/s) |
| Gain6:1 | theta_dot (rad/s) |
| PWM Gain:1 | LQR output PWM |

**Step 2 — Behavior Cloning Training**

```matlab
% Supervised learning: train network to imitate LQR
% Input:  [x, xDot/5, theta, thetaDot/10]
% Output: PWM
% Loss:   MSE(network output, LQR_PWM)
```

**Step 3 — PPO Fine-Tuning**

Continue with PPO on top of the behavior cloning initialization to improve position centering.

**Advantages**:
- Completely avoids Sim2Real gap
- Network initializes close to LQR behavior (no full-scale random output)
- Training data comes from real hardware so directions and magnitudes are correct

---

## Common Commands

```bash
# SSH into Raspberry Pi
ssh acrome@192.168.137.73
# Password: raspberry

# Check if program is running
ps aux | grep Pendulum

# Stop program
sudo killall PendulumQuickStart.elf

# Transfer file to Raspberry Pi
scp <local_path> acrome@192.168.137.73:<remote_path>

# List serial devices
ls -la /dev/serial*
```

---

## Environment Dependencies

| Platform | Dependencies |
|----------|-------------|
| Mac (development) | MATLAB R2025a, Simulink, Deep Learning Toolbox, MATLAB Support Package for Raspberry Pi |
| Raspberry Pi | Python 3.11, pyserial, GCC 12.2, make |
