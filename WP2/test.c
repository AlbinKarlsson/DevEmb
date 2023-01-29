#include <stdio.h>

int main()
{
    int x;

    while(x != 'q')
    {
        printf("Enter the integer: ");
        x = getchar();

        //clear buffer or do this
        getchar(); //this is required to avoid taking newline '\n'
                   //as the input (i.e. when you hit enter)
    }

    return 0;
}