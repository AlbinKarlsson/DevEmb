// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 3
// Exercise 3
// Submission code: D12DDDDD 

// C++ code
// This code corresponds to picture ex3-4.jpeg in the images folder 

const byte ROWS = 4;                            // Set keypad ROWS to 4 rows
const byte COLS = 4;                            // Set keypad COLS to 4 columns
char keys[ROWS][COLS] = {                       // This is the keypad matrix
    {'1', '2', '3', 'A'},     
    {'4', '5', '6', 'B'},     
    {'7', '8', '9', 'C'},     
    {'*', '0', '#', 'D'},     
};    

byte rowPins[ROWS] = {11, 10, 9, 8};            // Assign which pins goes to the Rows
byte colPins[COLS] = {7, 6, 5, 4};              // Assign which pins goes to the Cols

void setup()      
{     
      Serial.begin(9600);                       // To exchange messages with the Serial monitor with given 9600 bits per second

      for (char r = 0; r < ROWS; r++)
      {
            pinMode(rowPins[r], INPUT);         // set the Row pins as input
            digitalWrite(rowPins[r], HIGH);     // turn on the pullups
      }

      for (char c = 0; c < COLS; c++)
      {
            pinMode(colPins[c], OUTPUT);        // set the Column pins as output
      }
}

void loop()
{                                               // Keeps looping over until executing program
      char key = getKey();                      // Store getKey() value to key
      if (key != 0)                             // If value of key is not 0 then execute
      {
            Serial.println(key);                // Print key 
      }
}

char getKey()
{                                               // This function is the function that will scan and detect which key is pressed
      char x = 0;                               // Declaring variable x that will be used to store the value of pressed key
      for (char c = 0; c < COLS; c++)
      {                                         // A for loop to iterate for size of COLS
            digitalWrite(colPins[c], LOW);      // A function to set the state (HIGH or LOW). It takes two arguments pin number and the state
            for (char r = 0; r < ROWS; r++)     // A for loop to iterate for size of ROWS
            { 
                  if (digitalRead(rowPins[r]) == LOW)
                  {                             // The code checks the input pin (rowPins[r]) to see if it is LOW, which would indicate that a key has been pressed.
                        delay(20);              // 20ms debounce time
                        while (digitalRead(rowPins[r]) == LOW)
                              ;                 // The loop continues to execute until the digitalRead function returns a value of HIGH, (A key has been released)
                        x = keys[r][c];         // This assigns the value stored
                  }
            }
            digitalWrite(colPins[c], HIGH);     // This function will set the state to HIGH     
      }
      return x;
}