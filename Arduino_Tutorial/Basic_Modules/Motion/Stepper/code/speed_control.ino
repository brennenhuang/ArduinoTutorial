#include <Stepper.h>

const int STEPS_PER_REV = 2048;
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

Stepper stepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

// 速度控制變數
int currentSpeed = 5;  // 初始速度
int targetSteps = 0;   // 目標步數
int currentPosition = 0;  // 目前位置

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(currentSpeed);

  Serial.println("速度控制模式");
  Serial.println("輸入格式：速度,步數");
  Serial.println("例如：10,1024 表示速度10RPM移動1024步");
}

void loop() {
  if (Serial.available() > 0) {
    // 讀取速度和步數
    int speed = Serial.parseInt();
    if (Serial.read() == ',') {
      int steps = Serial.parseInt();

      if (speed > 0 && steps != 0) {
        Serial.print("速度: ");
        Serial.print(speed);
        Serial.print(" RPM, 步數: ");
        Serial.println(steps);

        // 執行加速運動
        smoothMove(speed, steps);
      }
    }
  }
}

// 平滑加速移動
void smoothMove(int targetSpeed, int steps) {
  // 記錄移動方向
  int direction = steps > 0 ? 1 : -1;
  steps = abs(steps);

  // 加速階段
  for (int speed = currentSpeed; speed <= targetSpeed; speed++) {
    stepper.setSpeed(speed);
    stepper.step(direction * (steps/10));
    delay(50);
  }

  // 維持速度移動
  stepper.setSpeed(targetSpeed);
  stepper.step(direction * (steps * 8/10));

  // 減速階段
  for (int speed = targetSpeed; speed >= currentSpeed; speed--) {
    stepper.setSpeed(speed);
    stepper.step(direction * (steps/10));
    delay(50);
  }

  // 更新位置
  currentPosition += steps * direction;
  Serial.print("目前位置: ");
  Serial.println(currentPosition);
}