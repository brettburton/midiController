

void sendMidi(){

  for(int i=0;i<8;i++){
    
    // LED STUFF
//    if(buttonStates[i] == HIGH){
//    digitalWrite(ledPin, HIGH); // turn LED on:
//    }
    
    
    //MIDI BUTTONS
    if ((buttonStates[i] == HIGH) && (isItPushed[i] == false)){     
    MIDI.sendNoteOn(notes[i]+keyVal,127,1);  // Send a Note (pitch 42, velo 127 on channel 1)
    isItPushed[i] = true;
  } 
  }
  

  for (int i=0;i<8;i++){
    if (buttonStates[i] == LOW){     
//    digitalWrite(ledPin, LOW); // turn LED on:
    MIDI.sendNoteOn(notes[i]+keyVal,0,1);  // Send a Note (pitch 42, velo 127 on channel 1)
    isItPushed[i] = false;
  } 
  }
  
}
