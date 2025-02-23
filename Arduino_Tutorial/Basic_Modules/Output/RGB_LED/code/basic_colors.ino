// 定義 RGB LED 腳位（使用 PWM）
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

// 是否為共陽極 RGB LED
const boolean COMMON_ANODE = false;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // 顯示紅色
  setColor(255, 0, 0);
  delay(1000);

  // 顯示綠色
  setColor(0, 255, 0);
  delay(1000);

  // 顯示藍色
  setColor(0, 0, 255);
  delay(1000);

  // 顯示黃色（紅+綠）
  setColor(255, 255, 0);
  delay(1000);

  // 顯示青色（綠+藍）
  setColor(0, 255, 255);
  delay(1000);

  // 顯示紫色（紅+藍）
  setColor(255, 0, 255);
  delay(1000);

  // 顯示白色（全亮）
  setColor(255, 255, 255);
  delay(1000);
}

// 設定 RGB LED 顏色
void setColor(int red, int green, int blue) {
  // 如果是共陽極 LED，需要反轉數值
  if (COMMON_ANODE) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  }

  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}