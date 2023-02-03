// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 2
// Exercise 3
// Submission code: C12CCCCC 

#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h>
#include <string.h>
 
int selection = 0;

// -----typedefs ------- 
typedef struct {                                            // Here we create a struct called PERSON with three values
        char firstname[20];                                 // Firstname with type char
        char famname[20];                                   // famname with type char
        char pers_number[13]; // yyyymmddnnnc                  pers_number of type char
} PERSON; 
 
PERSON input_record(void){
    
}                                  // Reads a person’s record. 


void write_new_file(PERSON *inrecord){
    FILE *fp;                                               // Create instance of FILE called fp with assigned pointer
    fp = fopen("records.bin", "ab");                        // Open file with given address and assign to value fp
    if(fp == NULL){                                         // If file fp is NULL execute exit function 
        printf("Error opening the file\n");
        exit(1);                                            // Exit the program
    }   

    fwrite(inrecord, sizeof(PERSON), 1,fp);                 // Add a new ppost called inrecord in this function to file fp
    fclose(fp);                                             // close file function with passing value of fp

}  // Creates a file and  

// writes the first record 
void printfile(void){
    PERSON record;                                          // Create instance of PERSON name record
    FILE *fp;                                               // Create instance of FILE with pointer to fp
    fp = fopen("records.bin", "ab");                        // Open file fp 
    fp = fopen("records.bin", "rb");                        // Open file fp
    if(fp == NULL){                                         // If file fp does not exist then we print a message 
        printf("Error, file does not exist");        
        exit(1);
    }


    while(fread(&record, sizeof(PERSON), 1, fp) == 1) {     // While loop through the file fp, iterate through each ppost in fp
        printf("|---------------------------------------------|\n");
        printf("|Firstname:         %s\n", record.firstname);
        printf("|Surname:           %s\n", record.famname);
        printf("|Personal number:   %s\n", record.pers_number);
    }
    printf("|---------------------------------------------|\n");

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    if (size == 0)                                          // if size of fp is 0 then print message and then back to menu 
    {
        printf("File is empty!\n");
    }
    fclose(fp);                                             // Close the file with passed value of fp 
}

void search_by_firstname(char *name){                       // This function will allow the user to pass a string (name or family name) and search in the file for a match
    printf("Find using firstname: %s\n", name);
    PERSON record;                                          // create instance record from struct Person 
    FILE *fp;                                               // Create instance *fp from FILE 
    fp = fopen("records.bin", "rb");                        // Assign, which address for a file to open, to fp

    while(fread(&record, sizeof(PERSON), 1, fp) == 1) {     // A loop to iterate through all data
        if((strcmp(record.firstname, name)== 0) || strcmp(record.famname, name)== 0){ // if there is a match with a name or lastname then print that match
            printf("|---------------------------------------------|\n");
            printf("|Firstname:         %s\n", record.firstname);
            printf("|Surname:           %s\n", record.famname);
            printf("|Personal number:   %s\n", record.pers_number);
            break;                                          // Break out of the while loop when there is a match
        }
    }
    fclose(fp);                                             // Close the file with the passed variable fp
}

void append_file(PERSON *inrecord){                         // this function will take an argument passed to it which is a ppost
    remove("records.bin");                                  // We want to remove this a specific file, with the given name
    FILE *fp;                                               // Point to fp from FILE 
    fp = fopen("records.bin", "ab");                        // assign which file address to open to variable fp
    if(fp == NULL){                                         // If fp file does not exist it will throw an error 
        printf("Error opening the file\n");
        exit(1);
    }   
    fwrite(inrecord, sizeof(PERSON), 1,fp);                 // Attatch new created object to the file, this case file fp
    fclose(fp);                                             // File close function, close the fp file 
}

void clrscr()                                               // Here we created a clrscreen function
{
    system("@cls||clear");                                  // This will clear the terminal
}

int main(void){                                             // Declare a PERSON struct called ppost
    PERSON ppost;                                           // Initializing a variable called choice to keep track of a while loop depending on choice
    char choice = 'Y';                                      // As long s value of choice is Y, loop the menu choices
    while(choice == 'Y'){
        printf("1: Create a new and delete the old file\n2: Add a new person in the file\n3: Search for a person in the file\n4: Print out all in the file\n5: Exit program\n");
        scanf("%d", &selection);
        clrscr();                                           // Make it cleaner by clearing the terminal, using a clearing function 
        switch (selection) {                                // Switch case function for each choice 
            case 1:                                         // Case 1 out of 4 + default
                PERSON dummy = {"John", "Doe", "199904223478"};  // Assging 'dummy' data to ppost
                append_file(&dummy);                        // Send the address of ppost to the function append_file 
                break;                                      // Break after executing this case
            case 2:                                         // Case 2 out of 4 + default
                printf("Add a new person in the file\n");
                printf("New persons name: \n");
                scanf("%s", ppost.firstname);               // Take input and store in ppost.firstname
                printf("New persons surname: \n");
                scanf("%s", ppost.famname);                 // Take input and store in ppost.famname
                printf("New persons date of birth (yyyymmddxxxx): \n");
                scanf("%s", ppost.pers_number);             // Take input and store in ppost.pers_number
                write_new_file(&ppost);                     // Send the address of ppost to the functiion write_new_file
                break;                                      // Break after executing this case
            case 3:                                         // Case 3 out of 4 + default
                char name[20];                              // Initializing a char array called name 
                printf("Search for a person in the file\n");
                printf("Persons name: \n");
                scanf("%s", name);                          // Assign the input string to name
                search_by_firstname(name);                  // Use the input name and send to the function search_by_firstname
                break;                                      // Break after executing this case
            case 4:                                         // Case 4 out of 4 + default
                printf("Print out all in the file\n\n");
                printfile();                                // Call the printfile function
                break;                                      // Break after executing this case
            default:                                        // Default case if none of the cases are called 
                printf("Exit program... ");
                exit(1);                                    // Exit the program 
        }
        printf("Do you want to go to main menu? \n(Y/N): ");
        scanf(" %c", &choice);                              // Check input value for choice 
    }
    return 0;
} 

