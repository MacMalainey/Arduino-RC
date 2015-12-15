#include <Servo.h>

#include <Stepper.h>

#include <Wire.h>
const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int servoPin = 13;
Servo myServo;

// for your motor
void setup() {
  // put your setup code here, to run once:
    Wire.begin(8);
    myServo.attach(servoPin);
    Serial.begin(9600);
    Wire.onReceive(Controller);
}
int A = 0;
int B = 0;
int C = 0;
int D = 0;
int TURN = 0;
bool GAS = false;

void loop() {
  // put your main code here, to run repeatedly:
	myStepper.step(stepsPerRevolution/100);
}
void Controller(int numBytes){
	Serial.println("RECEIVED");
	while(Wire.available()){
		int test = Wire.read();
		if (test == 72){
			myStepper.setSpeed(10);
		}
		else if (test == 76){
			myStepper.setSpeed(0);
		}
		else{
			TURN = test;
			TURN = TURN / 3;
			if (TURN <= 3){
				TURN = 4;
			}
			Serial.println(TURN);
			myServo.write(TURN);
		}
	}


}
