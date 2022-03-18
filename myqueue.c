#include "myqueue.h"

int front = 0;
int rear = 0;
int capacity = NUM_POINTS;

short peek(){
  return queueArray[front];
}

short dequeue(void){
  if(isEmpty()){
    return 0; //nothing here
  }
  short e = queueArray[front];
  front = (front+1)%capacity;
  return e;
}

void enqueue(short val){
  if(!isFull()){
    queueArray[rear] = val;
    rear = (rear+1)%capacity; 
  }
  else{ //empty oldest element and put in new one
    dequeue();
    enqueue(val);
  }
}

bool isFull(void){
  return (getSize() == capacity-1);
}

bool isEmpty(){
  return (front == rear);
}

int getSize(){
  if(front <= rear){
    return (rear-front);
  }
  else{
    return(capacity+rear-front);
  }
}

// Implemented
//peek
//enqueue
//dequeue
//isfull