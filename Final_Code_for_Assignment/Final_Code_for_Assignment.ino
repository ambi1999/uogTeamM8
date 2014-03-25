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

//The set up only runs once at the start.
void setup() {
  Serial.begin(9600); //starts the serial communications.
  pinMode(LED, OUTPUT); //sets the pin for the led to output.
  while (!Serial) {  //allows the program to run on Arduno Duo.
    }
}

//This is the main loop of the program it calls the sensor functions.
void loop() { 
  
  waterSensor(); //Calls water sensor function.
  delay(100); //Delay 100ms.   
  ultrasonicLED(); //Calls the ultra sonic function.
  delay(100); //Delay 100ms.
  humidityTemp(); //Calls the humidity and temperature function.
  delay(10); //Delay 10ms. 
}

void waterSensor(){
  waterSensorValue = analogRead(waterSensorPin);  //Reads the water sensor value.          
  //If the sensor value is below a threshold then there is rain, so prints "rain".
  if(waterSensorValue <=200){                        
    Serial.println("rain");      
  }
  //Else the value is below thethreshold so there is no rain, so prints "no rain".
  else{
    Serial.println("no rain");  
  }
  delay(10); //Delay 10ms.    
}

void ultrasonicLED(){
  delay(100); //Delay 100ms. 
  DistanceCm = sonar.ping_cm(); //Get the distance from the ultrasonic sensor. 
  //Prints the distance value followed by "cm".
  Serial.print(DistanceCm);
  Serial.println("cm");
  
  //If the distance is between 40 and 50 cm call the blink LED function with a delay of 100ms.
  if (DistanceCm >= 40 && DistanceCm<= 50){ 
    blinkLED(100); //Pass the value of 100 to the blink led function.
   }
  //If the distance is between 30 and 39 cm call the blink LED function with a delay of 200ms.
  else if (DistanceCm >= 30 && DistanceCm<= 39){
    blinkLED(200); //Pass the value of 200 to the blink led function.
   }
  //If the distance is between 20 and 29 cm call the blink LED function with a delay of 300ms.
  else if (DistanceCm >= 20 && DistanceCm<= 29){
    blinkLED(300); //Pass the value of 300 to the blink led function. 
   }
  //If the distance is between 10 and 19 cm call the blink LED function with a delay of 400ms.
  else if (DistanceCm >= 10 && DistanceCm<= 19){
    blinkLED(400); //Pass the value of 400 to the blink led function.
   }
  //If the distance is between 1 and 9 cm call the blink LED function with a delay of 500ms.
  else if (DistanceCm >= 1 && DistanceCm<= 9){
    blinkLED(500); //Pass the value of 500 to the blink led function.
   }
  //else turn the led off.
  else {
    digitalWrite(LED, LOW);
  }
  delay(10); 
}

void humidityTemp(){
  int err;
  float temp, humi;
  //Read the humidity and temperature values, if there is no error then prints theses values.
  if((err=dht11.read(humi, temp))==0){
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  //Else there is an error so it prints the error value.
  else{
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
  delay(10); 
}

void blinkLED(int idelay){ //accept an integer passed to it, this integer is the delay time.
  digitalWrite( LED, HIGH); //Turn the LED on.
  delay(idelay); //Delay for the ammount passed in the parameter.
  digitalWrite(LED, LOW); //Turn the LED off.    
  delay(50); 
}
