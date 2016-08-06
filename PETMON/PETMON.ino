// demo of Grove - Light Sensor
#include "DHT.h"


#define DHTPIN 3     // what pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);


const int pinLight = A0;
int level = 0;


void setup()
{
    Serial.begin(9600);
    dht.begin();
     
}

void loop()
{
    int value = analogRead(pinLight);
    Serial.println(value);
    delay(100);
    
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
