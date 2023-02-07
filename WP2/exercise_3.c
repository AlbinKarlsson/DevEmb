#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// -----typedefs -------
typedef struct                                                                  // Make person struct
{
    char firstname[20];                                                         // Declare firstname string
    char famname[20];                                                           // Declare famname string
    char pers_number[14]; // yyyymmddnnnc                                       // Declare personal number string
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
    int operation;                                                              // Declare operation int to be used in while loop
    PERSON ppost;                                                               // Declare person 
    PERSON test = {"John", "Doe", "190123094098"};                              // Declare dummy person to be loaded into file                                                                          

    while (true)
    {

        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");

        scanf("%d", &operation);                                                // Scan to check operation for switch case.

        switch (operation)                                                      // Decleration of switch case
        {
        case 1:                                                                 // Case 1 declared for question 1                                                  // Make ppointer point to the dummy person
            write_new_file(&test);                                           // Send ppointer to the write_new_file
            break;                                                              // Break case

        case 2:                                                                 // Case 2 declared for question 2
            printf("Add a first name: ");               
            scanf("%s", ppost.firstname);                                       // Save input as firstname of ppost

            printf("Add a family name: ");              
            scanf("%s", ppost.famname);                                         // Save input as famname of ppost

            printf("Add a personal number: ");              
            scanf("%s", ppost.pers_number);                                     // Save input as personal number ppost
            append_file(&ppost);                                                // send ppost to append_file function
            break;                                                              

        case 3:
            char name[20];                                                      // Declare char string called name
            char *pname = name;                                                 // Declare pname pointer pointing to name string
            printf("Search for a person with a first or family name: \n");
            scanf("%s", name);                                                  // Save input of the search for firstname or famname
            search_by_firstname(pname);                                         // Take in firstname in the search_by_firstname function
            break;

        case 4:                                                                 // Case 4 is assigned to question 4 which is to print all people

            printfile();                                                        // Calls printfile function that prints all people in the file
            break;

        case 5:
            exit(0);                                                            // Calls exit function to quit the program
        }
    }

    return (0);                                                                 // returns 0 in end of main
}

void write_new_file(PERSON *inrecord)                                           // Decleration of write_new_file function that creates and deletes files. It also puts the dummy person into the file
{
    if (remove("myTestFile.bin") == 0)                                          // If remove of file is successful print a message, of not print that it was not successful
        printf("Deleted file successfully \n"); 
    else
        printf("Unable to delete the file");


    FILE *pFileToCreate;                                                        // File which we create                                               

    char *strFilename = "myTestFile.bin";                                       // Location of file that we create


    pFileToCreate = fopen(strFilename, "wb");                                   // Open the file to write to it

    if (!pFileToCreate)                                                         // If file does not exist, it cannot be opened, print message
    {
        printf("Unable to open file!\n");
        exit(0);                                                                // Exit the program if the file does not exist                                                      
    }

    fwrite(inrecord, sizeof(PERSON), 1, pFileToCreate);                         // Write to inrecord in file, size of Person, size of 1 Person and the file.
    fclose(pFileToCreate);                                                      // Close the file when done
}

void append_file(PERSON *inrecord)                                              // Append person with append_file method
{
    FILE *fileToOpen;                                                           

    fileToOpen = fopen("myTestFile.bin", "ab");

    if (!fileToOpen)
    {
        printf("Unable to open file!\n");
        exit(0);
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
        printf("File is empty! \n");
        exit(0);
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
            printf("\n");
        }
    }
    if (found == 0)
        printf("\n Person not found in the file \n");

    fseek(pFileToRead, 0L, SEEK_END);
    long size = ftell(pFileToRead);
    if (size == 0)
    {
        printf("File is empty! \n");
        exit(0);
    }
    fclose(pFileToRead);
}