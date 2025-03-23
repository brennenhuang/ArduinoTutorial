#include <IRremote.h>

const int IR_SEND_PIN = 3;  // IR LED 接在 3 腳位（PWM）

// 定義常用的 IR 代碼
#define IR_POWER  0x20DF10EF  // 電源鍵代碼
#define IR_VOL_UP 0x20DF40BF  // 音量增加代碼
#define IR_VOL_DN 0x20DFC03F  // 音量減少代碼

void setup() {
  IrSender.begin(IR_SEND_PIN);  // 初始化 IR 發射器
  Serial.begin(9600);
  Serial.println("IR 發射器就緒");
}

void loop() {
  // 發送電源開關信號
  Serial.println("發送電源信號");
  IrSender.sendNEC(IR_POWER, 32);
  delay(2000);

  // 發送音量增加信號
  Serial.println("發送音量增加信號");
  IrSender.sendNEC(IR_VOL_UP, 32);
  delay(2000);

  // 發送音量減少信號
  Serial.println("發送音量減少信號");
  IrSender.sendNEC(IR_VOL_DN, 32);
  delay(2000);
}