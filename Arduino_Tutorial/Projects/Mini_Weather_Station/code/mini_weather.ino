#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 定義腳位
#define DHTPIN 2          // DHT11 連接到 D2
#define DHTTYPE DHT11     // DHT 類型

// 初始化感測器
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 設定 I2C 位址 0x27

// 自定義符號：溫度計
byte thermometer[8] = {
  B00100,
  B01010,
  B01010,
  B01010,
  B01010,
  B10001,
  B10001,
  B01110
};

// 自定義符號：水滴
byte droplet[8] = {
  B00000,
  B00100,
  B01110,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

void setup() {
  Serial.begin(9600);

  // 初始化 LCD
  lcd.init();
  lcd.backlight();

  // 建立自定義符號
  lcd.createChar(0, thermometer);
  lcd.createChar(1, droplet);

  // 初始化 DHT 感測器
  dht.begin();

  // 顯示啟動訊息
  lcd.print("Mini Weather");
  lcd.setCursor(0, 1);
  lcd.print("Station");
  delay(2000);
}

void loop() {
  // 讀取溫濕度數據
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // 檢查是否讀取失敗
  if (isnan(humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.print("Sensor Error!");
    return;
  }

  // 更新顯示
  updateDisplay(temperature, humidity);

  // 更新間隔
  delay(1000);
}

void updateDisplay(float temp, float hum) {
  lcd.clear();

  // 顯示溫度
  lcd.setCursor(0, 0);
  lcd.write(0);  // 溫度計符號
  lcd.print(" Temp: ");
  lcd.print(temp, 1);
  lcd.print((char)223);  // 度數符號
  lcd.print("C");

  // 顯示濕度
  lcd.setCursor(0, 1);
  lcd.write(1);  // 水滴符號
  lcd.print(" Hum: ");
  lcd.print(hum, 1);
  lcd.print("%");

  // 同時輸出到序列監視器
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C, Humidity: ");
  Serial.print(hum);
  Serial.println(" %");
}