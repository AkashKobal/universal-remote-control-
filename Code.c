#include <IRremote.h>


int IRpin = 8;
IRrecv irrecv(IRpin);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(13,OUTPUT);

}

  
void loop() 

{   
  if (irrecv.decode(&results)) 
    {
     Serial.println(results.value);
      delay(10);
      if(results.value==12582924)
      digitalWrite(13,HIGH); 
      delay(500);
      digitalWrite(13,LOW);
     irrecv.resume(); 
    }
}    