#include <toneAC.h>//alternate tone library that gives volume functionality if use both timer 1 PWM pins

//constants for our notes. the chanter is in D Major so the frequencies supplied for F and C are actually F#/C#
const int NOTE_HIGH_A = 880;
const int NOTE_HIGH_G = 784;
const int NOTE_F = 740; //F#
const int NOTE_E = 659;
const int NOTE_D = 587;
const int NOTE_C = 554; //C#
const int NOTE_B = 494;
const int NOTE_LOW_A = 440;
const int NOTE_LOW_G = 392;
int vol;
int note;
int sensor;

void setup() {
  //initialize input pins- INPUT_PULLUP sets all pins high unless grounded on a Teensy 2.0
  Serial.begin(9600);
  pinMode(0,INPUT_PULLUP);
  pinMode(1,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
}

void loop() {
  //based on button input, determine the pitch we should play
  if(digitalRead(0) == HIGH){
    note = NOTE_HIGH_A;
  }
  else if(digitalRead(1) == HIGH){
    note = NOTE_HIGH_G;
  }
  else if(digitalRead(2) == HIGH){
    note = NOTE_F;
  }
  else if(digitalRead(3) == HIGH){
    note = NOTE_E;
  }
  else if(digitalRead(4) == HIGH){
    note = NOTE_D;
  }
  else if(digitalRead(5) == HIGH){
    note = NOTE_C;
  }
  else if(digitalRead(6) == HIGH){
    note = NOTE_B;
  }
  else if(digitalRead(7) == HIGH){
    note = NOTE_LOW_A;
  }
  else{
    note = NOTE_LOW_G; 
  }
  
  //we map our sensor values to an int from 0 to 10, which is the volume parameter toneAC() accepts
  sensor = analogRead(10);
  vol = map(sensor,55,150,0,10);
  //some volumes sound ugly, so we avoid them by going up or down
  if(vol < 3){
    vol = 0;
  }
  else if(vol == 8){
    vol = 7;
  }
  else if(vol == 9){
    vol = 10;
  }
  else if(vol > 10){
    vol = 10;
  }
  //toneAC plays the specified pitch at the specific volume
  toneAC(note,vol);
}
