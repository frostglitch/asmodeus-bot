#include <AFMotor.h>
#include <Wire.h>

AF_DCMotor motor1(1); //levi
AF_DCMotor motor2(2); //desni
AF_DCMotor motor3(3); //levi
AF_DCMotor motor4(4); //desni


int myData[3]; //0 joystick X    1 joystick Y    2 camera

int horizLine = 150;
int vertLine = 150;

int minTurnSpeed = 50;

void setup()
{
  Wire.begin();
  Serial.begin(9600);

  //-------------------

  motor1.setSpeed(255);
  motor1.run(RELEASE);

  motor2.setSpeed(255);
  motor2.run(RELEASE);
  
  motor3.setSpeed(255);
  motor3.run(RELEASE);

  motor4.setSpeed(255);
  motor4.run(RELEASE);

  myData[1] = 255;
}

void Turn(bool left)
{
  if(left)
  {
    motor1.setSpeed(255);
    motor1.run(FORWARD);
  
    motor2.setSpeed(minTurnSpeed);
    motor2.run(FORWARD);
    
    motor3.setSpeed(255);
    motor3.run(FORWARD);
  
    motor4.setSpeed(minTurnSpeed);
    motor4.run(FORWARD);
  }
  else
  {
    motor1.setSpeed(minTurnSpeed);
    motor1.run(FORWARD);
  
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    
    motor3.setSpeed(minTurnSpeed);
    motor3.run(FORWARD);
  
    motor4.setSpeed(255);
    motor4.run(FORWARD);
  }
}

void Drive(bool forward)
{
    motor1.setSpeed(abs(myData[1]));
    motor2.setSpeed(abs(myData[1]));
    motor3.setSpeed(abs(myData[1]));
    motor4.setSpeed(abs(myData[1]));
  
  if(forward)
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  else
  {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
}

void Stop()
{
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);

    motor1.setSpeed(0);
    motor2.setSpeed(0);
    motor3.setSpeed(0);
    motor4.setSpeed(0);
}

void loop()
{
  int n = Wire.requestFrom(6,6);
  if ( n == 6 )
  {
    Wire.readBytes( (byte *) myData, 6);
  }

  if(myData[0] > horizLine) Turn(false); //right
  else if(myData[0] < -horizLine) Turn(true); //left
  else //center
  {
    if(myData[1] > vertLine) Drive(true); //forward
    else if(myData[1] < -vertLine) Drive(false); //backward
    else
    {
      Stop();
    }
  }

  delay(10);
}
