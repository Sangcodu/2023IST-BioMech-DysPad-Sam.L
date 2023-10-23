/*
Author: Roman Lacbungan
!!YOU HAVE TO CHANGE KEYBINDS AS THESE AREN'T DEFAULT (REFER TO CONTROLS BELOW)!!
( •̀ ω •́ )y
BPIN   	Case
2	      0
3	      1
4	      2
5	      3

Controls (excluding joystick):
- Jump = A
- Climb = B
- Dash = C
- Pause = D
- Talk/Interact = E

not yet added joystick look combo thing i add it later
*/

#include <Keyboard.h>

const int buttonPins[] = {2, 3, 4, 5}; // the pins that the pushbuttons are attached to
int buttonStates[] = {0, 0, 0, 0}; // current state of the buttons
int lastButtonStates[] = {0, 0, 0, 0}; // previous state of the buttons

void setup() {
  for (int i = 0; i < sizeof(buttonPins)/sizeof(buttonPins[0]); i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // initialize the button pins as pullup inputs
  }
  
  Keyboard.begin(); // initialize the Keyboard library
}

void loop() {
  for (int i = 0; i < sizeof(buttonPins)/sizeof(buttonPins[0]); i++) {
    buttonStates[i] = digitalRead(buttonPins[i]); // read the state of each button

    if (buttonStates[i] != lastButtonStates[i]) { // check if the button state has changed
      if (buttonStates[i] == LOW) { // check if the button is pressed
        switch(i) {
          case 0:
            Keyboard.press('a'); // jump
            break;
          case 1:
            Keyboard.press('b'); // climb
            break;
          case 2:
            Keyboard.press('c'); // dash
            break;
          case 3:
            Keyboard.press('d'); // pause
            break;
        }
        delay(50); // wait for a short period of time
        
        for (int j = i + 1; j < sizeof(buttonPins)/sizeof(buttonPins[0]); j++) {
          if (buttonStates[j] == LOW) { // check if another button is pressed
            switch(j) {
              case 1:
                Keyboard.press('e'); // talk to npc
                break;
            }
            delay(50); // wait for a short period of time
            
            switch(j) {
              case 1:
                Keyboard.release('e'); // talk
                break;
            }
          }
        }
        
        switch(i) {
          case 0:
            Keyboard.release('a'); // jump
            break;
          case 1:
            Keyboard.release('b'); // climb
            break;
          case 2:
            Keyboard.release('c'); // dash
            break;
          case 3:
            Keyboard.release('d'); // pause
            break;
        }
      }
      lastButtonStates[i] = buttonStates[i]; // update the previous button state
    }
  }
}