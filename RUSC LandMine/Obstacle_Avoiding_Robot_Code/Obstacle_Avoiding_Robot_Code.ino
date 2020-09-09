
#include <AFMotor.h> 
#include <Servo.h>    
#include <NewPing.h>

const int trig = 4;
const int echo = 7;
const int leftForward = 3;
const int leftBackward = 5;
const int rightForward = 6;
const int rightBackward = 11;

int duration = 0;
int m_distance = 0;
int l_distance =0;
int r_distance_0;
Servo myservo1;
Servo myservo2;

void setup() 
{
  myservo1.attach(10);
  myservo1.write(0);
  delay(1000);
  myservo2.attach(10);
  myservo1.write(0);
  delay(1000);
  
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  
  Serial.begin(9600);

}

void loop()
{
  myservo1.attach(10);
  myservo1.write(0);
  delay(1000);
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  m_distance = (duration/2) / 28.5 ;
  Serial.println(m_distance);
  

  if ( m_distance < 20 )
  {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    delay(100);
  }
  else
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
  }
 
}


