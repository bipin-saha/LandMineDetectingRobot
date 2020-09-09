#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>

#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 3000
#define MAX_SPEED 200
#define MAX_SPEED_OFFSET 40
#define COLL_DIST 10
#define TURN_DIST COLL_DIST+20

NewPing sonar (TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor leftMotor1 (1, MOTOR12_1KHZ);
AF_DCMotor leftMotor2 (2, MOTOR12_1KHZ);
AF_DCMotor rightMotor1 (3, MOTOR34_1KHZ);
AF_DCMotor rightMotor2 (4, MOTOR34_1KHZ);
Servo sonarservo;
Servo coilservo;
int leftDistance, rightDistance;
int curDist = 0;
String motorSet = "";
int speedSet = 0;
int Flag = 0;

void setup ()
{
  sonarservo.attach(10);
  coilservo.attach(9);
  sonarservo.write(90);
  coilservo.write(90);
  delay (1000);
}

void loop ()
{
  sonarservo.write(90);
  delay(90);
  curDist = readPing ();
  if (curDist > COLL_DIST)
  {
  moveStop ();
  coilservo.write(30);
  delay(300);
  coilservo.write(35);
  delay(300);
  coilservo.write(40);
  delay(300);
  coilservo.write(45);
  delay(300);
  coilservo.write(50);
  delay(300);
  coilservo.write(55);
  delay(300);
  coilservo.write(60);
  delay(300);
  coilservo.write(65);
  delay(300);
  coilservo.write(70);
  delay(300);
  coilservo.write(75);
  delay(300);
  coilservo.write(80);
  delay(300);
  coilservo.write(85);
  delay(300);
  coilservo.write(90);
  delay(300);
  coilservo.write(95);
  delay(300);
  coilservo.write(100);
  delay(300);
  coilservo.write(105);
  delay(300);
  coilservo.write(110);
  delay(300);
  coilservo.write(115);
  delay(300);
  coilservo.write(120);
  delay(300);
  coilservo.write(125);
  delay(300);
  coilservo.write(130);
  delay(300);
  coilservo.write(135);
  delay(300);
  coilservo.write(140);
  delay(300);
  coilservo.write(145);
  delay(300);
  coilservo.write(150);
  delay(300);
  coilservo.write(145);
  delay(300);
  coilservo.write(140);
  delay(300);
  coilservo.write(135);
  delay(300);
  coilservo.write(130);
  delay(300);
  coilservo.write(125);
  delay(300);
  coilservo.write(120);
  delay(300);
  coilservo.write(115);
  delay(300);
  coilservo.write(110);
  delay(300);
  coilservo.write(105);
  delay(300);
  coilservo.write(100);
  delay(300);
  coilservo.write(95);
  delay(300);
  coilservo.write(90);
  delay(300);
  coilservo.write(85);
  delay(300);
  coilservo.write(80);
  delay(300);
  coilservo.write(75);
  delay(300);
  coilservo.write(70);
  delay(300);
  coilservo.write(65);
  delay(300);
  coilservo.write(60);
  delay(300);
  coilservo.write(55);
  delay(300);
  coilservo.write(50);
  delay(300);
  coilservo.write(45);
  delay(300);
  coilservo.write(40);
  delay(300);
  coilservo.write(35);
  delay(300);
  coilservo.write(30);
  delay(300);
  }
  else if (curDist < COLL_DIST)
  {
    changePatch ();
    
  }
  moveForward();
  delay(2000);
}

void changePatch()
{
  moveStop ();
  sonarservo.write(36);
  delay(500);
  rightDistance = readPing ();
  delay (500);
  sonarservo.write(144);
  delay (500);
  leftDistance = readPing ();
  delay (500);
  sonarservo.write(90);
  delay(500);
  compareDistance();
}

void compareDistance()
{
  if(leftDistance>rightDistance)
  {
    turnLeft();
  }
  else if (rightDistance>leftDistance)
  {
    turnRight();
  }
  else
  {
    turnAround();
  }
}

int readPing ()
{
  delay(70);
  unsigned int uS = sonar.ping();
  int cm = uS/US_ROUNDTRIP_CM;
  return cm;
}

void moveStop()
{
  leftMotor1.run(RELEASE);
  leftMotor2.run(RELEASE);
  rightMotor1.run(RELEASE);
  rightMotor2.run(RELEASE);
}

void moveForward()
{
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2)
  {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet);
    rightMotor2.setSpeed(speedSet);
    delay (5);
  }
}

void moveBackward ()
{
  motorSet = "BACKWARD";
  leftMotor1.run(BACKWARD);
  leftMotor2.run(BACKWARD);
  rightMotor1.run(BACKWARD);
  rightMotor2.run(BACKWARD);
  delay(5);
}

void turnRight()
{
  motorSet = "RIGHT";
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(BACKWARD);
  rightMotor2.run(BACKWARD);
  rightMotor1.setSpeed(speedSet+MAX_SPEED_OFFSET);
  rightMotor2.setSpeed(speedSet+MAX_SPEED_OFFSET);
  delay(500);
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
}

void turnLeft()
{
  motorSet = "LEFT";
  leftMotor1.run(BACKWARD);
  leftMotor2.run(BACKWARD);
  leftMotor1.setSpeed(speedSet+MAX_SPEED_OFFSET);
  leftMotor2.setSpeed(speedSet+MAX_SPEED_OFFSET);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
  delay(500);
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
}

void turnAround ()
{
  motorSet = "RIGHT";
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(BACKWARD);
  rightMotor2.run(BACKWARD);
  rightMotor1.setSpeed(speedSet+MAX_SPEED_OFFSET);
  rightMotor2.setSpeed(speedSet+MAX_SPEED_OFFSET);
  delay (500);
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
  
}

