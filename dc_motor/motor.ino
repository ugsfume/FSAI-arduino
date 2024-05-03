
void setup() {
  // Set the motor pin as an output
  pinMode(10, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);              // read the value from the analog input
  Serial.println(sensorValue);

  int pwmRatio = map(sensorValue, 0, 1023, 0, 255); // map it to a range of 0 to 255
  // Write the PWM signal to the motor pin
  analogWrite(10, pwmRatio);
   int percentage = map(pwmRatio, 0, 255, 0, 100);
  // Print the percentage to the Serial Monitor
  Serial.print("PMW percentage: ");
  Serial.println(percentage);
  delay(500); // waits for the servo to get there
}
