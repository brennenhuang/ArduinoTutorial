# Arduino 序列通訊（Serial）基礎

## 什麼是序列通訊？
序列通訊是 Arduino 與電腦之間溝通的橋樑，可以：
- 從 Arduino 發送資料到電腦
- 從電腦發送指令到 Arduino
- 用來除錯程式（Debug）

## 基本使用方法

### 1. 開始序列通訊
```cpp
void setup() {
    Serial.begin(9600);    // 設定鮑率（Baud Rate）為 9600
}
```

### 2. 發送資料到電腦
```cpp
void loop() {
    Serial.print("Hello");      // 不換行輸出
    Serial.println(" World!");  // 換行輸出
    delay(1000);               // 等待 1 秒
}
```

### 3. 接收電腦發送的資料
```cpp
void loop() {
    if (Serial.available() > 0) {           // 檢查是否有資料
        char incomingByte = Serial.read();  // 讀取一個字元
        Serial.print("收到：");
        Serial.println(incomingByte);
    }
}
```

## 常用函式說明

### 輸出函式
- `Serial.print()`: 輸出不換行
- `Serial.println()`: 輸出後換行
- `Serial.write()`: 輸出原始位元組

### 輸入函式
- `Serial.available()`: 檢查是否有資料可讀
- `Serial.read()`: 讀取一個位元組
- `Serial.readString()`: 讀取一個字串

### 其他函式
- `Serial.flush()`: 等待資料傳送完成
- `Serial.end()`: 結束序列通訊

## 完整範例：溫度監測器
```cpp
const int tempPin = A0;  // 溫度感測器接在 A0

void setup() {
    Serial.begin(9600);  // 啟動序列通訊
}

void loop() {
    // 讀取溫度值
    int tempValue = analogRead(tempPin);

    // 轉換成實際溫度
    float temperature = (tempValue * 5.0 * 100.0) / 1024.0;

    // 輸出溫度
    Serial.print("溫度：");
    Serial.print(temperature);
    Serial.println("°C");

    delay(1000);  // 每秒更新一次
}
```

## 實用技巧

### 1. 格式化輸出
```cpp
float pi = 3.14159;
Serial.println(pi, 2);      // 顯示到小數點後 2 位：3.14
```

### 2. 多種資料型態輸出
```cpp
int number = 42;
String text = "答案是：";
Serial.print(text);         // 輸出字串
Serial.println(number);     // 輸出數字
```

### 3. 除錯用法
```cpp
void loop() {
    // 在關鍵點加入除錯訊息
    Serial.println("進入 loop");

    // 顯示變數值
    int sensor = analogRead(A0);
    Serial.print("感測器數值：");
    Serial.println(sensor);
}
```

## 練習
1. 製作一個簡單的計算機，從序列埠輸入兩個數字，輸出它們的和
2. 製作一個 LED 控制器，從序列埠輸入 "ON" 或 "OFF" 來控制 LED
3. 每隔一秒輸出一個遞增的計數器值

## 常見問題
1. 看不到序列輸出？
   - 檢查鮑率是否正確（預設 9600）
   - 確認是否有呼叫 Serial.begin()
   - 檢查 USB 連接是否正常

2. 資料顯示亂碼？
   - 檢查鮑率設定是否一致
   - 確認傳輸的資料格式

3. 程式無回應？
   - 檢查是否在等待序列輸入
   - 確認 loop() 中沒有無限迴圈