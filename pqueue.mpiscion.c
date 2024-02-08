/**
 * This file is the .c file for Programming Assignment #2: Priority Queue
 * This was written by Michael Piscione
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pqueue.mpiscion.h"

/**
 * createThing takes a string and an unsigned integer. The string represents the name of a "Thing",
 * while the weight represents the weight of a "Thing". The name cannot be NULL nor can it have 0 characters
 * or more than 63 characters. If it does, the function returns NULL. The weight must be greater than zero,
 * if it is not, the function returns NULL. Otherwise, the function allocates space in memory for a "Thing",
 * assigns it the name given by the parameter, and assigns it the weight given by the parameter. It returns the
 * pointer to the "Thing".
 * Parameters: char *name, the name of the "Thing", unsigned int weight, the weight of the "Thing".
 * Return: Thing *, a pointer to the "Thing".
*/
// Thing *createThing(char *name, unsigned int weight) {

//     // Check if name is NULL
//     if (name == NULL) {
//       return NULL;  // If-so, return NULL
//     }

//     // Check that the length of the name is greater than zero and less than or equal to 63
//     if (strlen(name) == 0 || strlen(name) > MAX_NAME_LENGTH) {
//         return NULL;  // Return NULL if not
//     }

//     // Check that the weight is greater than zero
//     if (weight <= 0) {
//         return NULL;  // Return NULL if not
//     }

//     // All values validated
//     // Allocate memory for the 'Thing'
//     Thing *ptr = malloc(sizeof(Thing));

//     // Set the weight
//     ptr->weight = weight;

//     // Set the name
//     strcpy(ptr->name, name);

//     // Return ptr if all checks pass
//     return ptr;
// }

/**
 * compareThings takes two "Thing" pointers as parameters. It compares the lexicograpgic ordering of their names.
 * If thingOne precedes thingTwo in this way, it returns -1. If thingOne follows thingTwo in this way, it returns 1.
 * If both names are equal it compares their weights. If thingOne's weight is more than thingTwo's, return 1. If
 * thingOne's weight is less than thingTwo's, return -1. Otherwise they are equal, return 0.
 * Parameters: Two "Thing" pointers representing thingOne and thingTwo.
 * Return: -1, 0, or 1 based on thingOne and thingTwo's comparison (as described above).
*/
int compareThings(Thing *thingOne, Thing *thingTwo) {
    // Get the value from the compared Things (using strcmp)
    int compared = strcmp(thingOne->name, thingTwo->name);

    // Check if the value is positive
    if (compared > 0) {
        return 1;  // If so, return 1
    }

    // Check if the value is negative
    else if (compared < 0) {
        return -1;  // If so, return -1
    }

    // Names are equal
    else {
        // If weight from thingOne > weight from thingTwo return 1
        if (thingOne->weight > thingTwo->weight) {  
            return 1;
        }
        // If weight from thingOne < weight from thingTwo return -1
        else if (thingOne->weight < thingTwo->weight) {
            return -1;
        }
        // The Things are equal, return 0
        else {
            return 0;
        }
    }
}

// The highest-priority element will be the one whose priority value is the smallest
// Maintained in ascending priority order, so that the highest-priority element will be at the front of the list.

/**
 * TODO: enqueue description
*/
int enqueue(PQueueNode **pqueue, int priority, void *data) {
    // Declare local variables
    PQueueNode *curr = *pqueue;
    PQueueNode *prev = NULL;

    // Allocate space for a new node
    PQueueNode *newNode = malloc(sizeof(PQueueNode));

    // Setup new node
    newNode->priority = priority;
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty
    if (curr == NULL) {
        // List is empty, list becomes new node
        *pqueue = newNode;
    }
    else {
        // List is not empty, find where new node should go
        while (curr != NULL && priority >= curr->priority) {
            prev = curr;
            curr = curr->next;
        }
        // New node goes before curr and after prev (if prev is not NULL)
        newNode->next = curr;
        if (prev != NULL) {
            prev->next = newNode;
        }
        else {
            *pqueue = newNode; // New record goes at the front
        }
    }

    // Return 0
    return 0;

}

/**
 * TODO: dequeue description
*/
void *dequeue(PQueueNode **pqueue) {
    // If the queue is empty, return NULL
    if (*pqueue == NULL) {
        return NULL;
    }

    // Declare a variable representing the top of the list
    PQueueNode *queueTop = *pqueue;

    // Take the data from the top of the list
    void *data = queueTop->data;

    // Make the top of the list the next in line
    *pqueue = queueTop->next;
    
    // Free space allocated to the previous top of the list
    free(queueTop);

    // Return the data
    return data;
}

/**
 * TODO: peek description
*/
void *peek(PQueueNode *pqueue) {
    // If the queue is empty, return NULL
    if (pqueue == NULL) {
        return NULL;
    }

    // Return the data at the top of the list
    return pqueue->data;
}

/**
 * TODO: printQueue description
*/
void printQueue(PQueueNode *pqueue, void (printFunction)(void*)) {
    // Set the current node to be the first in the priority queue
    PQueueNode *curr = pqueue;

    // As long as we're not at the end of the list (or that the list isn't empty)
    while(curr != NULL) {
        // Print out the priority
        printf("priority = %u ", curr->priority);

        // Print out the data
        printf("data = ");
        printFunction(curr->data);

        // Go to the next node in the priority queue
        curr = curr->next;
    }
}

/**
 * TODO: getMinPriority description
*/
int getMinPriority(PQueueNode *pqueue) {
    // If the priority queue is empty, return -1
    if (pqueue == NULL) {
        return -1;
    }

    // Return the priority of the first node in the priority queue
    return pqueue->priority;
}

/**
 * TODO: queueLength description
*/
int queueLength(PQueueNode *pqueue) {
    // Declare local variables
    int numNodes = 0;
    PQueueNode *curr = pqueue;

    // While the queue isn't empty
    while (curr != NULL) {
        // Add one to numNodes per node found
        numNodes += 1;

        // Set current node to be the next in the queue
        curr = curr->next;
    }
    return numNodes;
}

/**
 * TODO: printThing description
*/
void printThing(void *data) {
    // Cast void * to Thing *
    Thing *thing = (Thing *) data;

    // Print information
    printf("\"%s\" (%u lbs)\n", thing->name, thing->weight);
}


// int main() {
//     Thing *thing1;
//     Thing *thing2;
//     Thing *thing3;
//     Thing *thing4;
//     Thing *thing5;
//     PQueueNode *pqueue = NULL;

//     thing1 = createThing("thing1", 10);
//     thing2 = createThing("thing2", 1);
//     thing3 = createThing("thing3", 2);
//     thing4 = createThing("thing4", 15);
//     thing5 = createThing("thing5", 8);
//     enqueue(&pqueue, thing1->weight, thing1);
//     printThing(thing1);
//     enqueue(&pqueue, thing2->weight, thing2);
//     printThing(thing2);
//     enqueue(&pqueue, thing3->weight, thing3);
//     printThing(thing3);
//     enqueue(&pqueue, thing4->weight, thing4);
//     printThing(thing4);
//     printf("----------------------------------\n");
//     printQueue(pqueue, printThing);
//     printf("----------------------------------\n");
//     enqueue(&pqueue, thing5->weight, thing5);
//     printThing(thing5);
//     printf("----------------------------------\n");
//     printQueue(pqueue, printThing);
//     printf("----------------------------------\n");
//     printThing(dequeue(&pqueue));
//     printf("----------------------------------\n");
//     printThing(peek(pqueue));
//     printf("----------------------------------\n");
//     printf("The min priority is %u\n", getMinPriority(pqueue));
//     printf("The queue length is %u\n", queueLength(pqueue));
//     printThing(dequeue(&pqueue));
//     printf("The queue length is %u\n", queueLength(pqueue));
    

    

//     return 0;
// }