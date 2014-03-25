#include <NewPing.h>//The libary for the ultrasonic sensor.
#include <DHT11.h>  //The libary for the humidity sensor.

//Variables for water sensor.
int waterSensorPin = A0; 
int waterSensorValue = 0;       

//Variables for ultrasonic/led.
int  TRIGGER_PIN = 11;
int  ECHO_PIN    = 10;
int MAX_DISTANCE = 200;  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
int DistanceCm;
int  LED = 13;

//Variables for humidity and temperature sensor.
int humidityPin=4;
DHT11 dht11(humidityPin);

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  while (!Serial) {
    }
}

void loop() {
  
  waterSensor();
  delay(100);   
  ultrasonicLED();
  delay(100);
  humidityTemp();
  delay(10);  
}

void waterSensor(){
  waterSensorValue = analogRead(waterSensorPin);            
  if(waterSensorValue <=100){                        
    Serial.println("rain");      
  }
  else{
    Serial.println("no rain");  
  }
  delay(10);   
}

void ultrasonicLED(){
  delay(100);
  DistanceCm = sonar.ping_cm();
  Serial.print(DistanceCm); 
  Serial.println("cm");
  
  if (DistanceCm >= 40 && DistanceCm<= 50){           //make into a function, call with delay time
    digitalWrite( LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);    
    delay(50); 
   }
  else if (DistanceCm >= 30 && DistanceCm<= 40){
    digitalWrite( LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);    
    delay(50); 
   }
  else if (DistanceCm >= 20 && DistanceCm<= 30){
    digitalWrite( LED, HIGH);
    delay(300);
    digitalWrite(LED, LOW);    
    delay(50); 
   }
  else if (DistanceCm >= 10 && DistanceCm<= 20){
    digitalWrite( LED, HIGH);
    delay(400);
    digitalWrite(LED, LOW);    
    delay(50); 
   }
  else if (DistanceCm >= 5 && DistanceCm<= 10){
    digitalWrite( LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);    
    delay(50); 
   } 
   else {
     digitalWrite(LED, LOW);
   }
   delay(10); 
}

void humidityTemp(){
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0){
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else{
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
  delay(10); 
}
