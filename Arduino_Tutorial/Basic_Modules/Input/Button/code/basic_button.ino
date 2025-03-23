const int BUTTON_PIN = 2;    // 按鈕接在 2 腳位
const int LED_PIN = 13;      // LED 接在 13 腳位
int buttonState = 0;         // 儲存按鈕狀態

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);   // 設定按鈕腳位為輸入, 啟用內部上拉電阻
  pinMode(LED_PIN, OUTPUT);     // 設定LED腳位為輸出
}

void loop() {
  // 讀取按鈕狀態
  buttonState = digitalRead(BUTTON_PIN);

  // 按鈕被按下時LED亮起
  if (buttonState == LOW) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}