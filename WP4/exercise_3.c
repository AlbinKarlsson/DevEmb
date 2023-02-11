#include <Adafruit_NeoPixel.h>
#define PIN 6
#define sensorPinZero A0

// https://arduinogetstarted.com/tutorials/arduino-neopixel-led-strip

float temperature;
float voltage;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);  //12 LEDS, PIN 6, ? ?

int tempReading;
int num, prev_num = 0;


void setup() {
  Serial.begin(9600);
  strip.begin();          // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();           // send the updated pixel colors to the NeoPixel hardware.
  pinMode(10, INPUT);

}

void loop() {
  tempReading = analogRead(sensorPinZero);;
  delay(1000);
  
  Serial.println(tempReading);

  num = map(tempReading, 20, 358, 1, 12);              // Map values from the temp meter to the number of LEDs
  Serial.println("LED Number = " +String(num));
  if(num != prev_num){
    switch_led(strip.Color(0, 0, 0), 0, 12);          // Number of LEDS is 12. Resets all LEDS if temp is lowered.
    switch_led(strip.Color(255, 0, 0), 50, num);      // Set LED to red with delay of 50 ms    
    prev_num = num;                                   // Set previous number to new number

    if(num == 12){
      digitalWrite(10, HIGH);
    } else{
      digitalWrite(10, LOW);
    }
    
    delay(500);
  }
  
} 

void switch_led(uint32_t color, int time, int led_num) { //Set a pixel's color using a 32-bit 'packed' RGB or RGBW value.
  // turn pixels to red one by one with delay between each pixel
  for(int i = 0; i<led_num; i++){
      strip.setPixelColor(i, color);         //Set pixel color of each individual LED
      strip.show();                          // send the updated pixel colors to the NeoPixel hardware.
      delay(time);
  }
}