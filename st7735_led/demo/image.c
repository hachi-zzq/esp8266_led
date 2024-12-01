#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Gif.h>
#include <Image.h>

#define TFT_CS   5   // 芯片选择 (D1)
#define TFT_RST  4   // 重置 (D2)
#define TFT_DC   0   // 数据/命令 (D3)

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);




void setup() {
    tft.initR(INITR_BLACKTAB); // 初始化屏幕
    tft.setRotation(1);       // 设置屏幕方向
    tft.fillScreen(ST77XX_WHITE);

    // 绘制图像
    tft.drawRGBBitmap(0, 0, image, 50, 50); // 假设图像大小为 128x128
}

void loop() {

}





