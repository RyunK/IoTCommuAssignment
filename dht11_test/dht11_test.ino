#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
Serial.begin(9600);
Serial.print("Program start...");
dht.begin();
Serial.println();
}
void loop()
{
Serial.println("\n");
Serial.print("Read sensor: ");
Serial.print("Humidity (%): ");
Serial.println((float)dht.readHumidity());
Serial.print("Temperature (°C): ");
Serial.println((float)dht.readTemperature());
delay(2000);
}