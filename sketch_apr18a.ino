#define fan 8
#include<Arduino.h>
const int MOTION_SENSOR_PIN = 2;   // Arduino pin connected to the OUTPUT pin of motion sensor
const int LED_PIN           = 5;   // Arduino pin connected to LED's pin
const int LED_PIN2 =6;
int motion ;
#include <DHT.h>
const int pir = 9;

// Define the pins for the DHT sensors

const int DHT_PIN_2 = 12;
const int DHT_PIN_1 = 4;

// Define the type of DHT sensor (DHT11)
// const int DHT_TYPE = DHT22;

// Create DHT objects

DHT dht2(DHT_PIN_2, DHT11);
DHT dht1(DHT_PIN_1, DHT11);
void setup() {
  // put your setup code here, to run once:
  pinMode(fan, OUTPUT);
  Serial.begin(9600);
  
  // Initialize DHT sensors
  dht2.begin();
  dht1.begin();
  pinMode(MOTION_SENSOR_PIN, INPUT); // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT); 
  pinMode(pir, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

float humidity2 = dht2.readHumidity();
float humidity1 = dht1.readHumidity();
float temperature1 = dht1.readTemperature();
float temperature2 = dht2.readTemperature();
delay(1000);
  Serial.println("Sensor 1:");
  Serial.print("Humidity: ");
  Serial.print(humidity1);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature1);
  Serial.println("°C");
   
   Serial.println("Sensor 2:");
  Serial.print("Humidity: ");
  Serial.print(humidity2);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature2);
  Serial.println("°C");
if (humidity2>60){
  digitalWrite(fan, HIGH);
}
else {
  digitalWrite(fan, LOW);

}
  // read new state
  if ( digitalRead(MOTION_SENSOR_PIN) ) { // pin state change: LOW -> HIGH
   
    digitalWrite(LED_PIN, LOW); // turn off
    degiralWrite(LED_PIN2, HIGH);
  }
  else{
    digitalWrite(LED_PIN,HIGH); // turn on
     degiralWrite(LED_PIN2, LOW);
  }
if ( digitalRead(pir ) { // pin state change: LOW -> HIGH
   
    digitalWrite(LED_PIN, LOW); // turn off
    degiralWrite(LED_PIN2, HIGH);
  }
  else{
    digitalWrite(LED_PIN,HIGH); // turn on
     degiralWrite(LED_PIN2, LOW);
  }

}
