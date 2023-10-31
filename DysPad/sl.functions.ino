#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

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

void setup() {
  Serial.begin(9600);
}

void performGameAction(int action) {
  // Add code here to perform game actions based on the command
  switch (action) {
    case COMMAND_LEFT:
      Serial.println("Performing LEFT action");
      // Implement the left movement in your game
      break;
    case COMMAND_RIGHT:
      Serial.println("Performing RIGHT action");
      // Implement the right movement in your game
      break;
    case COMMAND_UP:
      Serial.println("Performing UP action");
      // Implement the up movement in your game
      break;
    case COMMAND_DOWN:
      Serial.println("Performing DOWN action");
      // Implement the down movement in your game
      break;
    // Add more cases for other commands if needed
  }
}

void loop() {
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

