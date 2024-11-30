#include <ESP8266WiFi.h>

const char* ssid = "你的WiFi名称";
const char* password = "你的WiFi密码";

void setup() {
    Serial.begin(115200);
    delay(10);

    Serial.println("正在连接到 WiFi...");
    WiFi.begin(ssid, password);

    int retries = 0; // 重试计数器
    while (WiFi.status() != WL_CONNECTED) {
        retries++;
        delay(500);
        Serial.print(".");
        if (retries > 20) { // 超过 10 秒（500ms * 20）
            Serial.println("\n连接超时，请检查网络设置！");
            break;
        }
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi 连接成功！");
        Serial.print("IP 地址: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\nWiFi 连接失败！");
    }
}

void loop() {
    // 保持运行
}
