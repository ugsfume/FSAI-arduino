import rospy
from std_msgs.msg import UInt16
def angle_publisher():
    rospy.init_node('angle_publisher',anonymous=True)
    motor_publisher=rospy.Publisher('/motor_angle',UInt16,queue_size=10)
    servo_publisher=rospy.Publisher('/servo_angle',UInt16,queue_size=10)
    rate=rospy.Rate(1)
    while not rospy.is_shutdown():
        with open('motor.txt','r') as file:
            for line in file:
                motor_angle=int(line.strip())
                motor_publisher.publish(motor_angle)
                rate.sleep
        with open('servo.txt','r') as file:
            for line in file:
                servo_angle=int(line.strip())
                servo_publisher.publish(servo_angle)
                rate.sleep() 
    motor_publisher.publish(30)
    servo_publisher.publish(25)

if __name__=='__main__':
    try:
        angle_publisher()
    except rospy.ROSInterruptException:
        pass
