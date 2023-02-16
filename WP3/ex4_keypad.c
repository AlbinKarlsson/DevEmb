// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 3
// Exercise 4
// Submission code: D12DDDDD 

// C++ code
// This code corresponds to picture ex3-4.jpeg in the images folder 

#include <Keypad.h>

const byte ROWS = 4;        // Set keypad ROWS to 4 rows 
const byte COLS = 4;        // Set keypad COLS to 4 columns
char keys [ROWS][COLS] = {  // This is the keypad matrix 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {11, 10, 9, 8};  // Assign which pins goes to the Rows 
byte colPins[COLS] = {7, 6, 5, 4};    // Assign which pins goes to the Cols 

Keypad keypad = Keypad (makeKeymap(keys), rowPins, colPins, ROWS, COLS);  // Create an instance of Keypad called keypad and use map to assign pins and byte 

void setup()
{
  Serial.begin(9600);                 // To exchange messages with the Serial monitor with given 9600 bits per second 
}

void loop()                           // Keeps looping over until executing program 
{
	char key = keypad.getKey();         // Store output from keypad.getKey() function and store in key
  	if (key != NO_KEY){               // If key is not "NO_KEY", in other words no value then dont execute 
    	Serial.println(key);            // Print out key 
    }
}