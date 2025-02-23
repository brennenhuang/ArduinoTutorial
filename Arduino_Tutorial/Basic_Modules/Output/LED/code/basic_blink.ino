const int LED_PIN = 13;  // LED 接在 13 腳位

void setup() {
  pinMode(LED_PIN, OUTPUT);  // 設定 LED_PIN 為輸出模式
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED 開啟
  delay(1000);                  // 延遲 1 秒
  digitalWrite(LED_PIN, LOW);   // LED 關閉
  delay(1000);                  // 延遲 1 秒
}