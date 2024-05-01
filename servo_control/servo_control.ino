#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:
}

void loop() {
  int sensorValue = analogRead(A0);              // read the value from the analog input
  int angle = map(sensorValue, 0, 1023, 0, 180); // map it to a range of 0 to 180
  
  myservo.write(angle); // sets the servo position according to the scaled value
  
  // Calculate the percentage of the sensor value
  int percentage = map(sensorValue, 0, 1023, 0, 100);
  
  // Print the percentage to the Serial Monitor
  Serial.print("Analog Reading in Percentage: ");
  Serial.println(percentage);
  
  delay(15); // waits for the servo to get there
}
