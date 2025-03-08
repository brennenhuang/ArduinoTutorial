#include <Servo.h>

Servo myservo;
const int SERVO_PIN = 9;

// 預設位置陣列（度）
int positions[] = {0, 45, 90, 135, 180};
int numPositions = 5;

void setup() {
  myservo.attach(SERVO_PIN);
  Serial.begin(9600);

  // 初始化位置
  myservo.write(90);
  delay(1000);
}

void loop() {
  // 模式 1：連續掃描
  sweepContinuous();
  delay(1000);

  // 模式 2：定點掃描
  sweepPositions();
  delay(1000);

  // 模式 3：擺動效果
  swingEffect();
  delay(1000);
}

// 連續掃描
void sweepContinuous() {
  // 從 0 到 180
  for (int angle = 0; angle <= 180; angle++) {
    myservo.write(angle);
    delay(15);
  }
  // 從 180 到 0
  for (int angle = 180; angle >= 0; angle--) {
    myservo.write(angle);
    delay(15);
  }
}

// 定點掃描
void sweepPositions() {
  for (int i = 0; i < numPositions; i++) {
    myservo.write(positions[i]);
    delay(500);  // 在每個位置停留
  }
}

// 擺動效果
void swingEffect() {
  int centerPos = 90;
  int swingRange = 30;  // 擺動範圍

  for (int i = 0; i < 5; i++) {  // 擺動 5 次
    // 向右擺動
    myservo.write(centerPos + swingRange);
    delay(200);
    // 向左擺動
    myservo.write(centerPos - swingRange);
    delay(200);
  }

  // 回到中心
  myservo.write(centerPos);
}