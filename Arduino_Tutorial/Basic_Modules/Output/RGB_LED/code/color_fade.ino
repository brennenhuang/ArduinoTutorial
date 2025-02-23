const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const boolean COMMON_ANODE = false;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // 彩虹效果
  rainbowFade(5);
}

// 彩虹漸變效果
void rainbowFade(int wait) {
  float hue = 0.0;

  // 完整的 HSV 色相環
  while (hue < 360) {
    // 將 HSV 轉換為 RGB
    float saturation = 1.0;  // 飽和度最大
    float value = 1.0;      // 亮度最大

    // 計算當前色相的 RGB 值
    int rgb[3];
    HSVtoRGB(hue, saturation, value, rgb);

    // 設定顏色
    setColor(rgb[0], rgb[1], rgb[2]);

    hue += 0.1;  // 色相漸變步進
    delay(wait);
  }
}

// HSV 轉 RGB
void HSVtoRGB(float h, float s, float v, int rgb[3]) {
  int i = floor(h/60.0);
  float f = h/60.0 - i;
  float p = v * (1 - s);
  float q = v * (1 - f * s);
  float t = v * (1 - (1 - f) * s);

  float r, g, b;
  switch (i % 6) {
    case 0: r = v; g = t; b = p; break;
    case 1: r = q; g = v; b = p; break;
    case 2: r = p; g = v; b = t; break;
    case 3: r = p; g = q; b = v; break;
    case 4: r = t; g = p; b = v; break;
    case 5: r = v; g = p; b = q; break;
  }

  rgb[0] = r * 255;
  rgb[1] = g * 255;
  rgb[2] = b * 255;
}

void setColor(int red, int green, int blue) {
  if (COMMON_ANODE) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  }
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}