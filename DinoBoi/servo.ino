#include <Servo.h>

 

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;

// twelve servo objects can be created on most boards

 

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;

 

void setup() {

  myservo1.attach(8);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(8);
  myservo3.attach(7);
  myservo4.attach(7);

}

void forward() {

  for (pos1 = 0, pos2 = 0; pos1 <= 360, pos2 >= -360; pos1 += 1, pos2 -= 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos1); 
    myservo3.write(pos2);
    myservo4.write(pos2);

    delay(15);                       // waits 15ms for the servo to reach the position
  
  }
  
}

void backward() {

  for (pos1 = 0, pos2 = 0; pos1 <= 360, pos2 >= -360; pos1 += 1, pos2 -= 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo1.write(pos2);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos2); 
    myservo3.write(pos1);
    myservo4.write(pos1);

    delay(15);                       // waits 15ms for the servo to reach the position
  
  }
  
}

void turnRight() {

  for (pos1 = 0, pos2 = 0; pos1 <= 90, pos2 >= -90; pos1 += 1, pos2 -= 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos1); 
    myservo3.write(pos1);
    myservo4.write(pos1);

    delay(15);                       // waits 15ms for the servo to reach the position
  
  }
  
}

void turnLeft() {
  
    for (pos1 = 0, pos2 = 0; pos1 <= 90, pos2 >= -90; pos1 += 1, pos2 -= 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo1.write(pos2);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos2); 
    myservo3.write(pos2);
    myservo4.write(pos2);

    delay(15);                       // waits 15ms for the servo to reach the position
  
  } 
  
}

 

void loop() {

  forward();

  delay(1000);

  backward();

  delay(1000);

  turnRight();

  delay(1000);

  turnLeft();

  delay(1000);
}
