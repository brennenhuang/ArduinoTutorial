const int LIGHT_SENSOR_PIN = A0;  // 光敏感測器接在 A0
const int LED_PIN = 13;           // LED 指示燈
const int THRESHOLD = 500;        // 光線閾值（0-1023）

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("光敏感測器就緒");
}

void loop() {
  // 讀取光線強度
  int lightLevel = analogRead(LIGHT_SENSOR_PIN);

  // 顯示光線強度
  Serial.print("光線強度: ");
  Serial.print(lightLevel);
  Serial.print(" (");
  Serial.print(map(lightLevel, 0, 1023, 0, 100)); // 將光線強度轉換為百分比
  Serial.println("%)");

  // LED 指示
  if (lightLevel < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);  // 光線暗時 LED 亮
  } else {
    digitalWrite(LED_PIN, LOW);   // 光線亮時 LED 滅
  }

  delay(500);  // 每 0.5 秒讀取一次
}