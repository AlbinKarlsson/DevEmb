#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
 
int selection = 0;

// -----typedefs ------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 
 
// Function declaration (to be extend)  
PERSON input_record(void);             // Reads a person’s record. 


void write_new_file(PERSON *inrecord){
    FILE *fp;
    fp = fopen("records.bin", "ab");
    if(fp == NULL){
        printf("Error opening the file\n");
        exit(1);
    }   

    fwrite(inrecord, sizeof(PERSON), 1,fp);
    fclose(fp);

}  // Creates a file and  

// writes the first record 
void printfile(void){
    PERSON record;
    FILE *fp;

    fp = fopen("records.bin", "rb");
    if(fp == NULL){
        printf("Error, file empty");
        exit(1);
    }

    while(fread(&record, sizeof(PERSON), 1, fp) == 1) {
        printf("|---------------------------------------------|\n");
        printf("|Firstname:         %s\n", record.firstname);
        printf("|Surname:           %s\n", record.famname);
        printf("|Personal number:   %s\n", record.pers_number);
    }
    printf("|---------------------------------------------|\n");
    fclose(fp);
}     // Prints out all persons in the file 

void search_by_firstname(char *name){
    printf("Find using firstname: %s\n", name);
    
    PERSON record;
    FILE *fp;
    fp = fopen("records.bin", "rb");

    while(fread(&record, sizeof(PERSON), 1, fp) == 1) {
        if(strcmp(record.firstname, name)== 0){
            printf("|---------------------------------------------|\n");
            printf("|Firstname:         %s\n", record.firstname);
            printf("|Surname:           %s\n", record.famname);
            printf("|Personal number:   %s\n", record.pers_number);
            break;
        }
    }
    fclose(fp);

} // Prints out the person if in list  

void append_file(PERSON *inrecord){

    remove("records.bin");
    FILE *fp;
    fp = fopen("records.bin", "ab");
    if(fp == NULL){
        printf("Error opening the file\n");
        exit(1);
    }   

    fwrite(inrecord, sizeof(PERSON), 1,fp);
    fclose(fp);


}    // appends a new person to the file 

void clrscr()
{
    system("@cls||clear");
}

int main(void){ 
    PERSON ppost;    
    char choice = 'Y';
    while(choice == 'Y'){
        printf("1: Create a new and delete the old file\n2: Add a new person in the file\n3: Search for a person in the file\n4: Print out all in the file\n5: Exit program\n");
        scanf("%d", &selection);
        clrscr();

        switch (selection) {
            case 1:
                printf("Add a new person to a new file\n");
                printf("New persons name: \n");
                scanf("%s", ppost.firstname);
                printf("New persons surname: \n");
                scanf("%s", ppost.famname);
                printf("New persons date of birth (yyyymmddxxxx): \n");
                scanf("%s", ppost.pers_number);
                append_file(&ppost);
                break;
            case 2:
                printf("Add a new person in the file\n");
                printf("New persons name: \n");
                scanf("%s", ppost.firstname);
                printf("New persons surname: \n");
                scanf("%s", ppost.famname);
                printf("New persons date of birth (yyyymmddxxxx): \n");
                scanf("%s", ppost.pers_number);
                write_new_file(&ppost);
                break;  
            case 3:   
                char name[20];          
                printf("Search for a person in the file\n");
                printf("Persons name: \n");
                scanf("%s", name);
                search_by_firstname(name);
                break;
            case 4: 
                printf("Print out all in the file\n\n");
                printfile();
                break;
            default: 
                printf("Exit program... ");
                exit(1);
        }
        printf("Do you want to go to main menu? \n(Y/N): ");
        scanf(" %c", &choice);
    }
    return 0;
} 
