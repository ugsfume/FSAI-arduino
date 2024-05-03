#include <Servo.h>

int var1;
int var2;

Servo motor;
Servo steer;
int motorValue = 0; // Initial motor value
int steerValue = 0;

void setup() {
  motor.attach(10);
  steer.attach(5);
  Serial.begin(9600);
  Serial.println("Motor control initialized. Send angles for motor and steer with a space in between.");
}


void loop() {
  if (Serial.available() > 0) {
    // Read the serial input until a newline character is received
    String input = Serial.readStringUntil('\n');
    input.trim();
   
    if (input.length() > 0) { // Check if the string is not empty
     // Split the input string into two parts separated by a space
      int spaceIndex = input.indexOf(' ');
      // If a space is found, parse the two parts into integers
      if (spaceIndex != -1) {
        String val1Str = input.substring(0,spaceIndex);
        String val2Str = input.substring(spaceIndex + 1);
        
        var1 = val1Str.toInt();
        var2 = val2Str.toInt();
        if (var1<100){
          var1=25;
        }
  
        if (var2>51){
          var2=51;
        }
        motorValue=var1;
        steerValue=var2;
        motor.write(motorValue);
        steer.write(steerValue);

        // Print the received values for verification
        Serial.print("\n");
        Serial.print("Received angle for motor: ");
        Serial.print(var1);
        Serial.print("\n");
        Serial.print("Received angle for steer: ");
        Serial.print(var2);
      }
    }
  }

}
