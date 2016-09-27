

#include <Wire.h>
#include "Seeed_QTouchSensor.h"
#include "pitches.h"


#define PWM_OUT_PIN 5


QTouch qTouch;


unsigned int noteDurations = 50 ;


void setup()
{  
    Serial.begin(115200);
    Serial.println("Test for Q Touch");
    
    pinMode(13, OUTPUT);
    for(int i=0;i<2; i++)
    {
        digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13, LOW);
        delay(500);
    }
    digitalWrite(13, HIGH);
    
    qTouch.Init();  
}


void loop()
{
    int key = qTouch.QTouchRead();

    if(key > -1)
    {
        Serial.print("Press key is:"); 
        Serial.println(key); 
        Gamut_Play(key);
    }
    delay(30);
}


void Gamut_Play(unsigned char data)
{
    switch(data)
    {
        /*MID*/     
        case 6:
        tone(PWM_OUT_PIN,NOTE_C5,noteDurations);//Do(523Hz)
        break;        
        case 5:
        tone(PWM_OUT_PIN,NOTE_D5,noteDurations);//Re(587Hz)
        break;        
        case 4:
        tone(PWM_OUT_PIN,NOTE_E5,noteDurations);//Mi(659Hz)
        break;        
        case 3:
        tone(PWM_OUT_PIN,NOTE_F5,noteDurations);//Fa(698Hz)
        break;        
        case 2:
        tone(PWM_OUT_PIN,NOTE_G5,noteDurations);//So(784Hz)
        break;        
        case 1:
        tone(PWM_OUT_PIN,NOTE_A5,noteDurations);//La(880Hz)
        break;       
        case 0:
        tone(PWM_OUT_PIN,NOTE_B5,noteDurations);//Si(988Hz)
        break;  
        /*MID*/ 
        default:
        break;         
    }
    //delay(noteDurations * 1.3);
}
