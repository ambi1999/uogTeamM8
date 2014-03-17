#include <NewPing.h>

int  TRIGGER_PIN = 11;
int  ECHO_PIN    = 10;
int MAX_DISTANCE = 200;  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
int DistanceCm;
int  LED = 13;
void setup()  
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

}


void loop()   
{
  delay(300);
  DistanceCm = sonar.ping_cm();
  Serial.print(DistanceCm); 
  Serial.println("cm");
 if (DistanceCm >= 0 && DistanceCm<= 50){
 digitalWrite( LED, HIGH);
 delay(500);
 digitalWrite(LED, LOW);    
 delay(500); 
 }
else {  digitalWrite(LED, LOW);}
}



