//
// image2cpp
//https://javl.github.io/image2cpp/
//

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "image.h"

// 定义 TFT 引脚
#define TFT_CS   5   // 芯片选择 (D1)
#define TFT_RST  4   // 重置 (D2)
#define TFT_DC   0   // 数据/命令 (D3)

// 初始化 TFT 对象
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);



void setup() {
    Serial.begin(115200);
    tft.initR(INITR_BLACKTAB); // 初始化 TFT 屏幕
    tft.setRotation(1);  // 设置屏幕方向（0-3 可选）
    tft.fillScreen(ST77XX_BLACK); // 填充黑色背景

    // 将图片显示到屏幕上
    tft.drawRGBBitmap(0, 0, image, 50, 50); // 假设图像大小为 128x128
}

void loop() {
    // 可在此添加其他功能
}