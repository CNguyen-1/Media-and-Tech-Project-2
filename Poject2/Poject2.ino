/*
 AET Little Mermaid Enclosure
 Team Name: Floundering Flounders
 Team Members: Airi Hibler, Bianca Jimenez, Christine Nguyen 
 Description: button and servo program
 */

#include<Servo.h>

//VARIABLES 
//servos
Servo ursulaServo;
Servo whirlServo;
Servo armServo;

//variables (values may be changed for final build assembly)
//Pin numbers
const int ursulaSwitch = 7; 
const int tridentSwitch = 6;
const int whirlButton = 5;
const int boatSwitch = 4;
const int armSwitch = 3;
const int tridentLED = 13; 
const int boatLED = 12;

int buttonState = LOW;
int ledState = LOW;
unsigned long previousMillis = 0;   
const long interval = 1000; 


void setup() {
  ursulaServo.attach(11); //pins for servos may be changed for final build assembly
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
  pinMode(boatLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  unsigned long currentMillis = millis();

  //Project interactions
  //1. Ariel and Eric switch activating servo to reveal transformed Ursula
    if(digitalRead(ursulaSwitch) == HIGH){
    ursulaServo.write(180);
    
  } else {
    ursulaServo.write(0);
  }

  //2. Whirlpool spinning activated by button
  buttonState = digitalRead(whirlButton); 
  Serial.print("buttonState: ");
  Serial.println(buttonState);
  if(buttonState == HIGH){
    whirlServo.write(180);
   
  } else {
    whirlServo.write(0);
  }

if (currentMillis - previousMillis >= interval) {
  
    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(tridentLED, ledState);
  }
  //3. Trident switch activates LED
  if(digitalRead(tridentSwitch) == HIGH){
    digitalWrite(tridentLED, HIGH);
  } else {
    digitalWrite(tridentLED, LOW);
  }

  //4. Boat switch activates blinking LED
  if(digitalRead(boatSwitch) == HIGH){
    digitalWrite(boatLED, HIGH);
                                  
    digitalWrite(boatLED, LOW);
  }

  //5. Arm switch (cake object) activates servo on Ariel's arm to have it wave
  if(digitalRead(armSwitch) == HIGH){
    armServo.write(90); 
 
  } else {
    armServo.write(0);
  }
}
