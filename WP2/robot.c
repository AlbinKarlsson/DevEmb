// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 2
// Exercise 1
// Submission code: C12CCCCC 


#include <stdio.h>

enum DIRECTION {N,E,S,W};                               // Enum creation for N E S W 
char direction[5];                                      // Initializing a variable for priting direction for user

//Here the struct is creating a new typ called ROBOT, this has thre variables.Two ints, and one enum called dir
typedef struct {
        int xPos;
        int yPos;
        enum DIRECTION dir;
} ROBOT;

void move(ROBOT *robot) {                               // Function to call for moving the Robot
        if (robot->dir == N) {                          // If the direction is N, execute the following
                robot->yPos++;                          // Access and increment the yPos by 1. The -> operator is used to access the variable in the struct 
        } else if (robot->dir == E) {                   // If the direction is E, execute the following
                robot->xPos++;                          // Access and increment the xPos by 1. The -> operator is used to access the variable in the struct 
        } else if (robot->dir == S) {                   // If the direction is S, execute the following 
                robot->yPos--;                          // Access and reduce the yPos by 1 
        } else if (robot->dir == W) {                   // If the direction is W, execute the following
                robot->xPos--;                          // Access and reduce the xPos by 1 
        }
}

void turn(ROBOT *robot) {                               // The turn function, with the passing value of the pointer value of robot 
        if (robot->dir == N) {                          // If the robot direction is N, do the following 
                robot->dir = E;                         // Set new direction to E in robot
                *direction = 'E';                       // The pointer for direction will now have value E  
        } else if (robot->dir == E) {                   // If the robot direction is E, do the following  
                robot->dir = S;                         // Set new direction to S in robot
                *direction = 'S';                       // The pointer for direction will now have value S 
        } else if (robot->dir == S) {                   // If the robot direction is S, do the following 
                robot->dir = W;                         // Set new direction to W in robot
                *direction = 'W';                       // The pointer for direction will now have value W 
        } else if (robot->dir == W) {                   // If the robot direction is W, do the following 
                robot->dir = N;                         // Set new direction to N in robot
                *direction = 'N';                       // The pointer for direction will now have value N
        }      
}

int main() {
        ROBOT robot;                                                    // Initialize Robot robot 
        char c;                                                         // Initialize variable c for commands later. User will use this char ariable for commands, steering the robot 
        int end = 0;                                                    // Initialize variable end, this will be used for the loop. To make sure the loop continues 
        while (!end) {                                                  // A while loop to make the program continue 
                printf("Enter starting position (x, y): \n");
                scanf("%d, %d", &robot.xPos, &robot.yPos);              // Take input from the user, getting the coordinates for the robots starting position 
                if((robot.xPos < 0 || robot.xPos > 99) || (robot.yPos < 0 || robot.yPos > 99)){         // Checking and making sure the inputs are valid withing 0 - 99 for both x and y, if not run error message
                        printf("Not valid starting position. Try again between 0 - 99 ex: (10,30) \n");
                        continue;                                       // Continue if invalid to let user try again 
                } else {
                        robot.dir = N;                                  // Starting direction is N always
                        *direction = 'N';                               // Make sure to use that input to display for the user
                        printf("Deployed position: [ X: %d ],[ Y:%d ], with direction: %s\n", robot.xPos, robot.yPos, &direction);
                        printf("Enter string of instructions (m for move, t for turn, b to exit): \n");
                        while ((c = getchar()) != 'b') {                // As long as c is not b this loop will continue, and checking the input from the user using getchar()
                                if (c == 'm') {                         // If input is 'm' do the following 
                                        move(&robot);                   // Call the move functon, passing the robot address 
                                        printf("Robot took one step forward: [ X: %d ],[ Y: %d ] Direction: %s \n", robot.xPos, robot.yPos, &direction);
                                } else if (c == 't') {                  // If the input is 't' do the following 
                                        turn(&robot);                   // Call the turn function and pass the robot address
                                        printf("*Robot Turned 90 degrees clockwise*  Direction: %s\n", direction);
                                } else if (c == 'b') {                  // If the input is 'b' do the following 
                                        end = 1;                        // Set end to 1
                                        break;                          // Break out
                                }
                        }
                }

                break;                                                  // Break loop 
        }
        return 0;                                                       // Return 0 end of program 
}