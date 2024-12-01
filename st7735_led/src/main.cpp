#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <gif.h>
#include <Image.h>
#include <wifi.h>
#include <screen.h>
#include <SPI.h>

const uint8_t numberLeftPix = 42;
const uint8_t leftPix = 5;
const uint8_t topPix = 5;
const uint8_t titleNumberMargin = 5;
const uint8_t blockMargin = 10;

void setup() {
    Serial.begin(115200);
    initTft();    
    // 连接到 WiFi
    // connectToWiFi();

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
    tft.print("178888");

    // 44 +8 + 5 = 57
    tft.setCursor(numberLeftPix, topPix + 8 + titleNumberMargin + 16 + blockMargin + 8 + titleNumberMargin);
    tft.setTextSize(2);
    tft.print("98765");

    // 绘制横线
    int x1 = numberLeftPix, y1 = 90, x2 = 128-5, y2 = 90;
    tft.drawLine(x1, y1, x2, y2, ST7735_WHITE); // 绘制白色横线

    tft.setCursor(numberLeftPix, 100);
    tft.setTextSize(1);
    tft.print("998765");
    
}



// 上次执行 Wi-Fi 请求的时间
unsigned long lastRequestTime = 0;
unsigned long requestInterval = 6000*5;  // 每 1 分钟请求一次 API

bool isFirst = true;

void loop() {
      for (int frame = 0; frame < FRAME_COUNT ; frame++) {
        tft.drawRGBBitmap(128-50, 128-50, frames[frame], 50, 50); // 假设图像大小为 128x128
        delay(100); // 控制帧率
    }
    // 延迟1s
    delay(1000);
}

void loop2() {
    if (isFirst){
        tft.setCursor(1,30);
        tft.setTextSize(2);
        // 请求 API 并显示数据
        fetchDataAndDisplay();
        isFirst = false;
    }
    unsigned long currentMillis = millis();

    // 每 5 秒进行一次 Wi-Fi 请求
  if (currentMillis - lastRequestTime >= requestInterval) {
    // 记录当前时间
    lastRequestTime = currentMillis;

    tft.setCursor(1,30);
    tft.setTextSize(2);
    tft.fillScreen(0x2965);

    // 请求 API 并显示数据
    fetchDataAndDisplay();
  }

    for (int frame = 0; frame < FRAME_COUNT ; frame++) {
        tft.drawRGBBitmap(128-50, 128-50, frames[frame], 50, 50); // 假设图像大小为 128x128
        delay(100); // 控制帧率
    }
    // 延迟1s
    delay(1000);
}





