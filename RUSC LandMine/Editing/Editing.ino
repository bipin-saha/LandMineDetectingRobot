
#include <AFMotor.h> 
#include <Servo.h>    
#include <NewPing.h>

const int trig = A5;
const int echo = A4;
const int leftForward = 3;
const int leftBackward = 5;
const int rightForward = 6;
const int rightBackward = 11;

int duration = 0;
int m_distance = 0;
int l_distance =0;
int r_distance=0;
Servo myservo1;
Servo myservo2;

void setup() 
{
  myservo1.attach(10);
  myservo1.write(0);
  delay(1000);
  myservo2.attach(9);
  myservo2.write(0);
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
  // Left Distance
  
  myservo1.attach(10);
  myservo1.write(45);
  delay(1000);
  
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  
  duration = pulseIn(echo , HIGH);
  l_distance = (duration/2) / 28.5 ;
  Serial.println(l_distance);

  // Middle Distance
 
  myservo1.attach(10);
  myservo1.write(90);
  delay(1000);
  
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  
  duration = pulseIn(echo , HIGH);
  m_distance = (duration/2) / 28.5 ;
  Serial.println(m_distance);

  // Right Distance
  
  myservo1.attach(10);
  myservo1.write(135);
  delay(1000);
  
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  
  duration = pulseIn(echo , HIGH);
  r_distance = (duration/2) / 28.5 ;
  Serial.println(r_distance);

  if ( m_distance >= 100 )
  {
    digitalWrite(leftForward  , HIGH);
    digitalWrite(rightForward , HIGH);
    delay(100);
  }
  else
  {
    if (l_distance>r_distance)
    {
    digitalWrite(leftForward  , LOW);
    digitalWrite(rightForward , HIGH);
    delay(50);
    digitalWrite(leftForward  , HIGH);
    digitalWrite(rightForward , HIGH);
    
    }
    else
    {
    digitalWrite(leftForward  , HIGH);
    digitalWrite(rightForward , LOW);
    delay(50);
    digitalWrite(leftForward  , HIGH);
    digitalWrite(rightForward , HIGH);
    }
  }
 
}


