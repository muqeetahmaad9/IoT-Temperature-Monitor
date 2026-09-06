#include <DHT.h>
#include <ESP8266WiFi.h>

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Your_WiFi_Name";
const char* password = "Your_WiFi_Password";

void setup() {
    Serial.begin(115200);
    dht.begin();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting...");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    
    if (!isnan(temp) && !isnan(hum)) {
        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.print("°C  Humidity: ");
        Serial.print(hum);
        Serial.println("%");
    } else {
        Serial.println("Failed to read from DHT sensor!");
    }
    delay(2000);
}
