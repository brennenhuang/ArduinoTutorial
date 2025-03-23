# Arduino 函式（Functions）基礎

## 什麼是函式？
函式是一段可重複使用的程式碼，可以：
- 讓程式更容易理解
- 避免重複寫相同的程式碼
- 方便修改和維護

## 函式基礎

### 基本結構
```cpp
// 無參數無回傳值的函式
void sayHello() {
    Serial.println("Hello!");
}

// 有參數的函式
void blinkLED(int pin, int times) {
    for (int i = 0; i < times; i++) {
        digitalWrite(pin, HIGH);
        delay(1000);
        digitalWrite(pin, LOW);
        delay(1000);
    }
}

// 有回傳值的函式
int addNumbers(int a, int b) {
    return a + b;
}
```

### 函式呼叫
```cpp
void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);

    sayHello();           // 呼叫無參數函式
    blinkLED(13, 3);      // 呼叫有參數函式
    int sum = addNumbers(5, 3);  // 呼叫有回傳值函式
}
```

## 實用範例

### 1. LED 控制函式
```cpp
const int LED_PIN = 13;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    blinkPattern(3, 200);  // 快速閃爍 3 次
    delay(1000);
    blinkPattern(2, 500);  // 慢速閃爍 2 次
    delay(1000);
}

// LED 閃爍模式函式
void blinkPattern(int times, int delayTime) {
    for (int i = 0; i < times; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(delayTime);
        digitalWrite(LED_PIN, LOW);
        delay(delayTime);
    }
}
```

### 2. 感測器讀取與處理
```cpp
const int TEMP_PIN = A0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    float temperature = readTemperature();
    String status = checkTemperature(temperature);

    displayResults(temperature, status);
    delay(1000);
}

// 讀取溫度
float readTemperature() {
    int rawValue = analogRead(TEMP_PIN);
    float voltage = rawValue * (5.0 / 1023.0);
    return voltage * 100;  // LM35 溫度轉換
}

// 檢查溫度狀態
String checkTemperature(float temp) {
    if (temp < 20) return "太冷";
    if (temp > 30) return "太熱";
    return "適中";
}

// 顯示結果
void displayResults(float temp, String status) {
    Serial.print("溫度：");
    Serial.print(temp);
    Serial.print("°C, 狀態：");
    Serial.println(status);
}
```

## 進階概念

### 1. 參數傳遞
```cpp
// 傳值呼叫
void modifyNumber(int number) {
    number = number + 1;  // 不會改變原始值
}

// 傳址呼叫（使用指標）
void modifyArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = array[i] * 2;  // 會改變原始陣列
    }
}
```

### 2. 函式重載
```cpp
// 同名但參數不同的函式
void setLED(int pin) {
    digitalWrite(pin, HIGH);
}

void setLED(int pin, int state) {
    digitalWrite(pin, state);
}

void setLED(int pin, int state, int duration) {
    digitalWrite(pin, state);
    delay(duration);
    digitalWrite(pin, !state);
}
```

### 3. 遞迴函式
```cpp
// 計算階乘的遞迴函式
long factorial(long n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

## 實用技巧

### 1. 函式最佳化
```cpp
// 內聯函式（建議用於簡短常用的函式）
inline int square(int x) {
    return x * x;
}

// 使用 const 參數防止修改
void displayValue(const int value) {
    Serial.println(value);
}
```

### 2. 函式庫使用
```cpp
// 在檔案開頭引入函式庫
#include <Servo.h>
#include "MyLibrary.h"

// 使用函式庫中的函式
Servo myServo;
myServo.write(90);
```

## 練習
1. 製作一個函式來計算多個數字的平均值
2. 製作一個 LED 燈效函式庫，包含多種閃爍模式
3. 製作一個溫度轉換函式（攝氏轉華氏）

## 常見問題
1. 函式無法使用？
   - 檢查函式是否宣告在使用之前
   - 確認參數類型和數量是否正確
   - 檢查是否有引入需要的函式庫

2. 全域變數使用問題？
   - 盡量避免過度使用全域變數
   - 使用參數傳遞代替全域變數
   - 注意變數範圍和生命週期

3. 記憶體不足？
   - 避免在函式中宣告大型陣列
   - 使用參數傳遞代替全域變數
   - 考慮使用 PROGMEM 儲存常數