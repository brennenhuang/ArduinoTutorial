# Arduino 類比輸入輸出（Analog I/O）

## 什麼是類比訊號？
類比訊號是連續的數值，不像數位訊號只有 0 和 1：
- 類比輸入：可以讀取 0~5V 之間的任何電壓，轉換為 0~1023 的數值
- 類比輸出：可以輸出 0~5V 之間的任何電壓，使用 PWM 模擬，範圍是 0~255

## 類比輸入（Analog Input）

### 基本讀取
```cpp
void loop() {
    int sensorValue = analogRead(A0);  // 讀取 A0 腳位
    // sensorValue 範圍：0-1023
}
```

### 電壓轉換
```cpp
void loop() {
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (5.0 / 1023.0);  // 轉換為實際電壓
    Serial.println(voltage);
}
```

## 類比輸出（PWM 輸出）

### 基本輸出
```cpp
void loop() {
    analogWrite(3, 128);  // 輸出約 2.5V（半亮）
    delay(1000);
    analogWrite(3, 255);  // 輸出 5V（全亮）
    delay(1000);
}
```

### LED 漸變效果
```cpp
const int LED_PIN = 3;  // PWM 腳位

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // 漸亮
    for (int i = 0; i <= 255; i++) {
        analogWrite(LED_PIN, i);
        delay(10);
    }

    // 漸暗
    for (int i = 255; i >= 0; i--) {
        analogWrite(LED_PIN, i);
        delay(10);
    }
}
```

## 實用範例

### 1. 光敏電阻控制 LED 亮度
```cpp
const int LIGHT_SENSOR = A0;  // 光敏電阻接在 A0
const int LED_PIN = 3;        // LED 接在 3 號腳位（PWM）

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // 讀取光線強度
    int lightLevel = analogRead(LIGHT_SENSOR);

    // 映射數值範圍（0-1023 轉換為 0-255）
    int brightness = map(lightLevel, 0, 1023, 255, 0);

    // 控制 LED 亮度
    analogWrite(LED_PIN, brightness);

    // 顯示數值
    Serial.print("光線強度：");
    Serial.print(lightLevel);
    Serial.print(", LED 亮度：");
    Serial.println(brightness);

    delay(100);
}
```

### 2. 可變電阻控制伺服馬達
```cpp
#include <Servo.h>

const int POT_PIN = A0;     // 可變電阻接在 A0
const int SERVO_PIN = 9;    // 伺服馬達接在 9 號腳位

Servo myServo;  // 建立伺服馬達物件

void setup() {
    myServo.attach(SERVO_PIN);
    Serial.begin(9600);
}

void loop() {
    // 讀取可變電阻
    int potValue = analogRead(POT_PIN);

    // 映射為角度（0-1023 轉換為 0-180）
    int angle = map(potValue, 0, 1023, 0, 180);

    // 控制伺服馬達
    myServo.write(angle);

    // 顯示數值
    Serial.print("可變電阻：");
    Serial.print(potValue);
    Serial.print(", 角度：");
    Serial.println(angle);

    delay(15);
}
```

## 重要觀念

### 1. ADC（類比數位轉換）
- Arduino 使用 10 位元 ADC
- 數值範圍：0-1023（2^10）
- 解析度：5V/1024 ≈ 4.9mV

### 2. PWM（脈寬調變）
- 數值範圍：0-255（8 位元）
- 頻率：約 490Hz（腳位 3, 9, 10, 11）或 980Hz（腳位 5, 6）
- 並非真正的類比輸出，而是快速切換數位訊號

### 3. 類比輸入腳位
- Arduino UNO 有 6 個類比輸入腳位（A0-A5）
- 輸入電壓範圍：0-5V
- 輸入阻抗：100MΩ

## 常用應用

### 1. 溫度感測器讀取
```cpp
const int TEMP_PIN = A0;
const float VOLTAGE_PER_UNIT = 5.0 / 1023.0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    // 讀取溫度感測器
    int sensorValue = analogRead(TEMP_PIN);

    // 轉換為電壓
    float voltage = sensorValue * VOLTAGE_PER_UNIT;

    // 轉換為溫度（以 LM35 為例）
    float temperature = voltage * 100;

    Serial.print("溫度：");
    Serial.print(temperature);
    Serial.println("°C");

    delay(1000);
}
```

### 2. RGB LED 控制
```cpp
const int RED_PIN = 9;    // 紅色 LED 接在 9 號腳位
const int GREEN_PIN = 10; // 綠色 LED 接在 10 號腳位
const int BLUE_PIN = 11;  // 藍色 LED 接在 11 號腳位

void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
    // 紅色漸變
    setColor(255, 0, 0);
    delay(1000);

    // 綠色漸變
    setColor(0, 255, 0);
    delay(1000);

    // 藍色漸變
    setColor(0, 0, 255);
    delay(1000);
}

void setColor(int red, int green, int blue) {
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}
```

## 練習
1. 製作一個根據環境光線自動調整亮度的夜燈
2. 使用可變電阻控制 RGB LED 的顏色
3. 製作一個簡單的溫度警報器，當溫度過高時 LED 會閃爍

## 常見問題
1. 類比讀取值不穩定？
   - 使用濾波電容
   - 多次讀取取平均值
   - 檢查接線是否穩固

2. PWM 輸出有雜訊？
   - 檢查負載是否合適
   - 考慮使用濾波電路
   - 調整 PWM 頻率

3. 類比輸入讀取範圍不正確？
   - 檢查參考電壓設定
   - 確認感測器規格
   - 校正轉換公式