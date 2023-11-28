#include <Mouse.h>
#include <Keyboard.h>

#define VRX_PIN A0
#define VRY_PIN A1
#define SWITCH_PIN 2

#define LEFT_THRESHOLD  400
#define LEFTUP_THRESHOLD  400
#define LEFTDOWN_THRESHOLD  400
#define RIGHT_THRESHOLD 800
#define RIGHTUP_THRESHOLD 800
#define RIGHTDOWN_THRESHOLD 800
#define UP_THRESHOLD 400
#define DOWN_THRESHOLD 800

#define COMMAND_NO 0x00
#define COMMAND_LEFT 0x01
#define COMMAND_LEFTUP 0x02
#define COMMAND_LEFTDOWN 0x03
#define COMMAND_RIGHT 0x04
#define COMMAND_RIGHTUP 0x05
#define COMMAND_RIGHTDOWN 0x06
#define COMMAND_UP 0x07
#define COMMAND_DOWN 0x08

int xValue = 0;
int yValue = 0;
int command = COMMAND_NO;
bool cameraMode = false;

void performGameAction(int action) {
  if (cameraMode) {
    switch (action) {
      case COMMAND_LEFT:
        Serial.println("Camera LEFT");
        Mouse.move(-10, 0);
        break;
      case COMMAND_LEFTUP:
        Serial.println("Camera LEFT UP");
        Mouse.move(-10, 10);
        break;
      case COMMAND_LEFTDOWN:
        Serial.println("Camera LEFT DOWN");
        Mouse.move(-10, -10);
        break;
      case COMMAND_RIGHT:
        Serial.println("Camera RIGHT");
        Mouse.move(10, 0);
        break;
      case COMMAND_RIGHTUP:
        Serial.println("Camera RIGHT UP");
        Mouse.move(10, 10);
        break;
      case COMMAND_RIGHTDOWN:
        Serial.println("Camera RIGHT DOWN");
        Mouse.move(10, -10);
        break;
      case COMMAND_UP:
        Serial.println("Camera UP");
        Mouse.move(0, -10);
        break;
      case COMMAND_DOWN:
        Serial.println("Camera DOWN");
        Mouse.move(0, 10);
        break;
    }
  } else {
    switch (action) {
      case COMMAND_LEFT:
        Serial.println("Character LEFT");
        Keyboard.press('A');
        delay(50);
        Keyboard.release('A');
        break;
      case COMMAND_LEFTUP:
        Serial.println("Character LEFTUP");
        Keyboard.press('W');
        delay(50);
        Keyboard.release('W');
        break;
      case COMMAND_LEFTDOWN:
        Serial.println("Character LEFTDOWN");
        Keyboard.press('S');
        delay(50);
        Keyboard.release('S');
        break;
      case COMMAND_RIGHT:
        Serial.println("Character RIGHT");
        Keyboard.press('D');
        delay(50);
        Keyboard.release('D');
        break;
      case COMMAND_RIGHTUP:
        Serial.println("Character RIGHTUP");
        Keyboard.press('W');
        Keyboard.press('D');
        delay(50);
        Keyboard.release('W');
        Keyboard.release('D');
        break;
      case COMMAND_RIGHTDOWN:
        Serial.println("Character RIGHTDOWN");
        Keyboard.press('S');
        Keyboard.press('D');
        delay(50);
        Keyboard.release('S');
        Keyboard.release('D');
        break;
      case COMMAND_UP:
        Serial.println("Character UP");
        Keyboard.press('W');
        delay(50);
        Keyboard.release('W');
        break;
      case COMMAND_DOWN:
        Serial.println("Character DOWN");
        Keyboard.press('S');
        delay(50);
        Keyboard.release('S');
        break;
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  bool switchState = digitalRead(SWITCH_PIN);

  if (!switchState) {
    cameraMode = !cameraMode;
    delay(250);
  }

  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  command = COMMAND_NO;

  if (xValue < LEFT_THRESHOLD)
    command = command | COMMAND_LEFT;
  else if (xValue > RIGHT_THRESHOLD)
    command = command | COMMAND_RIGHT;

  if (xValue < LEFTUP_THRESHOLD)
    command = command | COMMAND_LEFTUP;
  else if (xValue > RIGHTUP_THRESHOLD)
    command = command | COMMAND_RIGHTUP;

  if (xValue < LEFTDOWN_THRESHOLD)
    command = command | COMMAND_LEFTDOWN;
  else if (xValue > RIGHTDOWN_THRESHOLD)
    command = command | COMMAND_RIGHTDOWN;

  if (yValue < UP_THRESHOLD)
    command = command | COMMAND_UP;
  else if (yValue > DOWN_THRESHOLD)
    command = command | COMMAND_DOWN;

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print("\tY: ");
  Serial.print(yValue);
  Serial.print("\tCommand: ");
  Serial.println(command, HEX);

  if (command != COMMAND_NO) {
    performGameAction(command);
  }
}
