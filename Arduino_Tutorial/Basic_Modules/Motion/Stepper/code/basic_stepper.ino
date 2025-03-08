#include <Stepper.h>

// 定義步進馬達的步數（28BYJ-48 為 2048 步/圈）
const int STEPS_PER_REV = 2048;

// 定義控制腳位
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

// 初始化步進馬達
Stepper stepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

void setup() {
  Serial.begin(9600);
  // 設定初始速度（RPM）
  stepper.setSpeed(15);

  Serial.println("步進馬達控制就緒");
  Serial.println("輸入指令：");
  Serial.println("1: 順時針轉一圈");
  Serial.println("2: 逆時針轉一圈");
  Serial.println("3: 順時針轉半圈");
  Serial.println("4: 逆時針轉半圈");
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    switch (cmd) {
      case '1':
        Serial.println("順時針轉一圈");
        stepper.step(STEPS_PER_REV);
        break;

      case '2':
        Serial.println("逆時針轉一圈");
        stepper.step(-STEPS_PER_REV);
        break;

      case '3':
        Serial.println("順時針轉半圈");
        stepper.step(STEPS_PER_REV / 2);
        break;

      case '4':
        Serial.println("逆時針轉半圈");
        stepper.step(-STEPS_PER_REV / 2);
        break;
    }
  }
}