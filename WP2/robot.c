#include <stdio.h>

enum DIRECTION {N,E,S,W};
char direction[5];

//Here the struct is creating a new typ called ROBOT, this has thre variables.Two ints, and one enum called dir
typedef struct {
        int xPos;
        int yPos;
        enum DIRECTION dir;
} ROBOT;

void move(ROBOT *robot) {
        if (robot->dir == N) {
                robot->yPos++;                  // Access and increment the yPos by 1. The -> operator is used to access the variable in the struct 
        } else if (robot->dir == E) {
                robot->xPos++;                  // Access and increment the xPos by 1. The -> operator is used to access the variable in the struct 
        } else if (robot->dir == S) {
                robot->yPos--;
        } else if (robot->dir == W) {
                robot->xPos--;
        }
}

void turn(ROBOT *robot) {   
        if (robot->dir == N) {
                robot->dir = E; 
                *direction = 'E';                 // Access and increment the xPos by 1. The -> operator is used to access the variable in the struct 
        } else if (robot->dir == E) {
                robot->dir = S; 
                *direction = 'S';                 // Access and increment the xPos by 1. The -> operator is used to access the variable in the struct 
        } else if (robot->dir == S) {
                robot->dir = W;
                *direction = 'W';
        } else if (robot->dir == W) {
                robot->dir = N;
                *direction = 'N';
        }      
}

int main() {
        ROBOT robot;            // Initialize Robot robot 
        char c;

        int end = 0;
        while (!end) {
                printf("Enter starting position (x, y): ");
                scanf("%d, %d", &robot.xPos, &robot.yPos);
                robot.dir = N;
                *direction = 'N';
                printf("Deployed position: [ X: %d ],[ Y:%d ], with direction: %s\n", robot.xPos, robot.yPos, &direction);
                printf("Enter string of instructions (m for move, t for turn, x to exit): \n");
                while ((c = getchar()) != 'b') {
                        if (c == 'm') {
                                move(&robot);
                                printf("Robot took one step forward: [ X: %d ],[ Y: %d ] Direction: %s \n", robot.xPos, robot.yPos, &direction);
                        } else if (c == 't') {
                                turn(&robot);
                                printf("*Robot Turned 90 degrees clockwise*  Direction: %s\n", direction);
                        } else if (c == 'b') {
                                end = 1;
                                break;
                        }
                }
                break;
        }
        return 0;
}