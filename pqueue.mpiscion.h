/**
 * This file is the .h file for Programming Assignment #2: Priority Queue
 * This was written by Michael Piscione
*/
#ifndef PQUEUE_MPISCION_H
#define PQUEUE_MPISCION_H

// Define constants
#define MAX_NAME_LENGTH 63

// Define structs
// Thing struct
typedef struct {
    unsigned int weight;
    char name[1 + MAX_NAME_LENGTH];
} Thing;

// Priority queue node struct
typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;

// Function Declarations

// Declare createThing
// Thing *createThing(char *name, unsigned int weight);

// Declare compareThings
int compareThings(Thing *thingOne, Thing *thingTwo);

// Declare enqueue
int enqueue(PQueueNode **pqueue, int priority, void *data);

// Declare dequeue
void *dequeue(PQueueNode **pqueue);

// Declare peek
void *peek(PQueueNode *pqueue);

// Declare printQueue
void printQueue(PQueueNode *pqueue, void (printFunction)(void*));

// Declare getMinPriority
int getMinPriority(PQueueNode *pqueue);

// Declare queueLength
int queueLength(PQueueNode *pqueue);

// Declare printThing
void printThing(void *data);


#endif