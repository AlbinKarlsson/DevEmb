#include <stdio.h>

enum DIRECTION {N,E,S,W};

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
                robot->dir = E;                  // Access and increment the yPos by 1. The -> operator is used to access the variable in the struct 
        } else if (robot->dir == E) {
                robot->dir = S;                  // Access and increment the xPos by 1. The -> operator is used to access the variable in the struct 
        } else if (robot->dir == S) {
                robot->dir = W;
        } else if (robot->dir == W) {
                robot->dir = N;
        }      
}

int main() {
        ROBOT robot;            // Initialize Robot robot 
        char c;                 
        int end = 0;
        while (!end) {
                printf("Enter starting position (x, y): ");
                scanf("%d, %d", &robot.xPos, &robot.yPos);
                printf("Deployed position: [ X: %d ],[ Y:%d ]\n", robot.xPos, robot.yPos);
                robot.dir = N;
                printf("Enter string of instructions (m for move, t for turn, x to exit): \n");
                while ((c = getchar()) != 'b') {
                        if (c == 'm') {
                                move(&robot);
                                printf("Robot took one step forward: [ X: %d ],[ Y:%d ]\n", robot.xPos, robot.yPos);
                        } else if (c == 't') {
                                turn(&robot);
                                printf("*Robot Turned 90 degrees clockwise*\n");
                        } else if (c == 'b') {
                                end = 1;
                                break;
                        }
                }
                break;
        }
        return 0;
}