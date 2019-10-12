#include "CPutil.h"
//Nayana Tiwari Team 3
  const int leftMotorPin1 = 7;
  const int leftMotorPin2 = 6;
  const int rightMotorPin1 = 5;
  const int rightMotorPin2 = 4;
  const int ledPin = 30;
  const int ledRedPin = 52;
  const int buttonPin = 11;
  Led led(ledPin);
  Led redLed(ledRedPin);
  Button button(buttonPin);


  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  digitalWrite(30, LOW);
  digitalWrite(32, LOW);
  digitalWrite(34, LOW);
  digitalWrite(36, LOW);
  digitalWrite(36, LOW);
  motorsSetup();
  delay(500);
  Serial.print("we r in bois"); 



}

void loop() {
  // put your main code here, to run repeatedly:

   if (sloHacks())
    {}
    delay(500);
    
}

int sloHacks()
{ 
  int state = 0;
  int returnValue = false;
  while (Serial.available()>0)
  {
    state = Serial.parseInt();
    Serial.flush();
    Serial.print(state);
   if (state < 9 && state > 0)
   {

     if (state == 1)
     {
      leftMotorForward(150);
      rightMotorForward(150);
      delay(1000);
      robotStop();
      returnValue = true;
     
     }      
  
     else if (state == 2)
     {
      leftMotorBackward(150);
      rightMotorBackward(150);
      delay(1000);
      robotStop();
      returnValue = true;
     }
  
     else if (state == 3)
     {
        motorControl(rightMotorPin1, rightMotorPin2, 180);
        delay(850);
        robotStop();
        returnValue = true;
     }
  
     else if (state == 4)
     {
      motorControl(leftMotorPin1,leftMotorPin2, 180);
      delay(800);
      robotStop();
      returnValue = true;
     }
  
     else if (state ==  5)
     {
        if (dance())
        {
          redLed.off();
          returnValue = true;
        }
     }
      
     else if (state == 7)
     {
        if (error())
        {
          redLed.off();
          returnValue = true;
        }
     }
  
     else if (state == 6)
     {
      robotStop();
      returnValue = true;
     }
  
     else if (state == 8)
     {
      if (startup())
        {
          redLed.off();
        }
     }
     returnValue = true;
   }



  }
 return returnValue;
}

int dance()
{
  int value = false;
  for (int i = 0; i < 4; i++)
  {
    int value = false;
    rightMotorForward(100);
    leftMotorBackward(100);
          
    for(int i = 30; i <= 38; i+=2)
    {
      digitalWrite(i,HIGH);
      delay(200);
      digitalWrite(i, LOW);
    }
   robotStop();
  }
  
  value = true;
  return value;
}


int startup()
{
  int returnValue = false;
  led.on();
  delay(500);
  led.off();

  rightMotorForward(100);
  leftMotorBackward(100);
  delay(800);

  leftMotorForward(100);
  rightMotorBackward(100);
  delay(850);
  
  robotStop();
  returnValue = true;
  return returnValue;
}

int error()
{
  int returnValue = false;
  for(int i = 0; i < 6; i++)
  {
    redLed.on();
    delay(200);
    redLed.off();
    delay(200);
    i++;
  }
  returnValue = true;
  return returnValue;
}

/*

int drivingControl()
{
 enum {START,FORWARD1,RIGHT,FORWARD2,LEFT,BACKWARD,SPIN,STOP};
 static int state = START;
 int returnValue = false;
 switch(state)
 {
  case START:
    if (button.wasPushed())
    {
      state = FORWARD1;                                                                                                                                                                                                  
    }
  break;
  
  case FORWARD1:
    if (robotForward(100,3000))
    {
      state = RIGHT;
    }
  break;

  case RIGHT:
    if (robotRight(1500))
    {
    state=FORWARD2;
    }
  break;

  case FORWARD2:
    if (robotForward(100,5000))
    {
      state = LEFT;
    }
  break;

  case LEFT:
    if (robotLeft(2000))
    {
      state = BACKWARD;
    }
  break;
  
  case BACKWARD:
    if (robotBackward(100,1000))
    {
      state = SPIN;
    }
  break;

  case SPIN:
    if(robotSpin(700))
    {
      state = STOP;
    }
  break;

  case STOP:
    robotStop();
    returnValue = true;
    state = START;
  break;
 } 
 return returnValue;
}

int robotSpin(int spinTime)
{
  enum {START,STOP};
  static MSTimer timer = 0;
  int returnValue = false;
  static int state = START;
  switch(state)
  {
    case START:
      timer.set(spinTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
      if (timer.done())
      {
        robotStop();
        returnValue= true;
        state = START;
      }
    else
      {
        rightMotorForward(100);
        leftMotorBackward(100);
      }
    break;
  }
  return returnValue;
}

int robotRight(int turnTime)
{
  enum {START,STOP};
  static MSTimer timer = 0;
  int returnValue = false;
  static int state = START;
  switch(state)
  {
    case START:
      timer.set(turnTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
      if (timer.done())
      {
        robotStop();
        returnValue= true;
        state = START;
      }
      else
      { 
        rightTurn(100);
      }
    break;
  }
  return returnValue;
}
int robotLeft(int turnTime)
{
  enum {START,STOP};
  static MSTimer timer = 0;
  int returnValue = false;
  static int state = START;
  switch(state)
  {
    case START:
      timer.set(turnTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
      if (timer.done())
      {
        robotStop();
        returnValue= true;
        state = START;
      }
      else
      {
        leftTurn(100);
      }
    break;
  }
  return returnValue;
}
int robotBackward(int aSpeed, int driveTime)
{
  static MSTimer timer = 0;
  int returnValue = false;
  enum {START,STOP};
  static int state = START;
  switch(state)
  {
    case START:
      timer.set(driveTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
      if (timer.done())
      {
        robotStop();
        returnValue = true;
        state = START;
      }
      else
      {
        leftMotorBackward(aSpeed);
        rightMotorBackward(aSpeed);
      }
    break;
  }
  return returnValue;
}
int robotForward(int aSpeed, int driveTime)
{
  static MSTimer timer;
  int returnValue = false;
  enum {START,STOP};
  static int state = START;
  switch(state)
  {
    case START:
      timer.set(driveTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
      if (timer.done())
      {
        robotStop();
        returnValue = true;
        Serial.print("true");
        state = START;
      }
    else
      { 
        leftMotorForward(aSpeed);
        rightMotorForward(aSpeed);
      }
    break;
  }
  return returnValue;
}*/

void robotStop()
{
  rightMotorStop();
  leftMotorStop();
}
/*
void rightTurn(int aSpeed)
{
  rightMotorStop();
  leftMotorForward(aSpeed);
}

void leftTurn(int aSpeed)
{
  leftMotorStop();
  rightMotorForward(aSpeed);
}
*/
void rightMotorStop()
{
  motorControl(rightMotorPin1, rightMotorPin2, 0);
}

void leftMotorStop()
{
  motorControl(leftMotorPin1, leftMotorPin2, 0);
}

void rightMotorBackward(int aSpeed)
{
  motorControl(rightMotorPin2, rightMotorPin1, aSpeed);
}

void leftMotorBackward(int aSpeed)
{
  motorControl(leftMotorPin2, leftMotorPin1, aSpeed);
}

void rightMotorForward(int aSpeed)
{
  motorControl(rightMotorPin1,rightMotorPin2, aSpeed);
}

void leftMotorForward(int aSpeed)
{
  motorControl(leftMotorPin1,leftMotorPin2, aSpeed);
}

void motorControl(int pin1, int pin2, int aSpeed)
{
  analogWrite(pin1,aSpeed);
  analogWrite(pin2,0);
}

void motorsSetup()
{
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2,OUTPUT);
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  robotStop();
}
