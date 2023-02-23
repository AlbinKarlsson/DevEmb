#include "DHT.h"

#define DHTPIN 2      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

// Define the temperature thresholds
#define TEMP_1 24.4
#define TEMP_2 24.6
#define TEMP_3 24.8
#define TEMP_4 25

// Define the LED pins
#define LED1 3
#define LED2 4
#define LED3 5
#define LED4 6
#define LED5 7

#define INTERVAL 1000

void setup()
{

    // Set the LED pins to output mode
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED5, OUTPUT);

    Serial.begin(9600);

    dht.begin();
}

void loop()
{
    // Wait a few seconds between measurements.
    delay(INTERVAL);

    // Reading temperature takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    // Read temperature as Celsius
    float temperature = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(temperature))
    {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    // Control the LEDs based on the temperature
    // Check if the temperature is below the first threshold
    if (temperature < TEMP_1)
    {
        digitalWrite(LED1, HIGH); // Turn on Led 1, leave the rest off
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
    }
    // Check if the temperature is between the first and second thresholds
    else if (temperature >= TEMP_1 && temperature < TEMP_2)
    {
        digitalWrite(LED1, HIGH); // Turn on Led 1
        digitalWrite(LED2, HIGH); // Turn on Led 2, leave the rest off
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
    }
    // Check if the temperature is between the second and third thresholds
    else if (temperature >= TEMP_2 && temperature < TEMP_3)
    {
        digitalWrite(LED1, HIGH); // Turn on Led 1
        digitalWrite(LED2, HIGH); // Turn on Led 2
        digitalWrite(LED3, HIGH); // Turn on Led 3, leave the rest off
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
    }
    // Check if the temperature is between the third and fourth thresholds
    else if (temperature >= TEMP_3 && temperature < TEMP_4)
    {
        digitalWrite(LED1, HIGH); // Turn on Led 1
        digitalWrite(LED2, HIGH); // Turn on Led 2
        digitalWrite(LED3, HIGH); // Turn on Led 3
        digitalWrite(LED4, HIGH); // Turn on Led 4, leave 5 off
        digitalWrite(LED5, LOW);
    }
    // Check if the temperature is above the fourth threshold
    else if (temperature >= TEMP_4)
    {
        digitalWrite(LED1, HIGH); // Turn on Led 1
        digitalWrite(LED2, HIGH); // Turn on Led 2
        digitalWrite(LED3, HIGH); // Turn on Led 3
        digitalWrite(LED4, HIGH); // Turn on Led 4
        digitalWrite(LED5, HIGH); // Turn on Led 5
    }

    Serial.print(F("Temperature: "));
    Serial.print(temperature);
    Serial.print(F("°C \n"));
}
