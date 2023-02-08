float temperature;                                                          // Define temperature variable
float voltage;                                                              // Define voltage variable
const unsigned long eventInterval = 500;                                    // Define measurement variable as 500 milliseconds
unsigned long previousTime = 0;                                             // Declare previousTime as 0;
int reading;                                                                // Declare reading variable    

#define sensorPinZero A0                                                    // Declare pin A0 as sensorPinZero

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);                                                     // Tells Arduino to get ready to exchange message with rate of 9600 bits per second. 
}

void loop()
{
    // put your main code here, to run repeatedly:

    unsigned long currentTime = millis();                                   // Initialize unsigned long called CurrentTime with the millis function, returning number of milliseconds since start of program
    if (currentTime - previousTime >= eventInterval)                        // Only read temperature meter if currentTime - previousTime is bigger or equal to the defined event interval.
    {
        reading = analogRead(sensorPinZero);                                // Read pin A0 and set it to reading variable
    }

    voltage = reading * (5000 / 1024.0);                                    // Voltage at pin in milliVolts for 5V connection    
    temperature = (voltage - 500) / 10;                                     // Converting millivolts into temeperature   
	String temp = "Temperature: ";                                          // Part of string to print out temperature                                             
    String celcius = "C";                                                   // Part of string to print out temperature
  	String printTemp = temp + temperature + char(176) + celcius;            // String to the serial monitor    
  	
    Serial.println(printTemp);                                              // Print out temperature string                               
    delay(1000);
}