#include <Arduino.h>
#include "paledefs.h"

 

unsigned int shift = 0;
byte lastcode  = 0;
bool keyup = false;
byte rc = 0;
byte keymap[256];

void kb_interruptHandler()
{
    
    shift>>=1;
    shift|=(digitalRead(KEYBOARD_DATA)<<9);
    if(++rc==11)
    {
         
            uint8_t data=(shift>>1)&0xff;
            lastcode = data;
            rc=0;
            shift=0;
            if (data != 240) {
                 keymap[data] = 0;
            } else {
              for(int gg = 0;gg < 256;gg++)
                 keymap[gg] = 1;
             
            }
           
        /*   Serial.print("Received keys: ");
           for (int a=0;a<256;a++)
           {
             Serial.print(keymap[a]);
             Serial.print(" ");
           }
           Serial.println("");
           Serial.print("Lastcode:");      
           Serial.println(lastcode); */
    }
 
}



void kb_begin()
{
    pinMode(KEYBOARD_DATA,OUTPUT_OPEN_DRAIN);
    pinMode(KEYBOARD_CLK,OUTPUT_OPEN_DRAIN);
    digitalWrite(KEYBOARD_DATA,true);
    digitalWrite(KEYBOARD_CLK,true);
    attachInterrupt(digitalPinToInterrupt(KEYBOARD_CLK), kb_interruptHandler, FALLING);
    for(int gg = 0;gg < 256;gg++)
      keymap[gg] = 1;
    
}
