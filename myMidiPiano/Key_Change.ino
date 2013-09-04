 
 
 void keyChanger(){
 
  //CHANGE THE KEY
    if ((buttonStates[8] == HIGH) && (isItPushed[8] == false)){
      keyVal -= 1;
      isItPushed[8] = true;
    }
    
     if ((buttonStates[9] == HIGH) && (isItPushed[9] == false)){
      keyVal += 1;
      isItPushed[9] = true;
    }
    
    if (buttonStates[8] == LOW){
      isItPushed[8] = false;
    }
    
     if (buttonStates[9] == LOW){
      isItPushed[9] = false;
    }
    
 }
