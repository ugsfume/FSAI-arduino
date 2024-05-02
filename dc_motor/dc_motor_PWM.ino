#include <Servo.h>

Servo myservo;
int motorValue = 0; // Initial motor value

void setup() {
  myservo.attach(10);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);              // read the value from the analog input
  int ratio = map(sensorValue, 0, 460, 0, 100); // map it to a range of 0 to 180

  myservo.write(ratio); // sets the servo position according to the scaled value
  
  // Print the percentage to the Serial Monitor
  Serial.print("PMW ratio: ");
  Serial.println(ratio);
  
  delay(15); // waits for the servo to get there
}
