const int LIGHT_SENSOR_PIN = A0;  // 光敏感測器
const int LED_PIN = 3;            // LED（使用 PWM 腳位）
const int SAMPLES = 10;           // 取樣次數

// 光線閾值
const int DARK_THRESHOLD = 500;   // 暗光閾值
const int BRIGHT_THRESHOLD = 700; // 亮光閾值

// LED 亮度控制
int currentBrightness = 0;
const int FADE_AMOUNT = 5;        // 漸變步進值

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // 讀取平均光線強度
  int avgLight = getAverageLightLevel();

  // 根據光線強度調整 LED 亮度
  if (avgLight < DARK_THRESHOLD) {
    // 光線暗，增加亮度
    fadeToTarget(255);
  }
  else if (avgLight > BRIGHT_THRESHOLD) {
    // 光線亮，降低亮度
    fadeToTarget(0);
  }

  // 顯示數據
  Serial.print("光線強度: ");
  Serial.print(avgLight);
  Serial.print(" LED亮度: ");
  Serial.println(currentBrightness);

  delay(50);
}

// 取得平均光線強度
int getAverageLightLevel() {
  long total = 0;

  for (int i = 0; i < SAMPLES; i++) {
    total += analogRead(LIGHT_SENSOR_PIN);
    delay(10);
  }

  return total / SAMPLES;
}

// LED 亮度平滑過渡
void fadeToTarget(int target) {
  if (currentBrightness < target) {
    currentBrightness = min(currentBrightness + FADE_AMOUNT, target);
  } else if (currentBrightness > target) {
    currentBrightness = max(currentBrightness - FADE_AMOUNT, target);
  }

  analogWrite(LED_PIN, currentBrightness);
}