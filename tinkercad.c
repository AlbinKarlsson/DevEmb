// Based on the following tutorial: https://www.instructables.com/Arduino-Timer-Interrupts/
#define DATA_RATE 9600// Define data rate for Serial

// used in calculation: compare match register = [ clock speed/ (prescaler * interrupt frequency) ] - 1
#define PRESCALER 1024      // used for dictating speed of timer according to (timer speed (Hz)) = (Arduino clock speed (16MHz)) / prescaler
#define INTERRUPT_FREQ 1    // define interrupt frequency
#define CLOCK_SPEED 16000000// Clock speed of the Arduino Uno
#define TIMER1_MAX 65535    // Max counter value for timer1
#define TIMER1_LOW 257      // Lowest counter value for timer1

const byte SERVO_PIN = 9; // Define servo pin
int servoPos = 0; // Initialize servo position to 0
int timer1 = 0;
int iCounter = 0;

void setup() {
   pinMode(SERVO_PIN, OUTPUT); // Set servo pin to output
   setup_timer_1();        // Setup timer
   Serial.begin(DATA_RATE);// Begin serial
}

void loop() {
  digitalWrite(SERVO_PIN, HIGH);
  delay(1000); 
  Serial.print("Time: ");
  Serial.println(iCounter);
  digitalWrite(SERVO_PIN, LOW);
}


// This function sets up timer1 on an Arduino Uno
// Built on top of: https://www.instructables.com/Arduino-Timer-Interrupts/
// Sets timer1 interrupt at 1Hz = 1 second = 1 cycle per second
void setup_timer_1() {

   cli();//stop interrupts

   TCCR1A = 0;	// set entire TCCR1A register to 0
   TCCR1B = 0;	// same for TCCR1B
   TCNT1 = 0; 	//initialize counter value to 0

   // calculate at which point to stop the counter and set to int:
   timer1 = (CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQ)) - 1;
   //timer1 = (CLOCK_SPEED / (INTERRUPT_FREQ)) - 1;
   // timer1 = 16 000 000 / 65535

   if (timer1 >= TIMER1_MAX) {                                                         // if value went above max value
      timer1 = TIMER1_MAX;                                                             // set timer to max allowed value
      Serial.println((String) "timer1 was set too high and was changed to: " + timer1);// notify user
   } else if (timer1 <= TIMER1_LOW) {                                                  // if value went below lowest value
      timer1 = TIMER1_LOW;                                                             // set timer to max allowed value
      Serial.println((String) "timer1 was set too low and was changed to: " + timer1); // notify user
   }

   OCR1A = timer1;                     // set compare match register for 1hz increments
   TCCR1B |= (1 << WGM12);             // turn on CTC mode
   TCCR1B |= (1 << CS12) | (1 << CS10);// set CS10 and CS12 bits for 1024 prescaler
   TIMSK1 |= (1 << OCIE1A);            // enable timer compare interrupt

   sei();//allow interrupts
}

// Interrupt 1
// Based on setupTimer1, this ISR will trigger every x second(s)
ISR(TIMER1_COMPA_vect) {
   cli();     //stop interrupts
   iCounter++;
   sei();     //allow interrupts
}