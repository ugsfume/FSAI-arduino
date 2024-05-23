/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo servo;
Servo motor;

void servo_cb( const std_msgs::UInt16& cmd_msg2){
  if (cmd_msg2.data>=51){
    servo.write(51);
  } else {
    servo.write(cmd_msg2.data);; //set servo angle, should be from 0-180
  }
}

void motor_cb( const std_msgs::UInt16& cmd_msg1){
  if (cmd_msg1.data<100){
  motor.write(30); //set motor angle, should be from 0-180
  } else {
  motor.write(cmd_msg1.data); //set servo angle, should be from 0-180
  }
}

ros::Subscriber<std_msgs::UInt16> sub1("motor_angle", motor_cb);
ros::Subscriber<std_msgs::UInt16> sub2("servo_angle", servo_cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  servo.write(25);
  Serial.begin(9600);
  servo.attach(10); //attach it to pin 10
  motor.attach(5);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
