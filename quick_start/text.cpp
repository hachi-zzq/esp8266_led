/**
*

3. 连接 ESP8266 和 TFT
TFT 屏幕通常有以下引脚（具体型号可能略有差异）：

TFT 引脚	功能	ESP8266 引脚
VCC	电源	3.3V 或 5V
GND	地	GND
CS	芯片选择	D1 (GPIO5)
RST	重置	D2 (GPIO4)
DC	数据/命令	D3 (GPIO0)
SDA	数据 (MOSI)	D7 (GPIO13)
SCK	时钟	D5 (GPIO14)
LED	背光	3.3V 或 PWM
确保将 ESP8266 的 3.3V 连接到 TFT 的 VCC，以防止电压不匹配问题。

--- 库
Adafruit GFX Library
Adafruit ST7735 and ST7789 Library

*/

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// 定义 TFT 引脚
#define TFT_CS   5   // 芯片选择 (D1)
#define TFT_RST  4   // 重置 (D2)
#define TFT_DC   0   // 数据/命令 (D3)

// 初始化 TFT 对象
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    // 初始化串口用于调试
    Serial.begin(115200);
    Serial.println("TFT 初始化中...");

    // 初始化 TFT 屏幕
    tft.initR(INITR_BLACKTAB); // 针对 ST7735 的初始化设置。 INITR_GREENTAB
    tft.fillScreen(ST77XX_BLACK); // 填充黑色背景 RGB565
    tft.setRotation(1); // 设置屏幕方向（0-3 可选）

    // 显示文本
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println("Hello, ESP8266!");

    // 绘制图形
    tft.drawRect(10, 30, 100, 50, ST77XX_RED);  // 绘制矩形
    tft.fillCircle(60, 100, 20, ST77XX_BLUE);  // 绘制填充圆形
}

void loop() {
    // 可在此添加其他动态内容
    // 每1秒更新一次
    delay(1000);
    tft.fillScreen(ST77XX_BLACK); // 填充背景为黑色
    tft.setCursor(10, 10);
    tft.println("Hello, ESP8266!");
}
