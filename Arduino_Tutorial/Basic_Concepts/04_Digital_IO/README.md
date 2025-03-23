# Arduino 數位輸入輸出（Digital I/O）

## 什麼是數位訊號？
數位訊號只有兩種狀態：
- HIGH（高電位）= 1 = 5V
- LOW（低電位）= 0 = 0V

就像電燈開關一樣，只有開（ON）和關（OFF）兩種狀態。

## 數位腳位基礎

### 設定腳位模式
```cpp
void setup() {
    pinMode(13, OUTPUT);    // 設定為輸出模式
    pinMode(2, INPUT);      // 設定為輸入模式
    pinMode(3, INPUT_PULLUP);  // 設定為輸入模式並啟用內建上拉電阻
}
```

### 數位輸出
```cpp
void loop() {
    digitalWrite(13, HIGH);   // 輸出高電位（5V）
    delay(1000);             // 等待一秒
    digitalWrite(13, LOW);    // 輸出低電位（0V）
    delay(1000);             // 等待一秒
}
```

### 數位輸入
```cpp
void loop() {
    int buttonState = digitalRead(2);  // 讀取按鈕狀態
    if (buttonState == HIGH) {
        // 按鈕被按下時的程式
    }
}
```

## 實用範例

### 1. LED 控制
```cpp
const int LED_PIN = 13;      // LED 接在 13 號腳位

void setup() {
    pinMode(LED_PIN, OUTPUT);  // 設定 LED 腳位為輸出
}

void loop() {
    digitalWrite(LED_PIN, HIGH);  // LED 亮
    delay(1000);                  // 等待一秒
    digitalWrite(LED_PIN, LOW);   // LED 暗
    delay(1000);                  // 等待一秒
}
```

### 2. 按鈕控制 LED
```cpp
const int BUTTON_PIN = 2;    // 按鈕接在 2 號腳位
const int LED_PIN = 13;      // LED 接在 13 號腳位

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // 設定按鈕為輸入，使用內建上拉電阻
    pinMode(LED_PIN, OUTPUT);           // 設定 LED 為輸出
}

void loop() {
    // 讀取按鈕狀態（因為使用上拉電阻，按下時為 LOW）
    if (digitalRead(BUTTON_PIN) == LOW) {
        digitalWrite(LED_PIN, HIGH);    // 按下按鈕時 LED 亮
    } else {
        digitalWrite(LED_PIN, LOW);     // 放開按鈕時 LED 暗
    }
}
```

### 3. 按鈕開關（切換狀態）
```cpp
const int BUTTON_PIN = 2;    // 按鈕接在 2 號腳位
const int LED_PIN = 13;      // LED 接在 13 號腳位

boolean ledState = false;    // LED 狀態
boolean lastButton = HIGH;   // 上一次按鈕狀態
boolean currentButton = HIGH;// 目前按鈕狀態

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // 讀取按鈕狀態
    currentButton = digitalRead(BUTTON_PIN);

    // 檢測按鈕是否被按下（從 HIGH 變成 LOW）
    if (lastButton == HIGH && currentButton == LOW) {
        ledState = !ledState;  // 切換 LED 狀態
        digitalWrite(LED_PIN, ledState ? HIGH : LOW);
        delay(50);  // 去彈跳延遲
    }

    lastButton = currentButton;  // 更新上一次的按鈕狀態
}
```

## 重要觀念

### 1. 上拉和下拉電阻
- 上拉電阻（Pull-up）：未按下時為 HIGH，按下時為 LOW
- 下拉電阻（Pull-down）：未按下時為 LOW，按下時為 HIGH
- Arduino 有內建的上拉電阻（INPUT_PULLUP）

### 2. 按鈕去彈跳
```cpp
// 簡單的去彈跳方法
if (digitalRead(BUTTON_PIN) == LOW) {
    delay(50);  // 等待彈跳結束
    if (digitalRead(BUTTON_PIN) == LOW) {
        // 確認按鈕真的被按下
    }
}
```

### 3. 電流限制
- 每個數位腳位最大輸出電流：20mA
- 建議使用電阻保護 LED 和其他元件

## 常用應用

### 1. 多個 LED 控制
```cpp
// LED 陣列
const int LED_PINS[] = {2, 3, 4, 5};
const int LED_COUNT = 4;

void setup() {
    // 設定所有 LED 腳位
    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(LED_PINS[i], OUTPUT);
    }
}

void loop() {
    // 輪流點亮 LED
    for (int i = 0; i < LED_COUNT; i++) {
        digitalWrite(LED_PINS[i], HIGH);
        delay(200);
        digitalWrite(LED_PINS[i], LOW);
    }
}
```

### 2. 多個按鈕輸入
```cpp
const int BUTTON_PINS[] = {2, 3, 4, 5};
const int BUTTON_COUNT = 4;

void setup() {
    // 設定所有按鈕腳位
    for (int i = 0; i < BUTTON_COUNT; i++) {
        pinMode(BUTTON_PINS[i], INPUT_PULLUP);
    }
    Serial.begin(9600);
}

void loop() {
    // 檢查所有按鈕
    for (int i = 0; i < BUTTON_COUNT; i++) {
        if (digitalRead(BUTTON_PINS[i]) == LOW) {
            Serial.print("按鈕 ");
            Serial.print(i);
            Serial.println(" 被按下");
            delay(50);  // 去彈跳
        }
    }
}
```

## 練習
1. 製作一個 LED 跑馬燈，使用 4 個 LED
2. 製作一個電子骰子，按下按鈕時隨機點亮一個 LED
3. 製作一個簡單的密碼鎖，使用多個按鈕輸入密碼

## 常見問題
1. LED 不亮？
   - 檢查接線是否正確
   - 確認 LED 正負極方向
   - 檢查是否加裝限流電阻

2. 按鈕不穩定？
   - 加入去彈跳延遲
   - 檢查接線是否穩固
   - 確認是否正確使用上拉/下拉電阻

3. 輸出電流不足？
   - 檢查負載電流需求
   - 使用電晶體或繼電器驅動大電流負載
   - 注意不要超過腳位最大電流限制