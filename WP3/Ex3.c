// C++ code

const byte ROWS = 4;			// Set keypad ROWS to 4 rows
const byte COLS = 4;			// Set keypad COLS to 4 columns
char keys [ROWS][COLS] = {		// This is the keypad matrix
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {11, 10, 9, 8};	// Assign which pins goes to the Rows
byte colPins[COLS] = {7, 6, 5, 4};		// Assign which pins goes to the Cols


void setup () {
      Serial.begin(9600);
      
   for(char r = 0; r < ROWS; r++){
         pinMode(rowPins[r], INPUT);    //set the Row pins as input
         digitalWrite(rowPins[r], HIGH);    //turn on the pullups
   }
   
   for(char c = 0; c < COLS; c++){
         pinMode(colPins[c], OUTPUT);   //set the Column pins as output
   }
   
}


void loop() {
      char key = getKey();
      
      if(key != 0){
   Serial.println(key);
      }
}

char getKey(){				// This function is the function that will scan and detect which key is pressed
      char x = 0;
      for(char c = 0; c < COLS; c++){	// A for loop to set the cols to low
        digitalWrite(colPins[c], LOW);
         for(char r = 0; r < ROWS; r++){	// A for loop to set the rows to low
            if(digitalRead(rowPins[r]) == LOW){
            delay(20);    //20ms debounce time
            while(digitalRead(rowPins[r])== LOW);
            x = keys[r][c];
            }
         }
   digitalWrite(colPins[c], HIGH); 
      }
      return x;
}