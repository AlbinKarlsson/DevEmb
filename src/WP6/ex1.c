// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 6
// Exercise 1
// Submission code: ZZZ12ZZZ
// See image 'ex1_DCMotor.png' in the images folder

// Define constants for various pins
#define ENCA 2 // Define PIN 2 as ENCA (encoder signal from motor)
#define ENCB 3 // Define PIN 3 as ENCB (encoder signal from motor)
#define PWM1 5 // Define PIN 5 as PWM1 (Writing speed clockwise direction)
#define PWM2 6 // Define PIN 6 as PWM2 (Writing speed counter clockwise direction)

// Define variables
int pos = 0;       // Position in ticks
int deg = 0;       // Position in degrees
int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed
int kp = 5;    // Proportional constant for controller (tuning parameter)
int u_out = 0; // Output of controller
int e = 0;     // Error

volatile int a = 0;      // a-encoder signal
volatile int b = 0;      // b-encoder signal
volatile int last_a = 0; // Last a-encoder signal

// Set up the initial configuration
void setup()
{
    Serial.begin(9600);                                                    // Establish serial communication
    pinMode(ENCA, INPUT_PULLUP);                                           // Enable input to ENCA and activation of internal resistor to keep signal in HIGH state
    pinMode(ENCB, INPUT_PULLUP);                                           // Enable input to ENCB and activation of internal resistor to keep signal in HIGH state
    pinMode(PWM1, OUTPUT);                                                 // Set PWM1 to output to be able to write to it with speed
    pinMode(PWM2, OUTPUT);                                                 // Set PWM2 to output to be able to write to it with speed
    attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, CHANGE); // Attach the interrupt to ENCA and activate it on CHANGE state
    analogWrite(PWM1, 10);                                                 // Write 10 to PWM1 not to crash TinkerCad
    delay(1000);                                                           // Set delay of 1 second
    analogWrite(PWM2, 10);                                                 // Write 10 to PWM2 not to crash TinkerCad
}

// This is the main loop of the program

void loop()
{
    // Set PMW1 and PWM2 to 10 to prevent TinkerCad from crashing
    analogWrite(PWM1, 10);
    delay(20);
    analogWrite(PWM2, 10);

    // Add 0 to the current degree in each iteration
    deg = deg + 0;

    // Check if motor rotated all the way around, and reset the counter accordingly
    if (deg > 359)
    {
        deg = deg - 359;
    }
    if (deg < 0)
    {
        deg = 359 + deg;
    }

    // Get the input degree from the user
    degtarget = getInput();

    // Calculate the initial error between the target degree and the current degree
    e = degtarget - deg;

    // Loop until the error is zero
    while (e)
    {
        // Get the necessary speed signal to correct the error
        speed = getAction(e);

        // Send the speed signal to the motor
        if (speed >= 0)
        {
            // If the speed is too low, set it to 100
            if (speed < 100)
                speed = 100;

            // Set PWM2 to off and PWM1 to the calculated speed
            analogWrite(PWM2, 0);
            analogWrite(PWM1, speed);
        }
        // If the necessary speed signal is negative, rotate the motor counter-clockwise
        else
        {
            // If the speed is too low, set it to -100
            if (-speed < 100)
                speed = -100;

            // Set PWM1 to off and PWM2 to the absolute value of the calculated speed
            analogWrite(PWM1, 0);
            analogWrite(PWM2, -speed);
        }

        // Calculate the new error between the target degree and the current degree
        e = degtarget - deg;
    }

    // Check if the motor rotated all the way around, and reset the counter accordingly
    if (deg >= 360)
    {
        deg = deg - 359;
    }
    if (deg < 0)
    {
        deg = 359 + deg;
    }

    // Print the current position to the serial monitor
    Serial.print("The current position is: ");
    Serial.print(deg);
    Serial.print("\n");
}

// This function gets the user input from the serial monitor and returns it as an integer
int getInput()
{
    int ready = 0;
    char buf[3];
    int input = -1;
    Serial.print("Please enter the desired position: \n");

    // Wait until input is ready
    while (!ready)
    {
        ready = Serial.readBytes(buf, 4); // read up to 4 bytes from serial buffer
        input = atoi(&buf[0]);            // convert bytes to integer
    }
    return input;
}
// This function calculates and returns the output signal based on the error and proportional gain (kp)
int getAction(int error)
{
    // Calculate the output signal by multiplying the error with the proportional constant
    u_out = error * kp;
    // Limit the output signal to a range of -255 to 255 to prevent overflow
    if (u_out > 255)
    {
        return 255;
    }
    else if (u_out < -255)
    {
        return -255;
    }
    else
    {
        return u_out;
    }
}

// This function is an interrupt service routine that reads the encoder signals and updates the current position (deg)
void ISR_readEncoder()
{
    a = digitalRead(ENCA);
    b = digitalRead(ENCB);

    if (b != a)
    {
        pos++;                           // increment position
        deg = map(pos, 0, 2299, 0, 359); // map position to degrees
    }
    else
    {
        pos--;                           // decrement position
        deg = map(pos, 0, 2299, 0, 359); // map position to degrees
    }
}