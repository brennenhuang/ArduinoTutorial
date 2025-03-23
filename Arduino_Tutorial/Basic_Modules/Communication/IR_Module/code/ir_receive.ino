#include <IRremote.h>

const int IR_RECEIVE_PIN = 7;  // 紅外線接收器接在 7 腳位

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);  // 初始化 IR 接收器
  Serial.println("IR 接收器就緒");
}

void loop() {
  if (IrReceiver.decode()) {
    // 收到 IR 信號
    Serial.print("接收到代碼: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    // 準備接收下一個信號
    IrReceiver.resume();
  }
  delay(100);
}