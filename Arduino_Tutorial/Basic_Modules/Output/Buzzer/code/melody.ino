const int BUZZER_PIN = 9;  // 蜂鳴器接在 9 腳位（PWM）

// 定義音符頻率
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// 小星星旋律
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

// 音符持續時間（毫秒）
int noteDurations[] = {
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  playMelody();
  delay(2000);  // 播放完等待 2 秒
}

void playMelody() {
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int duration = noteDurations[i];
    tone(BUZZER_PIN, melody[i], duration);

    // 音符之間要有短暫停頓
    delay(duration * 1.1);
    noTone(BUZZER_PIN);
  }
}