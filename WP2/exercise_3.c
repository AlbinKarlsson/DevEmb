#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[14]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void);             // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and
// writes the first record
void printfile(void);                 // Prints out all persons in the file
void search_by_firstname(char *name); // Prints out the person if
// in list
void append_file(PERSON *inrecord); // appends a new person to the file

int main(void)
{
    int operation;
    PERSON ppost;
    PERSON test = {"John", "Doe", "190123094098"};
    PERSON *ppointer;
    ppointer = (PERSON *)malloc(1 * sizeof(ppost));
    int quit = 0;

    while (true)
    {

        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");

        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            *ppointer = test;
            write_new_file(ppointer);
            break;

        case 2:
            printf("Add a first name: ");
            scanf("%s", ppost.firstname);

            printf("Add a family name: ");
            scanf("%s", ppost.famname);

            printf("Add a personal number: ");
            scanf("%s", ppost.pers_number);
            append_file(&ppost);
            break;

        case 3:
            char name[20];
            char *pname = name;
            printf("Search for a person with a first or family name: \n");
            scanf("%s", name);
            search_by_firstname(pname);
            break;

        case 4:

            printfile();
            break;

        case 5:
            exit(0);
        }
    }

    return (0);
}

void write_new_file(PERSON *inrecord)
{
    if (remove("myTestFile.bin") == 0)
        printf("Deleted file successfully \n");
    else
        printf("Unable to delete the file");

    // file which we will create
    FILE *pFileToCreate;

    // location to my file
    char *strFilename = "myTestFile.bin";

    // open the file to write
    pFileToCreate = fopen(strFilename, "wb");

    if (!pFileToCreate)
    {
        printf("Unable to open file!");
    }

    fwrite(inrecord, sizeof(PERSON), 1, pFileToCreate);
    fclose(pFileToCreate);
}

void append_file(PERSON *inrecord)
{
    FILE *fileToOpen;

    fileToOpen = fopen("myTestFile.bin", "ab");

    if (!fileToOpen)
    {
        printf("Unable to open file!");
    }

    fwrite(inrecord, sizeof(PERSON), 1, fileToOpen);

    fclose(fileToOpen);
}

void printfile(void)
{

    FILE *pFileToRead;

    PERSON myRecord;

    pFileToRead = fopen("myTestFile.bin", "rb");

    if (!pFileToRead)
    {
        printf("Unable to open file!");
    }

    while (fread(&myRecord, sizeof(PERSON), 1, pFileToRead) == 1)
    {
        printf("Firstname: %s\n", myRecord.firstname);
        printf("Surname: %s\n", myRecord.famname);
        printf("Personal number: %s\n", myRecord.pers_number);
        printf("\n");
    }

    fseek(pFileToRead, 0L, SEEK_END);
    long size = ftell(pFileToRead);
    if (size == 0)
    {
        printf("File is empty!");
    }

    fclose(pFileToRead);
}

void search_by_firstname(char *name)
{

    int found = 0;
    FILE *pFileToRead;

    PERSON myRecord;

    pFileToRead = fopen("myTestFile.bin", "rb");

    if (!pFileToRead)
    {
        printf("Unable to open file!");
    }

    while (fread(&myRecord, sizeof(PERSON), 1, pFileToRead) == 1)
    {
        if (strcmp(name, myRecord.firstname) == 0 || strcmp(name, myRecord.famname) == 0)
        {
            found = 1;
            printf("Firstname: %s\n", myRecord.firstname);
            printf("Surname: %s\n", myRecord.famname);
            printf("Personal number: %s\n", myRecord.pers_number);
        }
    }
    if (found == 0)
        printf("\n Person not found in the file \n");

    fseek(pFileToRead, 0L, SEEK_END);
    long size = ftell(pFileToRead);
    if (size == 0)
    {
        printf("File is empty!");
    }
    fclose(pFileToRead);
}