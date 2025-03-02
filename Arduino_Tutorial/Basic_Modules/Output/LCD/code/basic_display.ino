#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 設定 LCD I2C 位址為 0x27(默認為0x27或0x3F，依據背板的晶片不同而有差異)，16字元 x 2行
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int PROGRESS_BAR_WIDTH = 9;  // 進度條主體寬度

void setup() {
  // 初始化 LCD
  lcd.init();
  // 開啟背光
  lcd.backlight();

  // 顯示歡迎訊息
  lcd.setCursor(0, 0); // 設定游標位置(column, row)
  lcd.print("Hello, Arduino!");
  lcd.setCursor(0, 1); // 設定游標位置(column, row)
  lcd.print("LCD Ready!");
  delay(2000);
}

void loop() {
  // 清除螢幕
  lcd.clear();

  // 顯示計數器
  for (int i = 0; i < 10; i++) {
    lcd.setCursor(0, 0);
    lcd.print("Counter: ");
    lcd.print(i);

    // 顯示進度條
    lcd.setCursor(0, 1);
    lcd.print("[");
    for (int j = 0; j < i; j++) {
      lcd.print("=");
    }
    for (int j = i; j < PROGRESS_BAR_WIDTH; j++) {
      lcd.print(" ");
    }
    lcd.print("]");

    delay(1000);
  }

  // 文字捲動效果
  lcd.clear();
  lcd.print("Scrolling Text");
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
}