# Arduino 程式基本結構：setup() 和 loop()

## 概述
每個 Arduino 程式都必須包含兩個基本函式：
- `setup()`: 程式開始時執行一次的設定
- `loop()`: 重複執行的主要程式碼

## setup() 函式
### 說明
- 當 Arduino 開機或重置時執行一次
- 用來進行初始設定
- 設定完成後就不會再執行

### 常見用途
1. 設定腳位模式
```cpp
void setup() {
    pinMode(13, OUTPUT);    // 設定 13 號腳位為輸出模式
    pinMode(2, INPUT);      // 設定 2 號腳位為輸入模式
}
```

2. 開始序列通訊
```cpp
void setup() {
    Serial.begin(9600);     // 啟動序列通訊，速率 9600
}
```

3. 初始化變數
```cpp
int myLED = 13;
void setup() {
    pinMode(myLED, OUTPUT);
}
```

## loop() 函式
### 說明
- 在 setup() 執行完後開始執行
- 會不斷重複執行
- 用來放主要的程式邏輯

### 常見用途
1. 讀取感測器
```cpp
void loop() {
    int sensorValue = digitalRead(2);    // 讀取感測器數值
    delay(100);                          // 等待 0.1 秒
}
```

2. 控制輸出
```cpp
void loop() {
    digitalWrite(13, HIGH);   // LED 開
    delay(1000);             // 等待 1 秒
    digitalWrite(13, LOW);    // LED 關
    delay(1000);             // 等待 1 秒
}
```

## 完整範例：LED 閃爍
```cpp
// LED 腳位定義
const int LED_PIN = 13;

// 初始設定
void setup() {
    // 設定 LED 腳位為輸出
    pinMode(LED_PIN, OUTPUT);
}

// 主要程式
void loop() {
    digitalWrite(LED_PIN, HIGH);   // 點亮 LED
    delay(1000);                   // 等待 1 秒
    digitalWrite(LED_PIN, LOW);    // 關閉 LED
    delay(1000);                   // 等待 1 秒
}
```

## 練習
1. 修改上面的程式，讓 LED 閃爍速度變快（每 0.5 秒閃一次）
2. 添加第二個 LED，讓兩個 LED 交替閃爍
3. 使用 `Serial.println()` 在序列監視器上顯示目前 LED 的狀態

## 常見問題
1. 為什麼我的 setup() 執行多次？
   - 可能是 Arduino 在重置
   - 檢查電源是否穩定
   - 確認程式上傳是否正確

2. loop() 執行太快怎麼辦？
   - 使用 delay() 函式來控制執行速度
   - 注意 delay() 會暫停所有程式執行

3. 可以不寫 setup() 或 loop() 嗎？
   - 不行，這兩個函式是必須的
   - 即使沒有要設定什麼，也要保留空的 setup()