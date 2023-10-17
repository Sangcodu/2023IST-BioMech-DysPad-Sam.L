#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/SCL, /* data=*/SDA, /* reset=*/U8X8_PIN_NONE);  // High-speed I2C
bool animationPlaying = false;

const int buttonPins[] = {2, 3, 4, 5};
const char* animations[] = {
  "Animation 1",
  "Animation 2",
  "Animation 3",
  "Animation 4"
};
const int numButtons = 4;

const unsigned int potPIN = A0;
int previousValue = 0;

void OLEDsetup() {
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  pinMode(potPIN, INPUT);
}

void playAnimation(const char* text) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setCursor(0, 10);
  u8g2.print(text);
  u8g2.sendBuffer();
  delay(1000);
}

void adjustVolume(int delta) {
  // Define the range for volume adjustment based on your needs
  const int volumeIncrement = 10;

  // You can adjust this range as per your requirements
  if (delta > 10) {
    // Increase volume
    // Implement your volume control logic here
  } else if (delta < -10) {
    // Decrease volume
    // Implement your volume control logic here
  }
}

void OLEDloop() {
  int potValue = analogRead(potPIN);
  int delta = potValue - previousValue;

  Serial.println(potValue);

  adjustVolume(delta); // Adjust the computer's volume based on potentiometer movement

  for (int i = 0; i < numButtons; i++) {
    int buttonState = digitalRead(buttonPins[i]);
    if (buttonState == HIGH && !animationPlaying) {
      animationPlaying = true;
      playAnimation(animations[i]);

      u8g2.clearBuffer();
      u8g2.setFont(u8g2_font_ncenB08_tr);
      u8g2.setCursor(0, 10);
      u8g2.print("DysPad");
      u8g2.sendBuffer();

      animationPlaying = false;
    }
  }

  previousValue = potValue;
}

void loop() {
  OLEDloop();
}
