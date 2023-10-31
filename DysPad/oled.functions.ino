void config ();
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // High-speed I2C

void setup(myPOTOLED) {
  u8g2.begin();
  int textX = 0;
  unsigned long startTime;
  const unsigned long animationDuration = 10000;
  int potPIN = A0;  // Potentiometer pin
  int potValue = 0;  // Potentiometer reading
  startTime = millis();
}

void loop(void) {
  unsigned long currentTime = millis();

  potValue = analogRead(potPIN);

  if (potValue < 400) {
    displayText("NT");
  } else if (potValue > 600) {
    displayText("GG");
  } else {
    if (currentTime - startTime < animationDuration) {
      // Continue the animation with "DysPad - Anna"
      animateDysPadAnna();
    } else {
      // After the animation, display "UwU" in the center
      displayText("UwU");
    }
  }
}

void animateDysPadAnna() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr); // Choose a suitable font
  u8g2.setCursor(textX, 50);
  u8g2.print("DysPad - Anna");
  u8g2.sendBuffer();
  delay(20);
  textX++;
  if (textX > u8g2.getDisplayWidth()) {
    textX = -u8g2.getStrWidth("DysPad - Anna");
  }
}

void displayText(const char *text) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr); // Choose a suitable font
  int textWidth = u8g2.getStrWidth(text);
  int textXPos = (u8g2.getDisplayWidth() - textWidth) / 2;
  u8g2.setCursor(textXPos, 50);
  u8g2.print(text);
  u8g2.sendBuffer();
  delay(100);
}





