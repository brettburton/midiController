#include <MIDI.h>

/*
  SIMPLE MIDI KEYBOARD
  Brett Burton 2013
  
  Single Octave (8) buttons connected to pins 4 thru 11.  UP / DOWN key change buttons on 12 + 13.  
  Pin 1 is connected to the MIDI.
  
*/



const int myButtons[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //the number of the button pins
//const int ledPin =  13; // the number of the LED pin
int buttonStates[10];  //pushbutton status
boolean isItPushed[10]; //declare our bool array
int notes[] = {48, 50, 52, 53, 55, 57, 59, 60};
int keyVal = 0;



//------------------------------------------------------------------------

void setup() {
  
 // Serial.begin(9600); //Turn on for Debugging, and turn off Midi.begin and all Midi messages
  
  //initialize our arrays
  for (int i=0;i<10;i++){
  isItPushed[i] = false; //our buttons are not playing at the start
  buttonStates[i] = 0;
  pinMode(myButtons[i], INPUT); //setup the buttons as inputs
  }
  
//  pinMode(LED, OUTPUT);
  MIDI.begin(4); // Launch MIDI with default options
		 // input channel is set to 4
}

//------------------------------------------------------------------------

void loop() {

  checkButtons();
  sendMidi();
  keyChanger();
  
}

//------------------------------------------------------------------------

void checkButtons(){
  // check the button states
  for (int i=0;i<10;i++){
  buttonStates[i] = digitalRead(myButtons[i]);
  }
}
