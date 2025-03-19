# IoT-Temperature-Monitor
# IoT-Based Temperature and Humidity Monitoring 🌡️  
An IoT-enabled system using an **ESP8266 WiFi module** and a **DHT11 sensor** to monitor **temperature & humidity** remotely. Data is displayed on an **LCD screen** and sent to a cloud platform.

## 📌 Features
✅ Real-time temperature & humidity monitoring  
✅ Cloud data storage using Firebase/Blynk  
✅ LCD display for local readings  
✅ Automatic alerts when thresholds are exceeded  

## 🛠️ Hardware Used
- ESP8266 (NodeMCU)  
- DHT11/DHT22 Sensor  
- 16x2 LCD Display  
- Firebase/Blynk for IoT data logging  

## 📝 Code Example
```cpp
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
