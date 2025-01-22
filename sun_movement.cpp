#include <Servo.h>

// Initialize the servo motor
Servo mylarServo;

// Define LDR pins
const int ldrLeft = A0;  // Left LDR pin
const int ldrRight = A1; // Right LDR pin

// Servo position variables
int servoPos = 90; // Start at the middle position
const int servoMin = 0;   // Minimum servo angle
const int servoMax = 180; // Maximum servo angle

// Threshold for detecting sunlight difference
const int threshold = 20;

void setup() {
  // Attach the servo to pin 9
  mylarServo.attach(9);
  // Set the initial position of the servo
  mylarServo.write(servoPos);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the LDR values
  int leftLDR = analogRead(ldrLeft);  // Read left LDR value
  int rightLDR = analogRead(ldrRight); // Read right LDR value

  // Print LDR values for debugging
  Serial.print("Left LDR: ");
  Serial.print(leftLDR);
  Serial.print(" | Right LDR: ");
  Serial.println(rightLDR);

  // Compare LDR values and adjust servo
  if (abs(leftLDR - rightLDR) > threshold) {
    if (leftLDR > rightLDR && servoPos < servoMax) {
      servoPos += 1; // Move servo right
    } else if (rightLDR > leftLDR && servoPos > servoMin) {
      servoPos -= 1; // Move servo left
    }
  }

  // Update servo position
  mylarServo.write(servoPos);

  // Delay for smooth movement
  delay(50);
}
