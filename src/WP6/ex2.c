// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 6
// Exercise 2
// Submission code: ZZZ12ZZZ
// See image 'ex2_ParkingSensor.png' in the images folder

// C++ code
//
int distanceThreshold = 0;							// Initialize variable distanceThreshold
int cm = 0;											// Initialize variable cm
void setup()										
{						
  	Serial.begin(9600);								
  	pinMode(2, OUTPUT);								// Set the pin mode for digital pin 2 as output using the "pinMode()" function
  	pinMode(3, OUTPUT);								// Set the pin mode for digital pin 3 as output using the "pinMode()" function
  	pinMode(4, OUTPUT);								// Set the pin mode for digital pin 4 as output using the "pinMode()" function
  	pinMode(5, OUTPUT);								// Set the pin mode for digital pin 5 as output using the "pinMode()" function
  	pinMode(13, OUTPUT);							// Set the pin mode for digital pin 13 as output using the "pinMode()" function
}

void loop()
{
  	distanceThreshold = 200;						// Set variable distanceThreshold to 200, threshold distance to activate LEDs
  	cm = 0.01723 * readUltrasonicDistance(7, 6); 	// measure the ping time in cm
	Serial.print(cm);								// Print the variable cm 
  	Serial.println(" cm");							// Print 
  
  	if (cm > distanceThreshold) {					// If cm is greater than distanceThreshold do the following:
    	digitalWrite(2, LOW); 						// Setting pin 2 to LOW
   		digitalWrite(3, LOW); 						// Setting pin 3 to LOW
    	digitalWrite(4, LOW); 						// Setting pin 4 to LOW
    	digitalWrite(5, LOW); 						// Setting pin 5 to LOW
  	}else if (cm <= distanceThreshold && cm > distanceThreshold - 80) {	// If cm is greater than distanceThreshold AND cm is greater than distanceThreshold - 80, do the follwoing:
    	digitalWrite(2, HIGH);						// Setting pin 2 to HIGH
    	digitalWrite(3, LOW);						// Setting pin 3 to LOW
    	digitalWrite(4, LOW);						// Setting pin 4 to LOW
    	digitalWrite(5, LOW);						// Setting pin 5 to LOW
      	tone(13, 150, 800);							// Activate the Piezo, the tone function takes in three arguments, (which pin) 13, (pitch) 150 and (duration of tone) 800. 
        delay(800);									// Added a delay for 800 miliseconds, to set intervals for often a sound should beep
  	} else if(cm <= distanceThreshold && cm > distanceThreshold - 130){ // If cm is greater than distanceThreshold AND cm is greater than distanceThreshold - 130, do the follwoing:
      	digitalWrite(2, HIGH);						// Setting pin 2 to HIGH
    	digitalWrite(3, HIGH);						// Setting pin 3 to HIGH
    	digitalWrite(4, LOW);						// Setting pin 4 to LOW
    	digitalWrite(5, LOW);						// Setting pin 5 to LOW
		tone(13, 200, 800);							// Activate the Piezo, the tone function takes in three arguments, (which pin) 13, (pitch) 200 and (duration of tone) 800. 
      	delay(500);									// Added a delay for 500 miliseconds, to set intervals for often a sound should beep
  	} else if(cm <= distanceThreshold && cm > distanceThreshold - 150){ // If cm is greater than distanceThreshold AND cm is greater than distanceThreshold - 150, do the follwoing:
      	digitalWrite(2, HIGH);						// Setting pin 2 to HIGH
    	digitalWrite(3, HIGH);						// Setting pin 3 to HIGH
    	digitalWrite(4, HIGH);						// Setting pin 4 to HIGH
    	digitalWrite(5, LOW);						// Setting pin 5 to LOW
		tone(13, 300, 800);							// Activate the Piezo, the tone function takes in three arguments, (which pin) 13, (pitch) 300 and (duration of tone) 800. 
      	delay(200);									// Added a delay for 200 miliseconds, to set intervals for often a sound should beep
  	} else if(cm <= distanceThreshold && cm > distanceThreshold - 175){ // If cm is greater than distanceThreshold AND cm is greater than distanceThreshold - 175, do the follwoing:
      	digitalWrite(2, HIGH);						// Setting pin 2 to HIGH
    	digitalWrite(3, HIGH);						// Setting pin 3 to HIGH
    	digitalWrite(4, HIGH);						// Setting pin 4 to HIGH
    	digitalWrite(5, HIGH);						// Setting pin 5 to HIGH
		tone(13, 400, 800);							// Activate the Piezo, the tone function takes in three arguments, (which pin) 13, (pitch) 400 and (duration of tone) 800. 
      	delay(100);									// Added a delay for 100 miliseconds, to set intervals for often a sound should beep
  	} else if(cm <= distanceThreshold && cm > distanceThreshold - 180){	// This if statement was put in place to make the led light blink when the sensor detects something v
      	digitalWrite(2, HIGH);						// Setting pin 2 to HIGH
    	digitalWrite(3, HIGH);						// Setting pin 2 to HIGH
    	digitalWrite(4, HIGH);						// Setting pin 2 to HIGH
    	digitalWrite(5, HIGH);						// Setting pin 2 to HIGH
		tone(13, 500, 800);							// Activate the Piezo, the tone function takes in three arguments, (which pin) 13, (pitch) 500 and (duration of tone) 800. 
      	delay(100);									// Added a delay for 100 miliseconds, to set intervals for often a sound should beep
        digitalWrite(2, LOW);						// Setting pin 2 to LOW		To make it blink
    	digitalWrite(3, LOW);						// Setting pin 2 to LOW		To make it blink
    	digitalWrite(4, LOW);						// Setting pin 2 to LOW		To make it blink
    	digitalWrite(5, LOW);						// Setting pin 2 to LOW		To make it blink
  	}
  delay(500); 										// Wait for 100 millisecond(s)
}

long readUltrasonicDistance(int triggerPin, int echoPin)	// Function to read distance using the ultrasonic sensor
{
  pinMode(triggerPin, OUTPUT);  					// Clear the trigger
  digitalWrite(triggerPin, LOW);					// Set triggerPin to LOW
  delayMicroseconds(2);								// Small delay to make sure the program does not get stuck  													
  digitalWrite(triggerPin, HIGH);					// Sets the trigger pin to HIGH state for 10 microseconds
  delayMicroseconds(10);			
  digitalWrite(triggerPin, LOW);					// Set the triggerPin back to low 
  pinMode(echoPin, INPUT);			
  return pulseIn(echoPin, HIGH);					// Reads the echo pin, and returns the sound wave travel time in microseconds
}
