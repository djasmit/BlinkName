
const pin_t MY_LED = D6; //use the D6 pin
const int MORSE_UNIT = 70;
const int DOT = 1 * MORSE_UNIT;
const int DASH = 3 * MORSE_UNIT;
const int SPC = 1 * MORSE_UNIT;
const int CHR_S = 2 * MORSE_UNIT; //is acually 3, but every char has 1 unit space already 
const int WRD_S = 4 * MORSE_UNIT; //is actually 7, but every letter already has 3 units space

SYSTEM_THREAD(ENABLED);

void setup() {
    //tell ARGON that the pin MY_LED is an output pin
    pinMode(MY_LED, OUTPUT);
}

void loop() {
    //type chosen messsage in brackets
    char message[] = "Damien";
    
    //we need to get the size of the array here because C++ only passes arrays to methods by pointer
    int size = sizeof(message);
    
    //buzz the message in morse code
    buzzMessage(message, size);
}

//receives an array of characters and feeds each character into the buzzChar method
//then adds a delay for the word break at the end of the message
void buzzMessage(char message[], int size)
{
    //from first element to final element in message
    for (int i = 0; i < size; i++)
    { buzzChar(message[i]); }   
    
    delay(WRD_S);
}

//receives a character and determines what type of morse signal to send depending on that
//afterwords ads a delay for the character break.
void buzzChar(char chr)
{
    //morse code doesn't detect case, so give all letters a standardized case
    chr = tolower(chr);
    
    if (chr == ' ')
    {
        delay(WRD_S);
    }
    if (chr == 'a') {
        buzz(DOT); buzz(DASH);
    }
    else if (chr == 'b') {
        buzz(DASH); buzz(DOT); buzz(DOT); buzz(DOT);
    }
    else if (chr == 'c') {
        buzz(DASH); buzz(DOT); buzz(DASH); buzz(DOT);
    }
    else if (chr == 'd') {
        buzz(DASH); buzz(DOT); buzz(DASH);
    }
    else if (chr == 'e') {
        buzz(DOT);
    }    
    else if (chr == 'f') {
        buzz(DOT); buzz(DOT); buzz(DASH); buzz(DOT);
    }    
    else if (chr == 'g') {
        buzz(DASH); buzz(DASH); buzz(DOT);
    }    
    else if (chr == 'h') {
        buzz(DOT); buzz(DOT); buzz(DOT); buzz(DOT);
    }   
    else if (chr == 'i') {
        buzz(DOT); buzz(DOT);
    }   
    else if (chr == 'j') {
        buzz(DOT); buzz(DASH); buzz(DASH); buzz(DASH);
    }   
    else if (chr == 'k') {
        buzz(DASH); buzz(DOT); buzz(DASH);
    }   
    else if (chr == 'l') {
        buzz(DOT); buzz(DASH); buzz(DOT); buzz(DOT);
    }   
    else if (chr == 'm') {
        buzz(DASH); buzz(DASH);
    }       
    
    else if (chr == 'n') {
        buzz(DASH); buzz(DOT);
    }       
     else if (chr == 'o') {
        buzz(DASH); buzz(DASH); buzz(DASH);
    }   
     else if (chr == 'p') {
        buzz(DOT); buzz(DASH); buzz(DASH); buzz(DOT);
    } 
     else if (chr == 'q') {
        buzz(DASH); buzz(DASH); buzz(DOT); buzz(DASH);
    }   
     else if (chr == 'r') {
        buzz(DOT); buzz(DASH); buzz(DOT);
    } 
     else if (chr == 's') {
        buzz(DOT); buzz(DOT); buzz(DOT);
    }   
     else if (chr == 't') {
        buzz(DASH);
    }   
     else if (chr == 'u') {
        buzz(DOT); buzz(DOT); buzz(DASH);
    }
     else if (chr == 'v') {
        buzz(DOT); buzz(DOT); buzz(DOT); buzz(DASH);
    }   
     else if (chr == 'w') {
        buzz(DOT); buzz(DASH); buzz(DASH);
    }   
     else if (chr == 'w') {
        buzz(DOT); buzz(DASH); buzz(DASH);
    }      
     else if (chr == 'x') {
        buzz(DASH); buzz(DOT); buzz(DOT);
    }  
     else if (chr == 'y') {
        buzz(DASH); buzz(DOT); buzz(DASH); buzz(DASH);
    }  
      else if (chr == 'z') {
        buzz(DASH); buzz(DASH); buzz(DOT); buzz(DOT);
    }     
    
    //we'e finishd a character, so add the chararacter delay
    delay(CHR_S);
}

//turns on a selected device for the given amount of time, then turn it off and delay for 1 morse code unit
void buzz(int amount)
{
    digitalWrite(MY_LED, HIGH);
    delay(amount);
    digitalWrite(MY_LED, LOW);
    delay(SPC);
}
