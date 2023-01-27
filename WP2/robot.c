#include <stdio.h>
#include <stdio.h>
#include <string.h>

// Robots directions
enum DIRECTION
{
    N,
    O,
    S,
    W
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

char t[1];
char m[1];
char end[] = "X";
char moveInput[5];

void turn(enum DIRECTION *dirPoint)
{
    if (*dirPoint == 0)
    {
        *dirPoint = 1;
    }
    else if (*dirPoint == 1)
    {
        *dirPoint = 2;
    }
    else if (*dirPoint == 2)
    {
        *dirPoint = 3;
    }
    else if (*dirPoint == 3)
    {
        *dirPoint = 0;
    }
}

void move(int *mPointX, int *mPointY, enum DIRECTION *dirPoint)
{
    if (*dirPoint == 0)
    {
         (*mPointY)++;
    }
    else if (*dirPoint == 1)
    {
        (*mPointX)++;
    }
    else if (*dirPoint == 2)
    {
         (*mPointY)--;
    }
    else if (*dirPoint == 3)
    {
         (*mPointY)--;
    }
}

void printLocation(int *mPointX, int *mPointY, enum DIRECTION *dirPoint){
     printf("X-position: %d, Y-position: %d ", *mPointX, *mPointY);
     if(*dirPoint == 0){
        printf("%s", "Direction: N");
     } else if(*dirPoint == 1){
        printf("%s", "Direction: O");
     } else if(*dirPoint == 2){
        printf("%s", "Direction: S");
     } else if(*dirPoint == 3){
        printf("%s", "Direction: W");
     }
      printf("%s", "\n");
}

int main()
{

    // Create a new robot
    ROBOT robot = {0, 0, N};

    int *mPointX = &robot.xpos;
    int *mPointY = &robot.ypos;
    enum DIRECTION *dirPoint = &robot.dir;

    // Ask for the robots starting x postition:
    printf("Enter the starting X coordinate: ");
    scanf("%d", mPointX);

    // Ask for the robots starting y position:
    printf("Enter the starting Y coordinate: ");
    scanf("%d", mPointY);

    // Enter command t turn direction and command m to move in the current direction
    printf("Enter 't' to turn direction and 'm' for moving one step in the current direction: ");
    scanf("%s", moveInput);

    if (strcmp(moveInput, "t") == 0)
    {
        turn(dirPoint);
    }
    else if (strcmp(moveInput, "m") == 0)
    {
        move(mPointX, mPointY, dirPoint);
    }

    printLocation(mPointX, mPointY, dirPoint);


    return 0;
}