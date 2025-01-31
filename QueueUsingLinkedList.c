#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* next;
};

struct node* createnode(int val){

struct node* newnode=malloc(sizeof(struct node));
newnode->data=val;

return newnode;

}

struct queue{
    struct node* front;
    struct node* rear;
};

struct queue* createqueue(){
    struct queue* q = malloc(sizeof(struct queue));
    q->rear=q->front=NULL;
    return q;
}

void enq(struct queue **q,int value){

    struct node* newnode=createnode(value);

    if((*q)->rear==NULL){
        (*q)->rear=newnode;
        (*q)->front=newnode;
    }
    (*q)->rear->next=newnode;
    (*q)->rear=newnode;

}

void deq(struct queue **q){

    struct node* temp=(*q)->front;

    if(temp==NULL){
        (*q)->rear=NULL;
        printf("underflow");
        return;
    }

   (*q)->front =(*q)->front ->next;

    free(temp);

    
}

void printq(struct queue **q){

    struct node* temp=(*q)->front;

    while(temp->next){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){

struct queue* q=createqueue();
enq(&q,45);
enq(&q,34);
enq(&q,32);
enq(&q,54);
enq(&q,44);
enq(&q,78);
deq(&q);
deq(&q);



printq(&q);
    // createqueue()

    return 0;

}