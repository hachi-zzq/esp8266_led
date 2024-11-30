#include <Arduino.h>
// 定义板载 LED 引脚（通常是 GPIO2 或 GPIO16）
#define LED_PIN 2

void setup() {
    Serial.begin(115200);  // 初始化串口通讯
    pinMode(LED_PIN, OUTPUT);
    Serial.println("ESP8266 初始化完成！");
}

void loop() {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED 点亮");
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED 熄灭");
    delay(1000);
}
