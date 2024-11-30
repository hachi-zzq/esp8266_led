//
// https://ezgif.com/split
//

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Gif.h>
#include <Image.h>
#include <SPI.h>

#define TFT_CS   5   // 芯片选择 (D1)
#define TFT_RST  4   // 重置 (D2)
#define TFT_DC   0   // 数据/命令 (D3)

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    tft.initR(INITR_GREENTAB); // 初始化屏幕
    tft.setRotation(1);       // 设置屏幕方向
    tft.fillScreen(0xffdf);
    // tft.drawRGBBitmap(0, 0, image, 50, 50); // 假设图像大小为 128x128
    // 绘制图像
     tft.setCursor(1,1);
    tft.setTextColor(0xb236);
    tft.setTextSize(1.8);
     tft.print("S30");
     tft.setCursor(1,30);
     tft.setTextSize(2);
     tft.print("19872 ");



}

void loop() {
     for (int frame = 0; frame < FRAME_COUNT ; frame++) {
         tft.drawRGBBitmap(128-50, 128-50, frames[frame], 50, 50); // 假设图像大小为 128x128
         delay(100); // 控制帧率
     }

}