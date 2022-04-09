/*
 AET Little Mermaid Enclosure
 Team Name: Floundering Flounders
 Team Members: Airi Hibler, Bianca Jimenez, Christine Nguyen 
 Description: button and servo program
 */

#include<Servo.h>;

//VARIABLES 
Servo ursulaServo;
Servo whirlServo;
Servo armServo;

//variables values to be assigned later;
const int ursulaSwitch = ; 
const int whirlButton = ;
const int armSwitch = ;
const int boatSwitch = ;
const int tridentSwitch = ;
const int tridentLED = ; 
const int boatLED = ;


void setup() {
  // put your setup code here, to run once:
  ursulaServo.attach(9);//might need to change numbers
  whirlServo.attach(9);
  armServo.attach(9);
  pinMode(ursulaSwitch, INPUT);
  pinMode(whirlButton, INPUT);
  pinMode(tridentSwitch, INPUT); //may change variable name
  pinMode(boatSwitch, INPUT);
  pinMode(armSwitch, INPUT);
  pinMode(tridentLED, OUTPUT);
  pinMode(boatLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if button is pressed, swivel servo 180 degrees

  //1.Ursula flipping to reveal transformed Ursula
  if(digitalRead(ursulaSwitch) == HIGH){
    ursulaServo.write(180);
  } else {
    ursulaServo.write(0);
  }

  //2.Whirlpool spinning
  if(digitalRead(whirlButton) == HIGH){
    whirlServo.write(180);
    whirlServo.write(180); //check if this gives a spinning effect
  } else {
    whirlServo.write(0);
  }

  //3.Trident activates LED
  if(digitalRead(tridentSwitch) == HIGH){
    digitalWrite(tridentLED, HIGH);
  } else {
    digitalWrite(tridentLED, LOW);
  }

  //4.Boat switch activates LEDs/LED?, maybe make it flickering
  if(digitalRead(boatSwitch == HIGH){
    digitalWrite(boatLED, HIGH);
    delay(500); //delay time may need to be changed to get desired effect
    digitalWrite(boatLED, LOW);
    delay(500)
  } else {
    digitalWrite(boatLED, LOW);
  }

  //5.Arm switch (cake object) activates servo on Ariel's arm to have it wave
  if(digitalRead(armSwitch) == HIGH){
    armServo.write(180); //check if it gives a waving effect
    armServo.write(180);
  } else {
    armServo.write(0);
  }
}
