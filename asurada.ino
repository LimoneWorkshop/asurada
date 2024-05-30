#include <Servo.h>
#define analogPin A0
#define LED1Pin 14
#define LED2Pin 12
#define LED3Pin 13

#define servo1Pin 2
#define servo2Pin 0

Servo servo1;
Servo servo2;

int soundVal = 0;
int sumSoundVal = 0;
int defaultSoundVal = 0;
int motionCnt = 0;

int randomNum = 0;

void setup() {
  servo1.attach(servo1Pin); //D4
  servo1.write(0);
  servo2.attach(servo2Pin); //D4
  servo2.write(0);
  pinMode(analogPin, INPUT);
  pinMode(LED1Pin, OUTPUT);
  pinMode(LED2Pin, OUTPUT);
  pinMode(LED3Pin, OUTPUT);
  digitalWrite(LED1Pin, LOW);
  digitalWrite(LED2Pin, LOW);
  digitalWrite(LED3Pin, LOW);
  Serial.begin(115200);
  delay(2000);
  for (int i = 0; i < 50; i++) {
    sumSoundVal = sumSoundVal + analogRead(analogPin);
    delay(10);
  }
  defaultSoundVal = sumSoundVal/50;
  servo1.write(140);
  delay(700);
  servo1.write(0);
}

void loop() {
  soundVal = analogRead(analogPin);
  Serial.println(soundVal);
  if(soundVal > defaultSoundVal + 50){
    digitalWrite(LED1Pin, HIGH);
    digitalWrite(LED2Pin, HIGH);
    digitalWrite(LED3Pin, HIGH);
    motionCnt = 0;
  }else if(soundVal > defaultSoundVal + 30){
    digitalWrite(LED1Pin, HIGH);
    digitalWrite(LED2Pin, HIGH);
    digitalWrite(LED3Pin, LOW);
    motionCnt = 0;
  }else if(soundVal > defaultSoundVal + 10){
    digitalWrite(LED1Pin, HIGH);
    digitalWrite(LED2Pin, LOW);
    digitalWrite(LED3Pin, LOW);
    motionCnt = 0;
  }else{
    motionCnt++;
    digitalWrite(LED1Pin, LOW);
    digitalWrite(LED2Pin, LOW);
    digitalWrite(LED3Pin, LOW);
  }
  motionCnt++;
  if(motionCnt > 200){
    randomNum = random(1, 20);
    if(randomNum > 10){
      servo1.write(140);
      delay(700);
      servo1.write(0);
    }else{
      servo2.write(100);
      delay(700);
      servo2.write(0);
    }
    motionCnt= 0;
  }
  delay(100);
}
