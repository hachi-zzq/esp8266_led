#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

const uint16_t defaultTextColor = 0x9F9E;
const uint16_t numberColor = 0x6dcb;
const uint16_t defaultScreenColor =  0x2965;
const uint8_t defaultTextSize = 1;

const uint8_t numberLeftPix = 42;
const uint8_t leftPix = 5;
const uint8_t topPix = 5;
const uint8_t titleNumberMargin = 6;
const uint8_t blockMargin = 12;

#define TFT_CS   5   // 芯片选择 (D1)
#define TFT_RST  4   // 重置 (D2)
#define TFT_DC   0   // 数据/命令 (D3)

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void initTft(){
    tft.initR(INITR_GREENTAB); // 初始化屏幕
    tft.setRotation(1);       // 设置屏幕方向
    tft.fillScreen(defaultScreenColor);
    tft.setTextSize(defaultTextSize);
}

void drawS50(int total , int month){

    tft.drawRGBBitmap(3, 10, s50_icon, 45, 49); 

    tft.setTextColor(numberColor);
    // 5+8+5
    tft.setCursor(60, 20);
    tft.setTextSize(1);
    tft.print("Month");


    tft.setTextColor(defaultTextColor);
    // 5+8+5
    tft.setCursor(60, 38);
    tft.setTextSize(2);
    tft.print(month);

    tft.setTextColor(defaultTextColor);
    // 5+8+5
    tft.setCursor(12, 82);
    tft.setTextSize(3);
    tft.print(total);
}

void drawImageAndNumber(int s30Number , int s50Number, int imageNumber){
    tft.drawRGBBitmap(leftPix, leftPix, epd_bitmap_seestar_logo_2_ezgif, 30, 30); 
    tft.drawRGBBitmap(topPix, 90, epd_bitmap_logo_fddb51a7_ezgif, 30, 30); 

  // 1 size = 8 ,2 size = 16

    tft.setTextColor(numberColor);
    tft.setTextSize(1);
    tft.setCursor(numberLeftPix, topPix);
    tft.print("S30");

    // 18 + 16 + 10 = 44
    tft.setCursor(numberLeftPix, topPix + 8 + titleNumberMargin + 16 + blockMargin);
    tft.print("S50");

    tft.setTextColor(defaultTextColor);
    // 5+8+5
    tft.setCursor(numberLeftPix, topPix + 8 + titleNumberMargin);
    tft.setTextSize(2);
    tft.print(s30Number);

    // 44 +8 + 5 = 57
    tft.setCursor(numberLeftPix, topPix + 8 + titleNumberMargin + 16 + blockMargin + 8 + titleNumberMargin);
    tft.setTextSize(2);
    tft.print(s50Number);

    // 绘制横线
    int x1 = numberLeftPix, y1 = 85, x2 = 128-5, y2 = 85;
    tft.drawLine(x1, y1, x2, y2, ST7735_WHITE); // 绘制白色横线

    // 90 + 1 + 
    // tft.setCursor(numberLeftPix, 90 + 5);
    // tft.setTextColor(numberColor);
    // tft.setTextSize(1);
    // tft.print("Image");

    tft.setCursor(numberLeftPix, 100);
    tft.setTextSize(2);
    tft.setTextColor(defaultTextColor);
    tft.print(imageNumber);
}

void fullScreenPrint(const char c[], uint8_t textSize){
    tft.fillScreen(defaultScreenColor);
    tft.setTextColor(defaultTextColor);
    tft.setTextSize(textSize);
    tft.print(c);
}

void fullScreenPrint(const int number, uint8_t textSize){
    tft.fillScreen(defaultScreenColor);
    tft.setTextColor(defaultTextColor);
    tft.setTextSize(textSize);
    tft.print(number);
}


void fullScreenPrint(const char c[], uint16_t screenColor ,uint16_t defaultTextColor, uint8_t textSize){
    tft.fillScreen(screenColor);
    tft.setTextColor(defaultTextColor);
    tft.setTextSize(textSize);
    tft.print(c);
}

void fullScreenPrint(const int number, uint16_t screenColor ,uint16_t defaultTextColor, uint8_t textSize){
    tft.fillScreen(screenColor);
    tft.setTextColor(defaultTextColor);
    tft.setTextSize(textSize);
    tft.print(number);
}


#endif // FILE_H