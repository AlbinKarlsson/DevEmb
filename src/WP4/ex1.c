#include <TimerOne.h>

// Define the LED pins
#define LED1 3
#define LED2 4
#define LED3 5
#define LED4 6
#define LED5 7

// Define the temperature sensor pin
#define TEMP_SENSOR A2

// Define the temperature thresholds
#define TEMP_1 0
#define TEMP_2 25
#define TEMP_3 50
#define TEMP_4 75

// Define the interval for the interrupt
#define INTERVAL_MICROSECONDS 2000000 // 2 seconds in microseconds

// Define variables to keep track of time and temperature
int temperature = 0;

void setup() {
  // Set the LED pins to output mode
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  //Initialize serial communication with a baud rate of 9600 bits per second
  Serial.begin(9600);

  // Initialize Timer1
  Timer1.initialize(INTERVAL_MICROSECONDS); 

  // Attach the "readTemperature" function to the Timer1 interrupt
  Timer1.attachInterrupt(readTemperature);
}

void loop() {
  // Control the LEDs based on the temperature
  // Check if the temperature is below the first threshold
  if (temperature < TEMP_1) {
    digitalWrite(LED1, HIGH); // Turn on Led 1, leave the rest off
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
  // Check if the temperature is between the first and second thresholds
  else if (temperature >= TEMP_1 && temperature < TEMP_2) {
    digitalWrite(LED1, HIGH); // Turn on Led 1
    digitalWrite(LED2, HIGH); // Turn on Led 2, leave the rest off
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
  // Check if the temperature is between the second and third thresholds
  else if (temperature >= TEMP_2 && temperature < TEMP_3) {
    digitalWrite(LED1, HIGH); // Turn on Led 1
    digitalWrite(LED2, HIGH); // Turn on Led 2
    digitalWrite(LED3, HIGH); // Turn on Led 3, leave the rest off
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
  // Check if the temperature is between the third and fourth thresholds
  else if (temperature >= TEMP_3 && temperature < TEMP_4) {
    digitalWrite(LED1, HIGH); // Turn on Led 1
    digitalWrite(LED2, HIGH); // Turn on Led 2
    digitalWrite(LED3, HIGH); // Turn on Led 3
    digitalWrite(LED4, HIGH); // Turn on Led 4, leave 5 off
    digitalWrite(LED5, LOW);
  }
  // Check if the temperature is above the fourth threshold
  else if (temperature >= TEMP_4) {
    digitalWrite(LED1, HIGH); // Turn on Led 1
    digitalWrite(LED2, HIGH); // Turn on Led 2
    digitalWrite(LED3, HIGH); // Turn on Led 3
    digitalWrite(LED4, HIGH); // Turn on Led 4
    digitalWrite(LED5, HIGH); // Turn on Led 5
  }
}

// Update the temperature every time the interrupt is engaged
void readTemperature() {
  // Read the temperature sensor
  int sensor = analogRead(TEMP_SENSOR);

  // Convert the analog reading to voltage
  float voltage = (sensor / 1024.0) * 5.0;

  // Convert the voltage to temperature in Celsius
  temperature = (voltage - 0.5) * 100;

  // Print the temperature to the serial monitor
  Serial.println(temperature);
}