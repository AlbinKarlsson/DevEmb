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
        (*mPointX)--;
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
    // Create a new robot
    ROBOT robot = {0, 0, N};

    int *mPointX = &robot.xpos;
    int *mPointY = &robot.ypos;
    enum DIRECTION *dirPoint = &robot.dir;
    char c;
    int stop;

    while (!stop)
    {

        // Ask for the robots starting x postition:
        printf("Enter the starting X coordinate: ");
        scanf(" %d", mPointX);
        if (*mPointX < 0 || *mPointX > 99)
        {
            break;
        }
        c = getchar();

        if (c == 'q')
        {
            break;
        }

        // Ask for the robots starting y position:
        printf("Enter the starting Y coordinate: ");
        scanf(" %d", mPointY);
        if (*mPointX < 0 || *mPointX > 99)
        {
            break;
        }
        c = getchar();

        if (c == 'q')
        {
            break;
        }

        // Enter command t turn direction and command m to move in the current direction
        printf("Enter 't' to turn direction and 'm' for moving one step in the current direction: \n");

        while ((c = getchar()) != 'x')
        {
            if (c == 't')
            {
                turn(dirPoint);
            }
            else if (c == 'm')
            {
                move(mPointX, mPointY, dirPoint);
            }
            else if (c == 'q')
            {
                stop = 1;
                break;
            }
            else if (c == '\n')
            {
                break;
            }
        }
        printLocation(mPointX, mPointY, dirPoint);
    }

    return 0;
}