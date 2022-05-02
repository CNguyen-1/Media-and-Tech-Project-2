/*
 AET Little Mermaid Enclosure
 Team Name: Floundering Flounders
 Team Members: Airi Hibler, Bianca Jimenez, Christine Nguyen 
 Description: button and servo program
 */
 
#include<Servo.h>
 
//VARIABLES 
////servos
Servo ursulaServo;
Servo whirlServo;
Servo armServo;
////Pin numbers
const int ursulaSwitch = 7; 
const int tridentSwitch = 6;
const int whirlButton = 5;
const int boatSwitch = 4;
const int armSwitch = 3;
const int tridentLED = 13; 

const int ursulaRedLED = 12;
const int ursulaYellowLED = 8;
const int ursulaGreenLED = 2;

int ursulaHealthCounter = 0;
int targetVALUE;
int prevTargetVALUE = 0;

//testing
bool testUrsula = true;
unsigned long armPreviousMillis = 0;
unsigned long armCurrentMillis;
unsigned long whirlPreviousMillis = 0;
unsigned long whirlCurrentMillis;
const long interval = 500;
 
void setup() {
  Serial.begin(9600);
  
  ursulaServo.attach(11); 
  whirlServo.attach(10);
  armServo.attach(9);
  ursulaServo.write(0);
  whirlServo.write(0);
  armServo.write(0);
 
  //inputs
  pinMode(ursulaSwitch, INPUT);
  pinMode(whirlButton, INPUT);
  pinMode(tridentSwitch, INPUT); 
  pinMode(boatSwitch, INPUT);
  pinMode(armSwitch, INPUT);
 
  //led outputs
  pinMode(tridentLED, OUTPUT);
  pinMode(ursulaRedLED, OUTPUT);
  pinMode(ursulaYellowLED, OUTPUT);
  pinMode(ursulaGreenLED, OUTPUT);
  
  //Ursula health bar
  int ursulaHealthCounter = 0;
  digitalWrite(ursulaRedLED, HIGH);
  digitalWrite(ursulaYellowLED, HIGH);
  digitalWrite(ursulaGreenLED, HIGH);
  digitalWrite(tridentLED, LOW);
}
 
void loop() {
  
  ursulaFlip(); //1
  whirlPool(); //2
  trident(); //3
  boatKillsUrsula(); //4
  arielWaving(); //5

}


//1. Ariel and Eric switch activating servo to reveal transformed Ursula
void ursulaFlip(){
  if (digitalRead(ursulaSwitch) == HIGH) {
  //if (testUrsula == true) {//just here to test in tinkercad
    ursulaServo.write(180);
  } else {
    ursulaServo.write(0);
  }
}

void whirlPool(){
    if (digitalRead(whirlButton) == HIGH) {
      unsigned long whirlCurrentMillis = millis();
      if (whirlCurrentMillis - whirlPreviousMillis >= interval + 700){
        if (whirlServo.read() == 0){
          whirlServo.write(180);
        }else{
          whirlServo.write(0);
        }
        whirlPreviousMillis = whirlCurrentMillis;
      }
    }
  }



//3. Trident switch activates LED
void trident(){
  if(digitalRead(tridentSwitch) == HIGH){  
    digitalWrite(tridentLED, HIGH);
  } else {
    digitalWrite(tridentLED, LOW);
  }
}

//4. Boat switch activates blinking LED //maybe have lives and at end plays piezo?
void boatKillsUrsula(){
    targetVALUE = digitalRead(boatSwitch);
    if(targetVALUE != prevTargetVALUE){
      if (targetVALUE == HIGH) {
        ursulaHealthCounter ++;
        if (ursulaHealthCounter  == 1){
          digitalWrite(ursulaGreenLED, LOW);
        }
        else if (ursulaHealthCounter  == 2){
          digitalWrite(ursulaYellowLED, LOW);
        }
        else if (ursulaHealthCounter  >= 3){
          digitalWrite(ursulaRedLED, LOW);
        }
      }
      prevTargetVALUE = targetVALUE;
    }
  }


//5. Cake switch activates Ariel's waving
void arielWaving(){
  if (digitalRead(armSwitch) == HIGH) {
    unsigned long armCurrentMillis = millis();
    if (armCurrentMillis - armPreviousMillis >= interval){
      if (armServo.read() == 0){
        armServo.write(180);
      }else{
        armServo.write(0);
      }
      armPreviousMillis = armCurrentMillis;
    }
  }
}
