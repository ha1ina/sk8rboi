#include <SoftwareSerial.h>

// bluetooth only works with motor code commented out

const byte rxPin = 2;
const byte txPin = 3;

bool forwardVal = false;
bool backVal = false;
bool leftVal = false;
bool rightVal = false;

const int E1 = 3; ///<Motor1 Speed
const int E2 = 11;///<Motor2 Speed
const int E3 = 5; ///<Motor3 Speed
const int E4 = 2; ///<Motor4 Speed

const int M1 = 4; ///<Motor1 Direction
const int M2 = 12;///<Motor2 Direction
const int M3 = 8; ///<Motor3 Direction
const int M4 = 7; ///<Motor4 Direction

SoftwareSerial mySerial(rxPin,txPin);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
}

void stop(){
  forwardVal = false;
  backVal = false;
  rightVal = false;
  leftVal = false;
}

void M1_advance(char Speed) ///<Motor1 Advance
{
 digitalWrite(M1,LOW);
 analogWrite(E1,Speed);
}
void M2_advance(char Speed) ///<Motor2 Advance
{
 digitalWrite(M2,LOW);
 analogWrite(E2,Speed);
}
void M3_advance(char Speed) ///<Motor3 Advance
{
 digitalWrite(M3,LOW);
 analogWrite(E3,Speed);
}
void M4_advance(char Speed) ///<Motor4 Advance
{
 digitalWrite(M4,LOW);
 analogWrite(E4,Speed);
}

void M1_back(char Speed) ///<Motor1 Back off
{
 digitalWrite(M1,HIGH);
 analogWrite(E1,Speed);
}
void M2_back(char Speed) ///<Motor2 Back off
{
 digitalWrite(M2,HIGH);
 analogWrite(E2,Speed);
}
void M3_back(char Speed) ///<Motor3 Back off
{
 digitalWrite(M3,HIGH);
 analogWrite(E3,Speed);
}
void M4_back(char Speed) ///<Motor4 Back off
{
 digitalWrite(M4,HIGH);
 analogWrite(E4,Speed);
}

void backward() {
   M1_back(40);
   M2_back(40);
   M3_back(40);
   M4_back(40); 
}

void forward() {
   M1_advance(40);
   M2_advance(40);
   M3_advance(40);
   M4_advance(40); 
}
void left() {
  M1_advance(25);
  M2_advance(50);
  M3_advance(25);
  M4_advance(50); 
  
}
void right() {
  M1_advance(50);
  M2_advance(25);
  M3_advance(50);
  M4_advance(25); 
}

void stopDriving(){
    M1_advance(0);
    M2_advance(0);
    M3_advance(0);
    M4_advance(0);
}

void loop()
{
  int val;

  if (mySerial.available() > 0) {
    Serial.print("Bluetooth availability: ");
    Serial.println(mySerial.available());
    val = mySerial.read();
    Serial.print("DATA RECEIVED: ");
    Serial.println(val);

    if (val == 'F') {
      Serial.println("going forward");
      stop();
      forwardVal = true;
    }

    if (val == 'B') {
       Serial.println("going backwards");
       stop();
       backVal = true;
    }

   if (val == 'R') {
      Serial.println("going right");
      stop();
      rightVal = true;
   }

   if (val == 'L') {
      Serial.println("going left");
      stop();
      leftVal = true;
   }

   if (val == 'S'){
      Serial.println("stop");
      stop();
   }
  
  }

  if (forwardVal == true){
    //forward();
  }

  else if (backVal == true){
    //backward();
  }

  else if (rightVal == true){
    //right();
  }

  else if (leftVal == true){
    //left();
  }
  else{
    //stopDriving();
  }
  
}
