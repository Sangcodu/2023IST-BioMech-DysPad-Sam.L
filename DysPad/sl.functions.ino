#include <Mouse.h>
#include <Keyboard.h>

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SWITCH_PIN 2 // Arduino pin connected to the switch

#define LEFT_THRESHOLD  400
#define RIGHT_THRESHOLD 800
#define UP_THRESHOLD    400
#define DOWN_THRESHOLD  800

#define COMMAND_NO     0x00
#define COMMAND_LEFT   0x01
#define COMMAND_RIGHT  0x02
#define COMMAND_UP     0x04
#define COMMAND_DOWN   0x08

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int command = COMMAND_NO;
bool cameraMode = false; // Variable to track the camera mode

void performGameAction(int action) {
  // Add code here to perform game actions based on the command
  if (cameraMode) {
    // Camera direction movement
    switch (action) {
      case COMMAND_LEFT:
        Serial.println("Camera LEFT");
        // Implement camera movement to the left
        Mouse.move(-10, 0); // Mouse cursor move to the left 10 pixels
        break;
      case COMMAND_RIGHT:
        Serial.println("Camera RIGHT");
        // Implement camera movement to the right
        Mouse.move(10, 0); // Mouse cursor move to the right 10 pixels
        break;
      case COMMAND_UP:
        Serial.println("Camera UP");
        // Implement camera movement upwards
        Mouse.move(0, -10); // Mouse cursor move up 10 pixels
        break;
      case COMMAND_DOWN:
        Serial.println("Camera DOWN");
        // Implement camera movement downwards
        Mouse.move(0, 10); // Mouse cursor move down 10 pixels
        break;
      // Add more cases for other commands if needed
    }
  } else {
    // Normal joystick movement
    switch (action) {
      case COMMAND_LEFT:
        Serial.println("Character LEFT");
        // Implement character movement to the left
        Keyboard.press('A'); // Simulate pressing the 'A' key
        delay(50); // Add a small delay to hold the key
        Keyboard.release('A'); // Release the 'A' key
        break;
      case COMMAND_RIGHT:
        Serial.println("Character RIGHT");
        // Implement character movement to the right
        Keyboard.press('D'); // Simulate pressing the 'D' key
        delay(50); // Add a small delay to hold the key
        Keyboard.release('D'); // Release the 'D' key
        break;
      case COMMAND_UP:
        Serial.println("Character UP");
        // Implement character movement upwards
        Keyboard.press('W'); // Simulate pressing the 'W' key
        delay(50); // Add a small delay to hold the key
        Keyboard.release('W'); // Release the 'W' key
        break;
      case COMMAND_DOWN:
        Serial.println("Character DOWN");
        // Implement character movement downwards
        Keyboard.press('S'); // Simulate pressing the 'S' key
        delay(50); // Add a small delay to hold the key
        Keyboard.release('S'); // Release the 'S' key
        break;
      // Add more cases for other commands if needed
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Set the switch pin as an input with an internal pull-up resistor
}

void loop() {
  // Read the state of the switch
  bool switchState = digitalRead(SWITCH_PIN);

  // If the switch is pressed, toggle the camera mode
  if (!switchState) {
    cameraMode = !cameraMode;
    delay(250); // Add a small delay to debounce the switch
  }

  // Read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // Converts the analog value to commands
  // Reset commands
  command = COMMAND_NO;

  // Check left/right commands
  if (xValue < LEFT_THRESHOLD)
    command = command | COMMAND_LEFT;
  else if (xValue > RIGHT_THRESHOLD)
    command = command | COMMAND_RIGHT;

  // Check up/down commands
  if (yValue < UP_THRESHOLD)
    command = command | COMMAND_UP;
  else if (yValue > DOWN_THRESHOLD)
    command = command | COMMAND_DOWN;

  // Print command to serial and process command
  if (command & COMMAND_LEFT) {
    Serial.println("COMMAND LEFT");
    performGameAction(COMMAND_LEFT);
  }

  if (command & COMMAND_RIGHT) {
    Serial.println("COMMAND RIGHT");
    performGameAction(COMMAND_RIGHT);
  }

  if (command & COMMAND_UP) {
    Serial.println("COMMAND UP");
    performGameAction(COMMAND_UP);
  }

  if (command & COMMAND_DOWN) {
    Serial.println("COMMAND DOWN");
    performGameAction(COMMAND_DOWN);
  }
}
