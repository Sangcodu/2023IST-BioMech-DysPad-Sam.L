#include <Keyboard.h>

static unsigned int BUTTON_PIN1 = D5;
static unsigned int BUTTON_PIN2 = D6;
static unsigned int BUTTON_PIN3 = D7;
static unsigned int BUTTON_PIN4 = D8;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();

  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN1) == LOW) {
    Keyboard.press('X');
  } else {
    Keyboard.release('X');
  }

  if (digitalRead(BUTTON_PIN2) == LOW) {
    Keyboard.press('Z');
  } else {
    Keyboard.release('Z');
  }
  
  if (digitalRead(BUTTON_PIN3) == LOW) {
    Keyboard.press('C');
  } else {
    Keyboard.release('C');
  }

  if (digitalRead(BUTTON_PIN4) == LOW) {
    Keyboard.press(KEY_ESC);
  } else {
    Keyboard.release(KEY_ESC);
  }

  delay(100);
}
