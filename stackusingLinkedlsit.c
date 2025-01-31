#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;

};
struct node* createnode(int val){
        struct node* newnode=malloc(sizeof(struct node));
        newnode->data=val;

        return newnode;
}

struct stack{
    struct node* top;};

void createstack(struct stack *s){
   s->top=NULL; 
}

void peek(struct stack *S){


struct node* peektop=S->top;

if(S->top==NULL){
    return;
}
    printf("Top element Is %d\n",peektop->data);
}

void push(struct stack **s,int val){
    struct node* newnode=createnode(val);
        newnode->next=(*s)->top;
        (*s)->top=newnode;

}

void pop(struct stack *s){
    struct node* temp=s->top;
    if(temp==NULL){
        printf("Stack Is Empty");
    }
    
    s->top=s->top->next;
    free(temp);
}

void printstack(struct stack* s){
     struct node* temp=s->top;
    while (temp)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    
}
int main(){
    struct stack* s=malloc(sizeof(struct stack));
    push(&s,67);
    push(&s,78);
    push(&s,89);
    peek(s);
    pop(s);
    printstack(s);
    return 0;
}