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

int xValue = 0 ; // To store value of the X axis
int yValue = 0 ; // To store value of the Y axis
int command = COMMAND_NO;
bool cameraMode = false; // Variable to track the camera mode

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Set the switch pin as an input with internal pull-up resistor
}

void performGameAction(int action) {
  // Add code here to perform game actions based on the command
  if (cameraMode) {
    // Camera direction movement
    switch (action) {
      case COMMAND_LEFT:
        Serial.println("Camera LEFT");
        // Implement camera movement to the left
        break;
      case COMMAND_RIGHT:
        Serial.println("Camera RIGHT");
        // Implement camera movement to the right
        break;
      case COMMAND_UP:
        Serial.println("Camera UP");
        // Implement camera movement upwards
        break;
      case COMMAND_DOWN:
        Serial.println("Camera DOWN");
        // Implement camera movement downwards
        break;
      // Add more cases for other commands if needed
    }
  } else {
    // Normal joystick movement
    switch (action) {
      case COMMAND_LEFT:
        Serial.println("Character LEFT");
        // Implement character movement to the left
        break;
      case COMMAND_RIGHT:
        Serial.println("Character RIGHT");
        // Implement character movement to the right
        break;
      case COMMAND_UP:
        Serial.println("Character UP");
        // Implement character movement upwards
        break;
      case COMMAND_DOWN:
        Serial.println("Character DOWN");
        // Implement character movement downwards
        break;
      // Add more cases for other commands if needed
    }
  }
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
