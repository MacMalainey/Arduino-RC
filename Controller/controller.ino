#include <Wire.h>


#define button 3
#define pot A2
// define button and potentiometer pins
void setup(){
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  Wire.begin();
}
int lastPotState = 0;
int lastButtonState = 0;
void loop(){
  int buttonState = digitalRead(button);
  if (buttonState == LOW and lastButtonState != buttonState){
    Serial.println("PRESSED");
    lastButtonState = buttonState;
    Wire.beginTransmission(8);
    Wire.write("H");
    Wire.endTransmission();
  }
  else if (lastButtonState != buttonState){
    Serial.println("NOT");
    Wire.beginTransmission(8);
    Wire.write("L");
    Wire.endTransmission();
    lastButtonState = buttonState;
  }
  
  int potState = analogRead(pot);
  potState = potState / 8;
  if (potState != lastPotState and potState != (lastPotState + 1) and potState != (lastPotState - 1)) {
    if (potState == 72 or potState == 76){
        potState++;
    }
    Serial.println(potState);
    lastPotState = potState;
    Wire.beginTransmission(8);
    Wire.write(potState);
    Wire.endTransmission();
  }
}
