// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 3
// Exercise 3
// Submission code: D12DDDDD 

// This code corresponds to image ex3.jpeg in the images folder 


float temperature;                                                   // Declare temperature variable   
float celsius;                                                       // Declare celsius variable  
float voltage;                                                       // Declare voltage variable  
float luminosity;                                                    // Declare luminosity variable   
int reading;                                                         // Declare temp meter reading variable   
const unsigned long eventInterval = 1000;                            // Define eventInterval as one second   
unsigned long previousTime = 0;                                      // Set previouStime to be 0   

#define sensorPinZero A0                                             // Define A0 as sensorPinZero
#define sensorPinOne A1                                              // Define A1 as sensorPinOne

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    // Source https://www.programmingelectronics.com/arduino-sketch-with-millis-instead-of-delay/
    unsigned long currentTime = millis();                                   // Initialize unsigned long called CurrentTime with the millis function, returning number of milliseconds since start of program
    if (currentTime - previousTime >= eventInterval)                        // Only read temperature meter if currentTime - previousTime is bigger or equal to the defined event interval.
    {   
        // read light
        luminosity = measureLuminosity();
        reading = analogRead(sensorPinZero);                                // Read pin A0 and set it to reading variable
    }

    // Serial.print ("Brightness:");
    Serial.println(luminosity);
    delay(1000);

    voltage = reading * (5000 / 1024.0);                                    // Voltage at pin in milliVolts for 5V connection    
    temperature = (voltage - 500) / 10;                                     // Converting millivolts into temeperature   
	String temp = "Temperature: ";                                          // Part of string to print out temperature                                             
    String celcius = "C";                                                   // Part of string to print out temperature
  	String printTemp = temp + temperature + char(176) + celcius;            // String to the serial monitor    
  	
    Serial.println(printTemp);                                              // Print out temperature string                               
    delay(1000);

    // Serial.println(temperature);
    delay(1000);

    // Correct dependencies
    if (temperature < -12.0 && luminosity == 0.0)                    // Check for range <-12 and luminosity 0%
    {
        digitalWrite(12, HIGH); // Turn green on
        digitalWrite(11, LOW);  // Turn red off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature >= -12.0 && temperature <= 0.0) && (luminosity >= 1.0 && luminosity <= 20.0))     // Check for range 12 °C - 0 °C and luminosity 1% - 20%.
    {
    {
        digitalWrite(12, HIGH); // Turn green on
        digitalWrite(11, LOW);  // Turn red off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature <= 20.0 && temperature >= 0) && (luminosity >= 21.0 && luminosity <= 60.0))       // Check for range 0 °C - 20 °C and luminosity 21% - 60%.
    {
        digitalWrite(12, HIGH); // Turn green on
        digitalWrite(11, LOW);  // Turn red off
        digitalWrite(6, LOW);   // Turn blue off
    }
    if ((temperature >= 21) && (luminosity >= 61.0 && luminosity <= 100.0))                            // Check for range  temperature >= 21 °C and luminosity 61%-100%.
        digitalWrite(12, HIGH); // Turn green on
        digitalWrite(11, LOW);  // Turn red off
        digitalWrite(6, LOW);   // Turn blue off
    }

    // Incorrect dependencies temperature
    if (temperature >= -12.0 && luminosity <= 0.0)                                                    // Check if temperature > -12.0 and if luminosity is less or equal to 0.0. 
    {
        digitalWrite(11, HIGH); // Turn red on
        digitalWrite(12, LOW);  // Turn green off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature > 0.0) && (luminosity >= 1.0 && luminosity <= 20.0))                             // Check if temperature > 1.0 and if luminosity is less or equal to 20.  
    {
        digitalWrite(11, HIGH); // Turn red on
        digitalWrite(12, LOW);  // Turn green off
        digitalWrite(6, LOW);   // Turn blue off
    }

    if ((temperature > 20.0) && (luminosity >= 21.0 && luminosity <= 60.0))                           // Check if temperature > 20.0 and if luminosity is betwen 21% and 60%.
    {
        digitalWrite(11, HIGH); // Turn red on
        digitalWrite(12, LOW);  // Turn green off
        digitalWrite(6, LOW);   // Turn blue off
    }

    // Incorrect dependencies luminosity
    if ((temperature < 0.0 && temperature >= -12.0) && (luminosity >= 20.0))                          // Check if temperature is between -12 and 0 and if luminosity is bigger than 20%.
    {
        digitalWrite(6, HIGH); // Turn blue on
        digitalWrite(12, LOW); // Turn green off
        digitalWrite(11, LOW); // Turn red off
    }

    if ((temperature < 0.0) && (luminosity >= 21.0 && luminosity <= 60.0))                             // Check if temperature is less than 0 and if luminosity is between 21% and 60%.
    {
        digitalWrite(6, HIGH); // Turn blue on
        digitalWrite(12, LOW); // Turn green off
        digitalWrite(11, LOW); // Turn red off
    }

    if ((temperature < 21.0) && (luminosity >= 61.0 && luminosity <= 100.0))                          // check if temperature is less than 21 and luminosity is between 61% and 100%. 
    {
        digitalWrite(6, HIGH); // Turn blue on
        digitalWrite(12, LOW); // Turn green off
        digitalWrite(11, LOW); // Turn red off
    }
}

float measureLuminosity()                                                                             // Function to check luminosity
{       
    int value_ldr = analogRead(sensorPinOne);                                                        // Read photometer value from pin 0  
    float converted_ldr_val = map(value_ldr, 6, 679, 0, 100);                                         // Map value of photometer from 6-679 to 0 to 100 instead.   
    return converted_ldr_val;                                                                         // Return converted value      
}