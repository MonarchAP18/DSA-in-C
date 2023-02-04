#include <stdio.h>
# define size 69
struct Queue{
    char queue[size];
    int front;
    int back;
};

void initQueue(struct Queue *q){
 (*q).front=-1;
 (*q).back=-1;
 for(int i=0; i<size; i++){
  (*q).queue[i]='0';
 }
}
void enqueue(struct Queue *q, char item, int sz){
    if((*q).front>=){
        printf("\nStack Overflow");
    }else{
        if(item==0){
        printf("\nerror");
        }else{
            (*s).top+=1;
            (*s).stack[(*s).top]=item;
        }
    }
}