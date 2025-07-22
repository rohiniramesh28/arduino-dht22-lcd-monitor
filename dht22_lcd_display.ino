#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>


#define DHTPIN 25       
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
    Serial.begin(115200);
   
    dht.begin();
    delay(2000); 

    lcd.init();
    lcd.backlight();   

    lcd.setCursor(0, 0);
    lcd.print(F("Hello Everyone!")); 
    delay(2000);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Measuring Temp")); 
    lcd.setCursor(0, 1);
    lcd.print(F("and Humidity"));  
    delay(4000);
    lcd.clear();
}

void loop() {
    float humidity = dht.readHumidity(); 
    float temperature = dht.readTemperature(); 

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT22 sensor!");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Sensor Error!"));
        delay(2000);
        return;
    }

    Serial.print(F("Temperature: "));
    Serial.print(temperature);
    Serial.println(F("°C"));
    
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.println(F("%"));

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Temp: ")); 
    lcd.print(temperature);
    lcd.print(F("C"));

    lcd.setCursor(0, 1);
    lcd.print(F("Humidity: ")); 
    lcd.print(humidity);
    lcd.print(F("%"));

    delay(2000); 
}
