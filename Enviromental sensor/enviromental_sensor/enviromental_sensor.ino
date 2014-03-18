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
  delay(500);   
  ultrasonicLED();
  delay(500);
  humidityTemp();
  delay(500);  
}

void waterSensor(){
  waterSensorValue = analogRead(waterSensorPin);            
  if(waterSensorValue <=100){                        
    Serial.println("rain");      
  }
  else{
    Serial.println("no rain");  
  }
  delay(100);   
}

void ultrasonicLED(){
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
   else {
     digitalWrite(LED, LOW);
   }
   delay(100); 
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
  delay(100); 
}
