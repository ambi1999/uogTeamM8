const int analogInPin = A0;  
int sensorValue = 0;        // value read from the pot

//code by Phillip
int test1=0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  sensorValue = analogRead(analogInPin);            
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  delay(2);                     
}
