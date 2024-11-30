## 环境准备

## 使用 Arduino IDE
- 启用 ESP8266 支持：
- 打开 Arduino IDE，进入 Arduino > Preferences。
- 在 Additional Boards Manager URLs 中添加：
https://arduino.esp8266.com/stable/package_esp8266com_index.json
打开 Tools > Board > Boards Manager，搜索 esp8266 并安装。

## 连接 ESP8266

```bash
ls /dev/tty.*
```
## 下载 CH340 驱动

- 使用 Homebrew 安装 CH340 驱动：
- brew tap homebrew/cask-drivers
  brew install --cask wch-ch34x-usb-serial-driver

# 使用 VS Code Platformio 开发

- 安装 VsCode 插件

1. PlatformIO IDE
2. C/C++ 
3. Arduino 
4. Chinese (Simplified) Language Pack

- PlatformIO配置
- 点击左侧PlatformIO图标
- 新建项目
- 选择开发板：NodeMCU 1.0 (ESP-12E)
- 框架：Arduino 
- 位置：自定义项目目录

```bash
[env:nodemcuv2]
platform = espressif8266
board = nodemcuv2
framework = arduino
lib_extra_dirs = ~/Documents/Arduino/libraries
monitor_speed = 115200
upload_port = /dev/tty.wchusbserial1110
lib_deps = 
	bodmer/TFT_eSPI@^2.5.43
	bitbank2/AnimatedGIF@^2.1.1
	adafruit/Adafruit GFX Library@^1.11.11
	adafruit/Adafruit ST7735 and ST7789 Library@^1.10.4
	olikraus/U8g2@^2.36.2

```
- 项目结构
```
project/
├── src/
│   └── main.cpp     # 主程序
├── lib/             # 自定义库
├── include/         # 头文件
├── test/            # 测试代码
└── platformio.ini   # 配置文件
```
## 测试开发

```c
#include <Arduino.h>
void setup() {
  Serial.begin(115200);
  
  // 检查串口是否正常
  Serial.println("Board connection test");
}
```