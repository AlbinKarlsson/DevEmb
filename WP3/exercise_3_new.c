float temperature;
float celsius;
float voltage;
float luminosity;
int reading;
const unsigned long eventInterval = 1000;
unsigned long previousTime = 0;

#define sensorPinZero A0
#define sensorPinOne A1

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
        // read light
        luminosity = measureLuminosity();
        reading = analogRead(sensorPinZero);
    }

    // Serial.print ("Brightness:");
    Serial.println(luminosity);
    delay(1000);

    voltage = reading * (5000 / 1024.0);
    temperature = (voltage - 500) / 10;
  	String temp = "Temperature: ";
    String celcius = "C";
  	String printTemp = temp + temperature + char(176) + celcius;
  	
    Serial.println(printTemp);

    // Serial.println(temperature);
    delay(1000);

    // Correct dependencies
    if (temperature < -12.0 && luminosity == 0.0)
    {
        digitalWrite(12, HIGH); // Turn green on
        digitalWrite(11, LOW);  // Turn red off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature >= -12.0 && temperature <= 0.0) && (luminosity >= 1.0 && luminosity <= 20.0))
    {
        digitalWrite(12, HIGH); // Turn green on
        digitalWrite(11, LOW);  // Turn red off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature <= 20.0 && temperature >= 0) && (luminosity >= 21.0 && luminosity <= 60.0))
    {
        digitalWrite(12, HIGH); // Turn green on
        digitalWrite(11, LOW);  // Turn red off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature >= 21) && (luminosity >= 61.0 && luminosity <= 100.0))
    {
        digitalWrite(12, HIGH); // Turn green on
        digitalWrite(11, LOW);  // Turn red off
        digitalWrite(6, LOW);   // Turn blue off
    }

    // Incorrect dependencies temperature
    if (temperature >= -12.0 && luminosity <= 0.0)
    {
        digitalWrite(11, HIGH); // Turn red on
        digitalWrite(12, LOW);  // Turn green off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature > 0.0) && (luminosity >= 1.0 && luminosity <= 20.0))
    {
        digitalWrite(11, HIGH); // Turn red on
        digitalWrite(12, LOW);  // Turn green off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature > 20.0) && (luminosity >= 21.0 && luminosity <= 60.0))
    {
        digitalWrite(11, HIGH); // Turn red on
        digitalWrite(12, LOW);  // Turn green off
        digitalWrite(6, LOW);   // Turn blue off
    }

    // Incorrect dependencies luminosity
    if ((temperature < 0.0 && temperature >= -12.0) && (luminosity >= 20.0))
    {
        digitalWrite(6, HIGH); // Turn blue on
        digitalWrite(12, LOW); // Turn green off
        digitalWrite(11, LOW); // Turn red off
    }

    if ((temperature < 0.0) && (luminosity >= 21.0 && luminosity <= 60.0))
    {
        digitalWrite(6, HIGH); // Turn blue on
        digitalWrite(12, LOW); // Turn green off
        digitalWrite(11, LOW); // Turn red off
    }

    if ((temperature < 21.0) && (luminosity >= 61.0 && luminosity <= 100.0))
    {
        digitalWrite(6, HIGH); // Turn blue on
        digitalWrite(12, LOW); // Turn green off
        digitalWrite(11, LOW); // Turn red off
    }
}

float measureLuminosity()
{
    int value_ldr = analogRead(sensorPinOne);
    float converted_ldr_val = map(value_ldr, 6, 679, 0, 100);
    return converted_ldr_val;
}