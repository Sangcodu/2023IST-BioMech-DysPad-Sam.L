// thanks to https://roboticsbackend.com/arduino-input_pullup-pinmode/ helped alot
// libaries being used: Keyboard

#include <Keyboard.h>

unsigned int BUTTON_PIN1 = D5;
unsigned int BUTTON_PIN2 = D6;
unsigned int BUTTON_PIN3 = D7;
unsigned int BUTTON_PIN4 = D8;

void setup() {
  Keyboard.begin();

  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
}

void loop() {

  // combo which is quick restart in-game
  if (digitalRead(BUTTON_PIN1) == LOW + digitalRead(BUTTON_PIN2)) {
  Keyboard.press('R');
  } else {
  Keyboard.release('R');
  }

  // dash
  if (digitalRead(BUTTON_PIN1) == LOW) {
    Keyboard.press('X');
  } else {
    Keyboard.release('X');
  }

  // grab or interact
  if (digitalRead(BUTTON_PIN2) == LOW) {
    Keyboard.press('Z');
  } else {
    Keyboard.release('Z');
  }
  
  // jump
  if (digitalRead(BUTTON_PIN3) == LOW) {
    Keyboard.press('C');
  } else {
    Keyboard.release('C');
  }

  // pause
  if (digitalRead(BUTTON_PIN4) == LOW) {
    Keyboard.press('KEY_ESC');
  } else {
    Keyboard.release('KEY_ESC');
  }

  delay(100);
}
