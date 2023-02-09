#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

void copyString(char *dest, char *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

int main(int argc, char *argv[])
{
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    if (argc == 1)
    {
        printf("Enter a string (max %d characters): ", MAX_LEN - 1);
        scanf("%s", str1);
    }
    else if (argc == 2)
    {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("Error opening file %s\n", argv[1]);
            return 1;
        }
        fgets(str1, MAX_LEN, fp);
        fclose(fp);
    }
    else
    {
        printf("Too many arguments.\n");
        return 1;
    }

    strcpy(str2, str1);
    printf("Copied string using strcpy: %s\n", str2);

    copyString(str2, str1);
    printf("Copied string using custom function: %s\n", str2);

    return 0;
}