#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>
#define NUM_POINTS               100
#define QUEUE_SIZE               NUM_POINTS+1

/*Circular queue implementation*/

//Fxn declarations
unsigned short peek(void);
unsigned short dequeue(void);
void enqueue(unsigned short val);
bool isFull(void);
bool isEmpty(void);
int getSize(void);

//Array based data structure
extern unsigned short queueArray[1];

//Store front and rear index
//extern needed to avoid double declaration when header is included in multiple compilation units
extern int front;
extern int rear;
extern int capacity;


#endif