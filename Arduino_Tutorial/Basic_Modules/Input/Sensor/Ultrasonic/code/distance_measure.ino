const int TRIG_PIN = 12;  // 觸發腳位
const int ECHO_PIN = 11;  // 回波腳位
const int LED_PIN = 13;   // LED 指示燈腳位

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("超音波距離感測器就緒");
}

void loop() {
  // 發送觸發信號
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // 接收回波信號並計算距離
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;  // 換算成公分

  // 顯示距離
  Serial.print("距離: ");
  Serial.print(distance);
  Serial.println(" 公分");

  // 距離警示
  if (distance < 10) {  // 距離小於 10 公分
    digitalWrite(LED_PIN, HIGH);  // LED 亮起警示
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);  // 每 0.5 秒測量一次
}