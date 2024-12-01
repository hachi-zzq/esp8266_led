#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <gif.h>
#include <Image.h>
#include <wifi.h>
#include <screen.h>
#include <SPI.h>


void setup() {
    Serial.begin(115200);
    initTft();    
    // 连接到 WiFi
    // connectToWiFi();

    tft.drawRGBBitmap(5, 5, epd_bitmap_seestar_logo_2_ezgif, 40, 40); // 假设图像大小为 128x128
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





