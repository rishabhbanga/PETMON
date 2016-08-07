// demo of Grove - Light Sensor
#include "DHT.h"
#include <Suli.h>
#include <Wire.h>
#include "acc_adxl345_Arduino.h"

#define DHTPIN 3     // what pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);
Acc_Adxl345 acc;

const int pinLight = A0;
int level = 0;


void setup()
{
    Serial.begin(9600);
    dht.begin();
      acc.begin();
} 

void loop()
{
 float ax, ay, az;
 acc.get(&ax, &ay, &az);
    int value = analogRead(pinLight);
    Serial.println(value);
    delay(100);
    Serial.print(ax);                   // print it out
    Serial.print('\t');
    Serial.print(ay);
    Serial.print('\t');
    Serial.println(az);
    delay(1000);
     while((ax>-0.01 && ax<-0.20) && (ay>-0.25 && ay<-0.50  ) && (az>-0.55 && az<-1.0)){
      int footsteps;
      footsteps+=1;
        Serial.println("footsteps : ");
      Serial.print(footsteps);
      delay(10);
    
      }
    
    float t = 0.0;
    float h = 0.0;
    
    if(dht.readHT(&t, &h))
    {
        Serial.println("------------------------------");
        Serial.print("temperature = ");
        Serial.println(t);
        
        Serial.print("humidity = ");
        Serial.println(h);
    }
    
    delay(2000);
}
