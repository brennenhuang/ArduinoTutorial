#include "DHT.h"

#define DHTPIN 2        // DHT 感測器接在 2 腳位
#define DHTTYPE DHT11   // DHT11 感測器

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   // 初始化序列埠通訊
  dht.begin();          // 初始化 DHT 感測器
}

void loop() {
  // 等待 2 秒鐘再讀取
  delay(2000);

  // 讀取溫濕度數據
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // 檢查是否讀取失敗
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("無法從 DHT 感測器讀取數據！");
    return;
  }

  // 顯示溫濕度數據
  Serial.print("Humidity: " + String(humidity) + "% ");
  Serial.println("Temperature: " + String(temperature) + "°C");
}