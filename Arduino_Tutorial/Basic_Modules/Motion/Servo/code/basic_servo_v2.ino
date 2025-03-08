#include <Servo.h>

Servo myservo;  // 建立伺服馬達物件
const int SERVO_PIN = 9;  // 伺服馬達接在 9 腳位

void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);  // 連接伺服馬達

  // 移動到中間位置
  myservo.write(90);
  delay(1000);
}

void loop() {
  // 讀取序列埠輸入控制角度
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();  // 讀取角度值

    // 確保角度在有效範圍內
    if (angle >= 0 && angle <= 180) {
      Serial.print("移動到角度: ");
      Serial.println(angle);

      // 平滑移動到指定角度
      smoothMove(angle);
    }
  }
}

// 平滑移動函數
void smoothMove(int targetAngle) {
  int currentAngle = myservo.read();  // 讀取目前角度

  // 根據目標角度決定移動方向
  if (currentAngle < targetAngle) {
    // 順時針移動
    for (int i = currentAngle; i <= targetAngle; i++) {
      myservo.write(i);
      delay(15);  // 調整這個值可以改變移動速度
    }
  } else {
    // 逆時針移動
    for (int i = currentAngle; i >= targetAngle; i--) {
      myservo.write(i);
      delay(15);
    }
  }
}