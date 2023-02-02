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
char moveInput[5];

void turn(enum DIRECTION *dirPoint)
{
    if (*dirPoint == 0)
    {
        *dirPoint = 1;
        printf("Print out east: %d \n", *dirPoint);
    }
    else if (*dirPoint == 1)
    {
        printf("Print out South: %d \n", *dirPoint);
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

void printLocation(int *mPointX, int *mPointY, enum DIRECTION *dirPoint)
{
    printf("X-position: %d, Y-position: %d ", *mPointX, *mPointY);
    if (*dirPoint == 0)
    {
        printf("%s", "Direction: N");
    }
    else if (*dirPoint == 1)
    {
        printf("%s", "Direction: O");
    }
    else if (*dirPoint == 2)
    {
        printf("%s", "Direction: S");
    }
    else if (*dirPoint == 3)
    {
        printf("%s", "Direction: W");
    }
    printf("%s", "\n");
}

int main()
{
    int x;
    // Create a new robot
    ROBOT robot = {0, 0, N};

    int *mPointX = &robot.xpos;
    int *mPointY = &robot.ypos;
    enum DIRECTION *dirPoint = &robot.dir;

    while (1)
    {

        // Ask for the robots starting x postition:
        printf("Enter the starting X coordinate: ");
        scanf("%d", mPointX);
        if (*mPointX < 0 || *mPointX > 99)
        {
            break;
        }
        x = getchar();
        if (x == 'Q' || x == 'q')
        {
            break;
        }

        // Ask for the robots starting y position:
        printf("Enter the starting Y coordinate: ");
        scanf("%d", mPointY);
        if (*mPointX < 0 || *mPointX > 99)
        {
            break;
        }

        x = getchar();
        if (x == 'Q' || x == 'q')
        {
            break;
        }

        // Enter command t turn direction and command m to move in the current direction
        printf("Enter 't' to turn direction and 'm' for moving one step in the current direction: ");
        scanf("%s", moveInput);

        if (strcmp(moveInput, "Q") == 0 || strcmp(moveInput, "q") == 0)
        {
            break;
        }

        if (strcmp(moveInput, "t") == 0)
        {
            turn(dirPoint);
        }
        else if (strcmp(moveInput, "m") == 0)
        {
            move(mPointX, mPointY, dirPoint);
        }

        printLocation(mPointX, mPointY, dirPoint);
    }

    return 0;
}