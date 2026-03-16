#  AGV Factory Robot - 工厂物流自动搬运小车

> 一款低成本、可量产、支持二维码/磁条导航的智能工厂物流小车，适用于5-10kg载重场景。

![AGV运行效果图](docs/demo.gif) <!-- 可替换为实际图片 -->

##  功能亮点

-  支持 **二维码引导**（精准定位）
-  备用 **红外寻迹传感器**（防偏离）
-  内置 **Wi-Fi + Bluetooth**（远程控制）
-  可通过手机/电脑发送指令
-  适用于室内平整地面
-  总成本约 800~1200

##  硬件清单

| 模块 | 型号 | 数量 | 用途 |
|------|------|------|------|
| 主控板 | ESP32-WROOM-32D | 1 | 核心控制器 |
| 电机驱动 | TB6612FNG | 1 | 驱动两个直流减速电机 |
| 直流电机 | 12V 100RPM | 2 | 提供动力 |
| 摄像头 | OV7670 | 1 | 二维码扫描 |
| 红外传感器 | TCRT5000 | 4 | 辅助寻迹 |
| 电源 | 12V 5Ah锂电池 | 1 | 供电系统 |
| 底盘 | 亚克力/铝合金 | 1 | 结构支撑 |

 **详细采购清单请见**：`hardware/parts_list.csv`

##  项目结构

- `firmware/`: ESP32 主控代码
- `raspberry-pi/`: 树莓派二维码识别程序
- `app/`: 手机控制APP（MIT App Inventor）
- `docs/`: 使用手册、接线图、开发指南
- `hardware/`: 3D打印模型、接线图、元器件表

##  快速开始

### 1. 硬件组装
- 按照 `hardware/wiring_diagram.png` 连接各模块
- 安装摄像头、电机、传感器

### 2. 树莓派配置
```bash
cd raspberry-pi
chmod +x install.sh
./install.sh
python3 qr_scanner.py


---

###  3. 生成 `parts_list.csv`（采购清单）

```csv
Name,Model,Quantity,Link
ESP32-WROOM-32D,ESP32-WROOM-32D,1,https://s.click.aliexpress.com/e/_cKJzZa
TB6612FNG Motor Driver,TB6612FNG,1,https://s.click.aliexpress.com/e/_cKJzZa
12V DC Motor,12V 100RPM,2,https://s.click.aliexpress.com/e/_cKJzZa
OV7670 Camera Module,OV7670,1,https://s.click.aliexpress.com/e/_cKJzZa
TCRT5000 Infrared Sensor,TCRT5000,4,https://s.click.aliexpress.com/e/_cKJzZa
12V 5Ah Li-ion Battery,12V 5Ah,1,https://s.click.aliexpress.com/e/_cKJzZa
Aluminum Chassis,200x150mm,1,https://s.click.aliexpress.com/e/_cKJzZa