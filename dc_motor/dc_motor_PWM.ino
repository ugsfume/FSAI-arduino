#include <Servo.h>

Servo myservo;
int motorValue = 0; // Initial motor value

void setup() {
  myservo.attach(10);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);              // read the value from the analog input
  Serial.println(sensorValue);

  int ratio = map(sensorValue, 0, 1023, 0, 180); // map it to a range of 0 to 180
  // AnalogRead = 513 is when the car is moving at controllable speed
  myservo.write(ratio); // sets the servo position according to the scaled value
  
  int percentage = map(ratio, 0, 180, 0, 100);
  // Print the percentage to the Serial Monitor
  Serial.print("PMW percentage: ");
  Serial.println(percentage);
  
  delay(500); // waits for the servo to get there
}
