#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// 自定義字元（笑臉動畫）
byte customChar[8][8] = {
  // 笑臉 1
  {
    B00000,
    B00000,
    B01010,
    B00000,
    B10001,
    B01110,
    B00000,
    B00000
  },
  // 笑臉 2
  {
    B00000,
    B00000,
    B01010,
    B00000,
    B00000,
    B11111,
    B00000,
    B00000
  }
};

void setup() {
  lcd.init();
  lcd.backlight();

  // 創建自定義字元
  for (int i = 0; i < 2; i++) {
    lcd.createChar(i, customChar[i]);
  }

  lcd.print("Custom Chars:");
}

void loop() {
  // 顯示動畫
  lcd.setCursor(0, 1);
  lcd.write(0);  // 顯示笑臉 1
  delay(500);
  lcd.setCursor(0, 1);
  lcd.write(1);  // 顯示笑臉 2
  delay(500);
}