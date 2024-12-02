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

    // drawImageAndNumber(178998,18987,989841);


}

// 上次执行 Wi-Fi 请求的时间
unsigned long lastRequestTime = 0;
unsigned long requestInterval = 6000*5;  // 每 1 分钟请求一次 API

void loop() {

  tft.fillScreen(defaultScreenColor);

    drawImageAndNumber(178998,18987,98984);


  delay(30000);

  tft.fillScreen(defaultScreenColor);
  drawS50(78987,789);

  delay(30000);


  for (int frame = 0; frame < FRAME_COUNT ; frame++) {
      tft.drawRGBBitmap(0, 0, frames[frame], 128, 128); // 假设图像大小为 128x128
      delay(50); // 控制帧率
  }
}

void loop4() {
  unsigned long currentMillis = millis();
   // 每 1 分钟请求一次 API
  if (currentMillis - lastRequestTime >= requestInterval) {
    // 记录当前时间
    lastRequestTime = currentMillis;
    tft.fillScreen(defaultScreenColor);
    drawImageAndNumber(millis(),millis(), millis());
    Serial.println("drawImageAndNumber");
  }

  for (int frame = 0; frame < FRAME_COUNT ; frame++) {
      tft.drawRGBBitmap(128-50, 128-50, frames[frame], 50, 50); // 假设图像大小为 128x128
      delay(100); // 控制帧率
  }
    // 延迟1s
  delay(1000);
}

void loop2() {
      for (int frame = 0; frame < FRAME_COUNT ; frame++) {
        tft.drawRGBBitmap(128-50, 128-50, frames[frame], 50, 50); // 假设图像大小为 128x128
        delay(100); // 控制帧率
    }
    // 延迟1s
    delay(1000);
}

bool isFirst = true;

void loop3() {
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





