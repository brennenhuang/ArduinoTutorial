#include <IRremote.h>

const int IR_RECEIVE_PIN = 7;  // 紅外線接收器接在 7 腳位
const int LED_PIN = 13;
boolean ledState = false;      // 記錄 LED 狀態
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);  // 初始化 IR 接收器
  pinMode(LED_PIN, OUTPUT);
  Serial.println("IR 接收器就緒");

}

void loop() {
  if (IrReceiver.decode()) {
    // 收到 IR 信號
    Serial.print("接收到代碼: 0x");
    // Serial.println(IrReceiver.decodedIRData.command, HEX);
    Serial.println(IrReceiver.decodedIRData.command);
    switch (IrReceiver.decodedIRData.command){
      case 82: //遙控器8號鍵
        // 切換 LED 狀態
        ledState = !ledState;           // 切換狀態
        digitalWrite(LED_PIN, ledState); // 設定 LED
        Serial.println(ledState ? "LED 開啟" : "LED 關閉");
        break;
    }
    // 準備接收下一個信號
    IrReceiver.resume();
  }
  delay(100);
}