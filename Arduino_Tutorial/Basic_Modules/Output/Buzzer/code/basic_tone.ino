const int BUZZER_PIN = 9;  // 蜂鳴器接在 9 腳位（PWM）

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  tone(BUZZER_PIN, 262);  // 播放 Do (C4 - 262Hz)
  delay(1000);            // 持續 1 秒

  noTone(BUZZER_PIN);     // 停止發聲
  delay(1000);            // 暫停 1 秒
}