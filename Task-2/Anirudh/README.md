**The above codes are for line following and for testing the motors using input from a stack. The mechanisms of the code has been explained using comments.**

Base-Motor Controls:

1.Driving the bot :

	Approach 1:
		X-Drive
		This plan was not executed due to lack of components for building it. We needed omni wheels, which could not meet the size specifications of out bot.

Under this plan, the movement of the bot would be controlled by four wheels which were at an angle of 45 degrees to the shaft, which itself was shaped like a cross. The bot would move in any direction as a result of the sum of the vector forces applied by the wheels. Turning would be implemented by making two adjacent wheels in the reverse direction.

The code for this approach was not written.

	Approach 2:
		Four-Wheel Drive 
		This is the current working mechanism. Similar to X-Drive, but the wheels are arranged parallel to each other, like that in a car.

The movement of the bot would be controlled by the four wheels. All the wheels would move in the same direction for the bot to move forwards or backwards. Turning can be implemented by rotating two adjacent wheels on the side of the bot that we want to turn it to, in the reverse direction as that of the other two wheels.

The wheel motors (300 rpm, 10kg.cm) are controlled using a Cytron dual acting motor driver and two single acting motor drivers.

Pins used :
31, 5 - PWM and direction pin for left motor1.
33, 5 - PWM and direction pin for left motor2.
35, 11 - PWM and direction pin for right motor2.
37, 15 - PWM and direction pin for right motor2.
6 - Ground

RPi.GPIO library was used in python 2.7
Read documentation for further details.



2.Line Following :

This documentation is written assuming that the line has been tracked by the camera and the input from the image pocessing module gives correct data.

//Read about OpenCV and Contour mapping 

Contouring using OpenCV provides us with the centroid of the shape formed by the line on the ground. For implementing this, proper camera angle and light conditions required. Check implementation with just a camera. Use VNC to test on Pi.

Image width without usig roi = 640 pixels.

The line following algorithm works such that there is a small gap of about 100 pixels. If the centroid of the line falls within this space, the bot is moving straight. If it falls on either side of the strip, it is either moving towards the right or to the left.

The input given by the camera decides the function to be executed: left, right or straight.


3 Possible Errors:
	Cleanup the Raspberry Pi pins after every code run. Garbage values given by the pins can be a huge nuisance causing improper running of the bot.

	Do not run the motors on 100. It would cause the motor to heat up and burn. 

	Check camera feed before implementing line following. Shadows and light effects can give error in reading.

4.Retracing

	For implementing retracing, we need to store the movement of the bot as it traces the line during line following phase. This data is stored in the form of a stack. Then, for retracing, the stack items are popped, so they come out in a reverse order.
