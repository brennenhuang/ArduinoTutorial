#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 7    // LED 指示燈
// #define BUZZER_PIN 7 // 蜂鳴器

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();      // 初始化 SPI 通訊
  rfid.PCD_Init();  // 初始化 RFID 讀卡機

  pinMode(LED_PIN, OUTPUT);
  // pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("請將卡片靠近讀卡機...");
}

void loop() {
  // 檢查是否有新卡片
  if (!rfid.PICC_IsNewCardPresent())
    return;

  // 讀取卡片
  if (!rfid.PICC_ReadCardSerial())
    return;

  // 顯示卡片 UID
  Serial.print("卡片 UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  // 顯示卡片類型
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.print("卡片類型: ");
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // 成功讀取指示
  digitalWrite(LED_PIN, HIGH);
  // tone(BUZZER_PIN, 2000, 100);
  delay(500);
  digitalWrite(LED_PIN, LOW);

  rfid.PICC_HaltA();  // 停止讀取
  rfid.PCD_StopCrypto1();  // 停止加密
}