#define button 3
#define pot A2
// define button and potentiometer pins
void setup(){
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}
int lastPotState = 0;
int lastButtonState = 0;
void loop(){
  int buttonState = digitalRead(button);
  if (buttonState == LOW and lastButtonState != buttonState){
    Serial.println("PRESSED");
    lastButtonState = buttonState;
  }
  else if (lastButtonState != buttonState){
    Serial.println("NOT");
    lastButtonState = buttonState;
  }
  
  int potState = analogRead(pot);
  if (potState != lastPotState and potState != (lastPotState + 1) and potState != (lastPotState - 1)) {
    Serial.println(potState);
    lastPotState = potState;
  }
}
