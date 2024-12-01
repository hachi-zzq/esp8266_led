#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>
#include <screen.h>
#include <ArduinoJson.h>  // 用于解析 JSON 数据
#include <ESP8266HTTPClient.h>

const char* ssid = "yu_dianxin";
const char* password = "zhangbaoyu";
const int wifiConnAttempts = 20;

void connectToWiFi() {
  WiFi.begin(ssid, password);
  int attempts = 0;
  
if (WiFi.status() != WL_CONNECTED) {
    tft.setCursor(1,1);
    fullScreenPrint("Connecting to WiFi...", 1);
  } 

  while (WiFi.status() != WL_CONNECTED && attempts < wifiConnAttempts) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    // 连接成功
    Serial.println("WiFi connected");
    tft.setCursor(1,1);
    fullScreenPrint("Connecting to WiFi...",  1);
  } else {
    // 连接失败
    Serial.println("Wi-Fi connection failed.");
    tft.setCursor(1,1);
    fullScreenPrint("Connecting to WiFi...",  1);
  }
}


void fetchDataAndDisplay() {
// 检查 Wi-Fi 是否连接
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi lost, trying to reconnect...");
    tft.setCursor(10, 10);
    fullScreenPrint("Wi-Fi lost. Reconnecting...", 1);
    // 尝试重新连接 Wi-Fi
    connectToWiFi();
  }


  HTTPClient http;
  WiFiClient client;
  String url = "http://desktop-led.moneyzhu.com/";

  // 向 API 发送 GET 请求
  http.begin(client,url);
  int httpCode = http.GET();
  
  if (httpCode == HTTP_CODE_OK) {
    String payload = http.getString();
    Serial.println(payload);

    // 解析 JSON 数据
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, payload);
    
    if (error) {
      Serial.println("Failed to parse JSON");
      return;
    }

    // 获取 "number" 字段的值
    int number = doc["number"];
    
    // 显示数字到屏幕上
    tft.setCursor(10, 10);
    fullScreenPrint(number, 1);
  } else {
    Serial.println("Error on HTTP request");
  }

  // 结束 HTTP 请求
  http.end();
}

#endif // FILE_H