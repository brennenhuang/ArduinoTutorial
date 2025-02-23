// LED 進階控制示範
// 包含：PWM 呼吸燈、多重 LED 控制、閃爍模式

// 定義 LED 腳位
const int LED_PINS[] = {9, 10, 11};  // PWM 腳位
const int NUM_LEDS = 3;

// 呼吸燈參數
const int FADE_DELAY = 30;    // 漸變延遲（毫秒）
const int FADE_STEP = 5;      // 漸變步進值

// 閃爍模式參數
const int PATTERN_LENGTH = 8;
const int PATTERN_DELAY = 200;  // 模式延遲（毫秒）

// 定義閃爍模式（0=關，1=開）
const byte PATTERNS[][PATTERN_LENGTH] = {
  {1,0,1,0,1,0,1,0},  // 交替閃爍
  {1,1,0,0,1,1,0,0},  // 雙閃
  {1,1,1,0,0,0,0,0}   // SOS
};

void setup() {
  // 初始化所有 LED 腳位
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
}

void loop() {
  // 示範各種 LED 效果
  breathingEffect();       // 呼吸燈效果
  delay(1000);

  chaseEffect();          // 跑馬燈效果
  delay(1000);

  for (int i = 0; i < 3; i++) {
    playPattern(i);       // 播放閃爍模式
    delay(1000);
  }
}

// 呼吸燈效果
void breathingEffect() {
  // 漸亮
  for (int brightness = 0; brightness <= 255; brightness += FADE_STEP) {
    for (int i = 0; i < NUM_LEDS; i++) {
      analogWrite(LED_PINS[i], brightness);
    }
    delay(FADE_DELAY);
  }

  // 漸暗
  for (int brightness = 255; brightness >= 0; brightness -= FADE_STEP) {
    for (int i = 0; i < NUM_LEDS; i++) {
      analogWrite(LED_PINS[i], brightness);
    }
    delay(FADE_DELAY);
  }
}

// 跑馬燈效果
void chaseEffect() {
  for (int i = 0; i < NUM_LEDS * 2; i++) {
    // 關閉所有 LED
    for (int j = 0; j < NUM_LEDS; j++) {
      digitalWrite(LED_PINS[j], LOW);
    }

    // 點亮當前 LED
    digitalWrite(LED_PINS[i % NUM_LEDS], HIGH);
    delay(200);
  }
}

// 播放指定閃爍模式
void playPattern(int patternIndex) {
  for (int step = 0; step < PATTERN_LENGTH; step++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(LED_PINS[i], PATTERNS[patternIndex][step]);
    }
    delay(PATTERN_DELAY);
  }
}

// 自定義閃爍函數
void customBlink(int pin, int onTime, int offTime, int repeatCount) {
  for (int i = 0; i < repeatCount; i++) {
    digitalWrite(pin, HIGH);
    delay(onTime);
    digitalWrite(pin, LOW);
    delay(offTime);
  }
}

// LED 漸變效果
void fadeEffect(int pin, int startBrightness, int endBrightness, int fadeTime) {
  int steps = abs(endBrightness - startBrightness);
  int delayTime = fadeTime / steps;

  if (startBrightness < endBrightness) {
    for (int i = startBrightness; i <= endBrightness; i++) {
      analogWrite(pin, i);
      delay(delayTime);
    }
  } else {
    for (int i = startBrightness; i >= endBrightness; i--) {
      analogWrite(pin, i);
      delay(delayTime);
    }
  }
}