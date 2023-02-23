// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 5
// Exercise 1
// Submission code: FFF12FFFF
// Se image 'ex1.png'

void setup()                                                                // Initial setup loop
{
  pinMode(2, INPUT);                                                        // Configue pin2 to behave as input
}

int buttonState = 0;                                                        // Initialize button state to 0 at beginning. Not pressed.

void loop()
{
  // Turn led on with an interval of 1 second.  
  digitalWrite(8, HIGH);                                                    // Turn led on
  delay(1000);                                                              // Wait for 1000 millisecond(s)
  digitalWrite(8, LOW);                                                     // Turn led off
  delay(1000);                                                              // Wait for 1000 millisecond(s)

  buttonState = digitalRead(2);                                             // read the state of the pushbutton value
  // check if pushbutton is pressed.  if it is, the buttonState is HIGH
  if (buttonState == HIGH) {                                                    
    digitalWrite(3, HIGH);                                                  // turn LED on
  } else {
    digitalWrite(3, LOW);                                                   // turn LED off
  }
  delay(10);                                                                // Delay a little bit to improve simulation performance
}


