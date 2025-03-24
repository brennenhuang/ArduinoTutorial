# RFID 模組教學

## 簡介
RFID（Radio-Frequency IDentification）是一種無線射頻識別技術，可用於門禁系統、物品追蹤等應用。本教學使用 MFRC522 模組進行讀卡操作。

## 硬體需求
- MFRC522 RFID 模組
- RFID 卡片或鑰匙圈
- 連接線
- LED 指示燈（選配）
- 蜂鳴器（選配）

## 接線說明
MFRC522 與 Arduino 的連接：
- SDA  -> 10 (SS)
- SCK  -> 13 (SCK)
- MOSI -> 11 (MOSI)
- MISO -> 12 (MISO)
- IRQ  -> 不連接
- GND  -> GND
- RST  -> 9
- 3.3V -> 3.3V

## 程式範例
1. 讀取卡片 (rfid_read.ino)
   - 讀取卡片 ID
   - 顯示卡片類型

2. 寫入資料 (rfid_write.ino)
   - 寫入自定義資料
   - 資料加密儲存

## 應用範例
- 門禁系統
- 考勤系統
- 電子錢包
- 物品追蹤

## 注意事項
- 使用 3.3V 供電（不可使用 5V）
- 避免金屬物體干擾
- 注意讀取距離限制（通常 3-5 cm）
- 建議使用 SPI 通訊