// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 4
// Exercise 2
// Submission code: 98764 TA Bardha
// See image 'ex2.png'

// Based on the following tutorial: https://www.instructables.com/Arduino-Timer-Interrupts/
#define DATA_RATE 9600// Define data rate for Serial

// used in calculation: compare match register = [ clock speed/ (prescaler * interrupt frequency) ] - 1
#define PRESCALER 1024      // used for dictating speed of timer according to (timer speed (Hz)) = (Arduino clock speed (16MHz)) / prescaler
#define INTERRUPT_FREQ 1    // define interrupt frequency
#define CLOCK_SPEED 16000000// Clock speed of the Arduino Uno
#define TIMER1_MAX 65535    // Max counter value for timer1
#define TIMER1_LOW 257      // Lowest counter value for timer1

const byte SERVO_PIN = 9;   // Define servo pin
int servoPos = 0;           // Initialize servo position to 0
int timer1 = 0;             // Initialize timer1 = 0;
int countTime = 0;           // Initialize countTime = 0;

void setup() {
   pinMode(SERVO_PIN, OUTPUT); // Set servo pin to output
   setup_timer_1();        // Setup timer
   Serial.begin(DATA_RATE);// Begin serial
}


// Overall this function will repearedly move the servo motor to a specific angle, print the value of the iconter variable to the serial monitor, then we stop
// the servo motor. This process will be repeated indefinitely as long as the microcontroller is powered on 

void loop() {                       // A function to execute continuously as long as the microcontroller is powered on 
  digitalWrite(SERVO_PIN, HIGH);    // Using the digitalWrite we can set SERVO_PIN to HIGH 
  delay(1000);                      // A delay for 1000 milliseconds (1 second)
  Serial.print("Time: ");           // Print message
  Serial.println(countTime);        // Print message 
  digitalWrite(SERVO_PIN, LOW);     // Using digitalWrite to set SERVO_PIN to LOW (This will cause the servo motor to stop)
}


// Built on top of: https://www.instructables.com/Arduino-Timer-Interrupts/
void setup_timer_1() {
   cli();//stop interrupts
   TCCR1A = 0;	// set entire TCCR1A register to 0
   TCCR1B = 0;	// same for TCCR1B
   TCNT1 = 0; 	//initialize counter value to 0

   // calculate at which point to stop the counter and set to int:
   timer1 = (CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQ)) - 1;

   if (timer1 >= TIMER1_MAX) {                                                         // if value went above max value
      timer1 = TIMER1_MAX;                                                             // set timer to max allowed value
      Serial.println((String) "timer1 was set too high and was changed to: " + timer1);// Print message
   } else if (timer1 <= TIMER1_LOW) {                                                  // if value went below lowest value
      timer1 = TIMER1_LOW;                                                             // set timer to max allowed value
      Serial.println((String) "timer1 was set too low and was changed to: " + timer1); // Print message
   }

   OCR1A = timer1;                     // set compare match register for 1hz increments
   TCCR1B |= (1 << WGM12);             // turn on CTC mode
   TCCR1B |= (1 << CS12) | (1 << CS10);// set CS10 and CS12 bits for 1024 prescaler
   TIMSK1 |= (1 << OCIE1A);            // enable timer compare interrupt

   sei();                               //allow interrupts
}

// Interrupt 1
// Based on setupTimer1, this ISR will trigger every x second(s)
ISR(TIMER1_COMPA_vect) {
   cli();       //stop interrupts
   countTime++;  // Increment countTime by 1
   sei();       //allow interrupts
}