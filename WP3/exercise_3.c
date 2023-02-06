float temperature;
float voltage;
const unsigned long eventInterval = 500;
unsigned long previousTime = 0;
int reading;

#define sensorPinZero A0

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:

    unsigned long currentTime = millis();
    if (currentTime - previousTime >= eventInterval)
    {
        reading = analogRead(sensorPinZero);
    }

    voltage = reading * (5000 / 1024.0);
    temperature = (voltage - 500) / 10;

    Serial.println(temperature);
    delay(1000);
}