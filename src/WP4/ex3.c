#include <Adafruit_NeoPixel.h>
#define PIN 6               // Define PIN 6 to be used for input from the Neopixel
#define sensorPinZero A0    // Define A0 as sensorPinZero

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);  //Initilize the newpixel and use strip as the neopixel object

int tempReading;           // Declare the variable for reading temperature 
int num, prev_num = 0;     // Initilize num, and prev_num to 0 

void setup() {
  Serial.begin(9600);     // Initilaz      
  strip.begin();          // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();           // send the updated pixel colors to the NeoPixel hardware.
  pinMode(10, INPUT);     // Set 

}

void loop() {
  tempReading = analogRead(sensorPinZero);            // Read temperature on analog pin 0
  delay(1000);                                        // Delay for 1 second 
  

  num = map(tempReading, 20, 358, 1, 12);             // Map values from the temp meter to the number of LEDs
  if(num != prev_num){                                // If num does not equal the previous number (led) on the Neopixel.
    switch_led(strip.Color(0, 0, 0), 0, 12);          // Number of LEDS is 12. Resets all LEDS if temp is lowered.
    switch_led(strip.Color(255, 0, 0), 50, num);      // Set LED to red with delay of 50 ms    
    prev_num = num;                                   // Set previous number to new number

    if(num == 12){                                    // When led 12 is activated, lighten the red LED.
      digitalWrite(10, HIGH);                         // Write to pin 10 to activate the red PIN.
    } else{
      digitalWrite(10, LOW);                          // If led 12 not activated on the Neopixel, turn the red LED off.   
    }
    delay(500);                                       // Delay of 500 ms.
  }
  
} 

void switch_led(uint32_t color, int time, int led_num) {          //Set a pixel's color using a 32-bit 'packed' RGB or RGBW value.
  // turn pixels to red one by one with delay between each pixel
  for(int i = 0; i<led_num; i++){                                 // Loop through the number of 
      strip.setPixelColor(i, color);                              // Set pixel color of each individual LED
      strip.show();                                               // Send the updated pixel colors to the NeoPixel hardware.
      delay(time);                                                 // Delay with the given time passed to the function
  }
}