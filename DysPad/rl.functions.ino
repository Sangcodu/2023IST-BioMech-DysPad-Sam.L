#include <Keyboard.h>

unsigned int BUTTON_PIN1 = D5;
unsigned int BUTTON_PIN2 = D6;
unsigned int BUTTON_PIN3 = D7;
unsigned int BUTTON_PIN4 = D8;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  delay(1000);

  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN1) == HIGH && digitalRead(BUTTON_PIN2) == HIGH) {
    Keyboard.press('r');
  } else {
    Keyboard.release('r');
  }

  if (digitalRead(BUTTON_PIN1) == HIGH) {
    Keyboard.press('x');
  } else {
    Keyboard.release('x');
  }

  if (digitalRead(BUTTON_PIN2) == HIGH) {
    Keyboard.press('z');
  } else {
    Keyboard.release('z');
  }
  
  if (digitalRead(BUTTON_PIN3) == HIGH) {
    Keyboard.press('c');
  } else {
    Keyboard.release('c');
  }

  if (digitalRead(BUTTON_PIN4) == HIGH) {
    Keyboard.press(KEY_ESC);
  } else {
    Keyboard.release(KEY_ESC);
  }

  delay(100);
}
