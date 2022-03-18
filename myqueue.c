#include "myqueue.h"

int front = 0;
int rear = 0;
int capacity = NUM_POINTS;

unsigned short peek(){
  return queueArray[front];
}

unsigned short dequeue(void){
  if(isEmpty()){
    return 0; //nothing here
  }
  unsigned short e = queueArray[front];
  front = (front+1)%capacity;
  return e;
}

void enqueue(unsigned short val){
  if(!isFull()){
    queueArray[rear] = val;
    rear = (rear+1)%capacity; 
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

//TODO: implement
//peek
//enqueue
//dequeue
//isfull