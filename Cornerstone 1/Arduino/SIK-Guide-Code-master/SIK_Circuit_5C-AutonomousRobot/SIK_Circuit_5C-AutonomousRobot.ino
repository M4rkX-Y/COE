/*
  SparkFun Inventor’s Kit
  Circuit 5C - Autonomous Robot

  This robot will drive around on its own and react to obstacles by backing up and turning to a new direction.
  This sketch was adapted from one of the activities in the SparkFun Guide to Arduino.
  Check out the rest of the book at
  https://www.sparkfun.com/products/14326

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/


const int s = 90;


//the right motor will be controlled by the motor A pins on the motor driver
const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the right motor
const int PWMA = 11;            //speed control pin on the motor driver for the right motor

//the left motor will be controlled by the motor B pins on the motor driver
const int PWMB = 10;           //speed control pin on the motor driver for the left motor
const int BIN2 = 9;           //control pin 2 on the motor driver for the left motor
const int BIN1 = 8;           //control pin 1 on the motor driver for the left motor


int switchPin = 7;             //switch to turn the robot on and off

float distance1 = 0;            //variable to store the distance measured by the distance sensor
float distance2 = 0; 


//robot behaviour variables
int backupTime = 180;           //amount of time that the robot will back up when it senses an object
int turnTime = 480;             //amount that the robot will turn once it has backed up

/********************************************************************************/
void setup()
{
  pinMode(6, OUTPUT);       //this pin will send ultrasonic pulses out from the distance sensor
  pinMode(5, INPUT);        //this pin will sense when the pulses reflect back to the distance sensor
  pinMode(4, OUTPUT);       //this pin will send ultrasonic pulses out from the distance sensor
  pinMode(3, INPUT);

  pinMode(switchPin, INPUT_PULLUP);   //set this as a pullup to sense whether the switch is flipped


  //set the motor control pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin(9600);                       //begin serial communication with the computer
  Serial.print("To infinity and beyond!");  //test the serial connection
}

/********************************************************************************/
void loop()
{
  //DETECT THE DISTANCE READ BY THE DISTANCE SENSOR
  distance1 = getDistance(6, 5);
  distance2 = getDistance(4, 3);
  
  Serial.print(distance2);
  Serial.print('\n');

  if (digitalRead(switchPin) == LOW) { //if the on switch is flipped

    if (distance1 < 5) {
      if (distance2 > 12) {//if an object is detected
      //back up and turn
      Serial.print(" ");
      Serial.print("BACK!");

      //stop for a moment
      rightMotor(0);
      leftMotor(0);
      delay(800);

      //back up
      rightMotor(-s);
      leftMotor(-s);
      delay(backupTime);
      
        rightMotor(s);
        leftMotor(-s);
        delay(turnTime);
      }
      else {
        Serial.print(" ");
      Serial.print("BACK!");

      //stop for a moment
      rightMotor(0);
      leftMotor(0);
      delay(800);
      rightMotor(-s);
      leftMotor(-s);
      delay(backupTime);
      
        rightMotor(-s);
        leftMotor(s);
        delay(turnTime);
      }
      

    } else {                        //if no obstacle is detected drive forward
      Serial.print(" ");
      Serial.print("Moving...");


      rightMotor(s);
      leftMotor(s);
    }
  } else {                        //if the switch is off then stop

    //stop the motors
    rightMotor(0);
    leftMotor(0);
  }

  delay(50);                      //wait 50 milliseconds between readings
}

/********************************************************************************/
void rightMotor(int motorSpeed)                       //function for driving the right motor
{
  if (motorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(AIN1, HIGH);                         //set pin 1 to high
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
  }
  else if (motorSpeed < 0)                            //if the motor should drive backward (negative speed)
  {
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, HIGH);                         //set pin 2 to high
  }
  else                                                //if the motor should stop
  {
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(PWMA, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
}

/********************************************************************************/
void leftMotor(int motorSpeed)                        //function for driving the left motor
{
  if (motorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(BIN1, HIGH);                         //set pin 1 to high
    digitalWrite(BIN2, LOW);                          //set pin 2 to low
  }
  else if (motorSpeed < 0)                            //if the motor should drive backward (negative speed)
  {
    digitalWrite(BIN1, LOW);                          //set pin 1 to low
    digitalWrite(BIN2, HIGH);                         //set pin 2 to high
  }
  else                                                //if the motor should stop
  {
    digitalWrite(BIN1, LOW);                          //set pin 1 to low
    digitalWrite(BIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(PWMB, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
}

/********************************************************************************/
//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance(int trigPin, int echoPin)
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
                                          //pulse to bounce back to the sensor

  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)

  return calculatedDistance;              //send back the distance that was calculated
}
