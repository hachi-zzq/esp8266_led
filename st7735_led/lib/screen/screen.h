#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

const uint16_t defaultTextColor = 0x9F9E;
const uint16_t defaultScreenColor =  0x2965;
const uint8_t defaultTextSize = 1;

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