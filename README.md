# AGV Factory Robot - 工厂物流自动搬运小车

> 一款低成本、可量产、支持二维码/磁条导航的智能工厂物流小车，适用于 5-10kg 载重场景。

![AGV 运行效果图](docs/demo.gif) <!-- 可替换为实际图片 -->

## 功能亮点

- 支持 **二维码引导**（精准定位）
- 备用 **红外寻迹传感器**（防偏离）
- 内置 **Wi-Fi + Bluetooth**（远程控制）
- 可通过手机/电脑发送指令
- 适用于室内平整地面
- 总成本约 800~1200 元

## 硬件清单

| 模块 | 型号 | 数量 | 用途 |
|------|------|------|------|
| 主控板 | ESP32-WROOM-32D | 1 | 核心控制器 |
| 电机驱动 | TB6612FNG | 1 | 驱动两个直流减速电机 |
| 直流电机 | 12V 100RPM | 2 | 提供动力 |
| 摄像头 | OV7670 | 1 | 二维码扫描 |
| 红外传感器 | TCRT5000 | 4 | 辅助寻迹 |
| 电源 | 12V 5Ah 锂电池 | 1 | 供电系统 |
| 底盘 | 亚克力/铝合金 | 1 | 结构支撑 |

**详细采购清单请见**：`hardware/parts_list.csv`

## 项目结构

```
.
├── battery_monitor.ino    # 电量监测与低电报警代码
├── task_scheduler.ino     # AGV 任务调度器 - 状态机模式
├── qr_scanner.py          # 树莓派二维码识别程序
├── wiring_diagram.txt     # 接线图说明
├── AGV_Chassis.stl        # 3D 打印底盘模型
├── docs/                  # 使用手册、开发指南
└── hardware/              # 3D 打印模型、接线图、元器件表
```

## 快速开始

### 1. 硬件组装

- 按照 `wiring_diagram.txt` 连接各模块
- 安装摄像头、电机、传感器
- 使用 `AGV_Chassis.stl` 文件 3D 打印底盘

### 2. ESP32 固件烧录

```bash
# 使用 Arduino IDE 或 PlatformIO
# 打开 battery_monitor.ino 或 task_scheduler.ino
# 选择 ESP32 开发板，上传固件
```

### 3. 树莓派配置

```bash
# 安装依赖
pip install opencv-python pyzbar pyserial

# 运行二维码扫描程序
python3 qr_scanner.py
```

### 4. 功能说明

#### 电量监测 (`battery_monitor.ino`)
- 实时监测电池电压
- 低电压报警（低于 10.5V）
- 通过串口输出电压数据

#### 任务调度 (`task_scheduler.ino`)
- 状态机模式管理任务流程
- 支持多点任务队列
- 蓝牙通信控制

#### 二维码识别 (`qr_scanner.py`)
- 实时扫描地面二维码
- 识别内容通过串口发送给 ESP32
- 支持多种二维码格式

## 接线说明

详见 `wiring_diagram.txt` 文件，主要连接包括：
- ESP32 与 TB6612FNG 电机驱动
- ESP32 与 OV7670 摄像头
- ESP32 与 TCRT5000 红外传感器
- 电源系统连接

## 通信协议

### 蓝牙命令
- `GO:<目标点>` - 移动到指定位置
- `STOP` - 停止运动
- `HOME` - 返回基地

### 串口数据格式
- 波特率：115200
- 数据位：8
- 停止位：1
- 校验位：无

## 许可证

本项目采用 MIT 许可证，详见 `license` 文件。

## 贡献指南

欢迎提交 Issue 和 Pull Request！

## 联系方式

如有问题，请通过 GitHub Issues 联系。
