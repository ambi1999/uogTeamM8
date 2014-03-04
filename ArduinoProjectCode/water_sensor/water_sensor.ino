                                                          // declares the sensor pins.
const int waterSensorPin = A0;
const int tempSensorPin = A1;
const int lightSensorPin = A2;  
const int humiditySensorPin = A3;
                                                          // initialises the sensor variables.
int waterSensorValue = 0;        
int tempSensorValue = 0;
int lightSensorValue = 0;
int humiditySensorValue = 0;

void setup() {
  Serial.begin(9600);                                    //Starts serial communications.
}

void loop() {
  waterSensorValue = analogRead(waterSensorPin);         //reads the analog value and stores it into the variable.           
  Serial.println("water sensor = " );                       
  Serial.println(waterSensorValue);                      //Prints the value to the serial monitor.
  delay(100);

  tempSensorValue = analogRead(tempSensorPin);           //reads the analog value and stores it into the variable.         
  Serial.println("temperature sensor = " );                       
  Serial.println(tempSensorValue);                       //Prints the value to the serial monitor.
  delay(100);

  lightSensorValue = analogRead(lightSensorPin);         //reads the analog value and stores it into the variable.         
  Serial.println("light sensor = " );                       
  Serial.println(lightSensorValue);                      //Prints the value to the serial monitor.
  delay(100);
  
  humiditySensorValue = analogRead(humiditySensorPin);   //reads the analog value and stores it into the variable.           
  Serial.println("humidity sensor = " );                       
  Serial.println(humiditySensorValue);                   //Prints the value to the serial monitor.
  delay(100);
}
 
