# Arduino 變數與資料型態

## 變數基礎
變數就像是一個儲存盒，可以存放不同類型的資料。在 Arduino 中，變數必須先宣告才能使用。

### 變數宣告
```cpp
int number;           // 宣告整數變數
float temperature;    // 宣告浮點數變數
char letter;         // 宣告字元變數
```

### 變數初始化
```cpp
int count = 0;       // 宣告時給初始值
float pi = 3.14;     // 浮點數初始化
char grade = 'A';    // 字元初始化
```

## 常用資料型態

### 1. 整數類型
```cpp
byte smallNumber = 255;          // 0 到 255
int number = -32768;            // -32768 到 32767
unsigned int bigNumber = 65535;  // 0 到 65535
long veryBig = 2147483647;      // 超大數字
```

### 2. 浮點數類型
```cpp
float decimal = 3.14;        // 單精度浮點數
double precise = 3.141592;   // 雙精度浮點數
```

### 3. 字元和字串
```cpp
char letter = 'A';              // 單一字元
String message = "Hello";       // 字串
char text[] = "Arduino";        // 字元陣列
```

### 4. 布林值
```cpp
boolean isOn = true;     // 真
bool isOff = false;      // 假
```

## 常數定義

### 使用 #define
```cpp
#define LED_PIN 13        // 編譯時替換
#define PI 3.14159        // 不占用記憶體
```

### 使用 const
```cpp
const int BUTTON_PIN = 2;  // 占用記憶體但有型態檢查
const float TEMP_MAX = 50.0;
```

## 變數範圍

### 全域變數
```cpp
int globalVar = 10;  // 在函式外宣告

void setup() {
    // 可以使用 globalVar
}

void loop() {
    // 也可以使用 globalVar
}
```

### 區域變數
```cpp
void loop() {
    int localVar = 20;  // 只在 loop 內有效
    // 使用 localVar
}  // localVar 在這裡消失
```

## 實用範例：溫度轉換器
```cpp
// 全域常數
const float CELSIUS_MIN = -40.0;
const float CELSIUS_MAX = 125.0;

// 全域變數
float celsius;
float fahrenheit;

void setup() {
    Serial.begin(9600);
}

void loop() {
    // 讀取溫度
    celsius = analogRead(A0) * 0.48876;

    // 轉換溫度
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    // 檢查範圍
    if (celsius >= CELSIUS_MIN && celsius <= CELSIUS_MAX) {
        // 輸出結果
        Serial.print("攝氏：");
        Serial.print(celsius);
        Serial.print("°C, 華氏：");
        Serial.print(fahrenheit);
        Serial.println("°F");
    }

    delay(1000);
}
```

## 變數使用技巧

### 1. 型態轉換
```cpp
int x = 10;
float y = (float)x;    // 整數轉浮點數
int z = (int)3.14;     // 浮點數轉整數
```

### 2. 運算符號
```cpp
int a = 5 + 3;         // 加法
int b = 10 - 4;        // 減法
int c = 6 * 2;         // 乘法
float d = 15.0 / 2.0;  // 除法
int e = 7 % 3;         // 餘數
```

### 3. 遞增遞減
```cpp
int count = 0;
count++;               // 加 1
count--;               // 減 1
count += 2;            // 加 2
```

## 練習
1. 製作一個計數器，使用不同型態的變數記錄次數
2. 製作一個字串處理程式，將輸入的文字反轉
3. 使用布林變數製作一個開關狀態檢測器

## 常見問題
1. 變數值異常？
   - 檢查變數型態是否正確
   - 確認變數範圍是否足夠
   - 檢查是否有溢位問題

2. 記憶體不足？
   - 使用較小的資料型態
   - 減少全域變數使用
   - 善用 const 和 #define

3. 變數無法修改？
   - 檢查是否宣告為 const
   - 確認變數範圍是否正確
   - 檢查是否有權限存取