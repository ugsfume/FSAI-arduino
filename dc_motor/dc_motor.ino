#include <Servo.h>

Servo myservo;
int motorValue = 0; // Initial motor value

void setup() {
  myservo.attach(10);
  Serial.begin(9600);
  Serial.println("Motor control initialized. Send values between 0 and 1000.");
}

void loop() {
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n'); // Read the incoming data as a string until newline
    inputString.trim(); // Trim whitespace and newline characters

    if (inputString.length() > 0) { // Check if the string is not empty
      int newMotorValue = inputString.toInt(); // Convert string to integer
      if (newMotorValue > 0 || inputString == "0") { // Check if the value is greater than 0 or exactly "0"
        motorValue = newMotorValue;
        int angle = map(motorValue, 0, 1000, 0, 180);
        myservo.write(angle);
        Serial.print("Value received: ");
        Serial.print(motorValue);
        Serial.print(", Angle set to: ");
        Serial.println(angle);
      }
    }
  }
  delay(15); // Short delay to allow servo to move
}
