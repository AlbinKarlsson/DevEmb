// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 2
// Exercise 2
// Submission code: C12CCCCC 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #### Constants #####
#define MAX 5

// ##### typedefs          ####
typedef struct q                                             // define struct for node 
{
    int number;                                              // define a number for each node   
    struct q *next;                                          // define pointer to next node in the list
    struct q *prev;                                          // define pointer to previous node in the list   
} REGTYPE;                                                   // Define the node as REGTYPE

// ##### Function declarations   #####

REGTYPE *random_list(void);                                  // Function to generate a random linked list of 5 nodes
REGTYPE *add_first(REGTYPE *temp, int data);                 // Function declaration to add an item
REGTYPE *print_list(REGTYPE *, REGTYPE *);                   // Added function to print random list and random list with added item

// ###### Main program #######
int main(int argc, char *argv[])
{

    REGTYPE *act_post, *head = NULL;                         // Declaration of pointers to 

    printf("List generated with random nodes: ");
    srand(time(0));                                          // Random seed
    head = random_list();                                    // Set head to take in the linked list of randomly generated numbers
    print_list(act_post, head);                              // Function to print the linked list
    
    printf("\n");

    // Add entry to head
    printf("List with added entry: ");
    int data = rand() % 100 + 1;                             // Generate random number to be assigned to number in the added node in the list
    head = add_first(head, data);                            // Set the head pointer, pointing to the beginning of the list to be set to the added node.
    print_list(act_post, head);                              // Print list of random numbers, with the added node
    
    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL)                        // While loop to free up all allocated memory
    {
        head = act_post->next;                               // Loops through the while linked list by assigning head to the next node of act_post
        free(act_post);                                      // function to free up all allocated memory in list                    
    }

    return 0;
}

// ====     End of main   ======================================

REGTYPE *random_list(void)                                   // Function to generate the linked list
{
    int nr, i = 0;              
    REGTYPE *top, *old, *item;                               // Declaring pointers to first node in list, the previous node and a pointer item to call the node being added to the list
    top = NULL;                                              // Make sure that top is null in when list is empty.                

    while (i < MAX)                                          // Add nodes to list while i is less than MAX
    {                                               
        nr = rand() % 100 + 1;                               // randomize a number to be added to the item nodes number property            
        item = malloc(sizeof(item));                         // Allocate the needed memory of a node to item
        item->number = nr;                                   // Assign the randomly generated number to item
        item->next = NULL;                                   // Set the first added items next pointer to null, since it is the first in the list and does not point to anything.    

        if (top == NULL)                                     // If top is null, items previous pointer will point to null
        {
            item->prev = NULL;                               // If list is empty, the first added nodes prev pointer will point to Null
            top = item;                                      // The head node (top) will then be item, being the first and only node in the list
        }
        else                                                 // If the there is one or more items in the linked list
        {
            old = top;                                       // If top is not null, assign top to be the old node when a second node is added
            old->prev = item;                                // Olds previous pointer will point to the newly added item    
            item->next = old;                                // Items next pointer will then point the old node.    
            top = item;                                      // The new top in the list becomes the last added item node    
        }
        i++;                                                 // Increment until i reaches 4
    }
    return (top);                                            // Return the top node
}

//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data)                  // Function to add node, taking in head pointer and a random number
{
    REGTYPE *addItem = (REGTYPE *)malloc(sizeof(addItem));   // Assign the needed memory for the struct regtype item
    addItem->number = data;                                  // Assign the randomly generated number to the items number property
    temp->prev = addItem;                                    // Set the heads pointer to point to the previous node, which becomes the added item   
    addItem->next = temp;                                    // Set items next pointer to point to the previous head node   

    return (addItem);                                        // return the pointer to the added item   
}

REGTYPE *print_list(REGTYPE *act_post, REGTYPE *head)        // Function to print the linked list   
{
    int nr = 0;                                              // Nr used to show what position each node has in the list   
    act_post = head;                                         // Set act_post to be the head node

    while (act_post != NULL)                                 // Print as long as act_post is not null
    {   
        printf("\n Post nr %d : %d", nr++, act_post->number);// Print location and number of each node in the list  
        act_post = act_post->next;                           // Loop through list and set act_post to the next node in the list iteratively
    }
    printf("\n");
}