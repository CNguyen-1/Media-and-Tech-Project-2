/*
 AET Little Mermaid Enclosure
 Team Name: Floundering Flounders
 Team Members: Airi Hibler, Bianca Jimenez, Christine Nguyen 
 Description: button and servo program
 */

#include<Servo.h>;

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



void setup() {
  ursulaServo.attach(11); //pins for servos may be changed for final build assembly
  whirlServo.attach(10);
  armServo.attach(9);

  //inputs
  pinMode(ursulaSwitch, INPUT);
  pinMode(whirlButton, INPUT);
  pinMode(tridentSwitch, INPUT); 
  pinMode(boatSwitch, INPUT);
  pinMode(armSwitch, INPUT);

  //led outputs
  pinMode(tridentLED, OUTPUT);
  pinMode(boatLED, OUTPUT);
  
}

void loop() {

  //Project interactions
  //1. Ariel and Eric switch activating servo to reveal transformed Ursula
    if(digitalRead(ursulaSwitch) == HIGH){
    ursulaServo.write(180);
  } else {
    ursulaServo.write(0);
  }

  //2. Whirlpool spinning activated by button
  if(digitalRead(whirlButton) == HIGH){
    whirlServo.write(360);
    delay(1200);
    whirlServo.write(0);
    delay(1200);
  } else {
    whirlServo.write(0);
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
    delay(500);                                 //delay time may need to be changed to get desired effect
    digitalWrite(boatLED, LOW);
    delay(500);
  } else {
    digitalWrite(boatLED, LOW);
  }

  //5. Arm switch (cake object) activates servo on Ariel's arm to have it wave
  if(digitalRead(armSwitch) == HIGH){
    armServo.write(90); 
    delay(500);
    armServo.write(0);
    delay(500);
  } else {
    armServo.write(0);
  }
}
