#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
    
};

void insertatbeg(struct node** head,int val){

    struct node* newnode=malloc(sizeof(struct node));
    
    newnode->data=val;

    if(*head==NULL){
        (*head)=newnode;
        (*head)->next=NULL;
        (*head)->prev=NULL;
        // (*head)=tail;
        return;
        
    }

    (*head)->prev=newnode;
    newnode->prev=NULL;
    newnode->next=(*head);
    (*head) = newnode;
}

void insertatend(struct node** head,int val){

    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=val;

    if(*head==NULL){
        (*head)=newnode;
        (*head)->next=NULL;
        (*head)->prev=NULL;
        return;
        
    }
    struct node* temp=*head;

    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;

}

void insertatmiddle(struct node** head,int val){

    if((*head)==NULL){
        return;
    }
    struct node* slow=*head;
    struct node* fast=*head;

    while(fast &&fast->next ){
        slow=slow->next;
        fast=fast->next->next;
    }

    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=val;

    
    slow->prev->next=newnode;
    newnode->prev=slow->prev;
    slow->prev=newnode;
    newnode->next=slow;
    

    
}

void deletefrombeg(struct node** head){
    
    if(*head==NULL){
        return;
    }
    
    if((*head)->next==NULL){
        *head=NULL;
        return;
    }
    struct node* temp=*head;
    
    *head=(*head)->next;
    (*head)->prev=NULL;
    
    free(temp);
}

void deletefromlast(struct node** head ){
        struct node* temp=*head;
        while(temp->next){
            temp=temp->next;
        }

        temp->prev->next=NULL;

        temp->prev=NULL;
        free(temp);
}


void deletefromMiddle(struct node** head){

     if (*head == NULL || (*head)->next == NULL)
      return;

    struct node* slow=*head;
    struct node* fast=*head;

    while(fast &&fast->next ){
        slow=slow->next;
        fast=fast->next->next;
    }

   if (slow->prev)
    slow->prev->next = slow->next;
    if (slow->next) 
    slow->next->prev = slow->prev;

    free(slow);

}

void countNodes(struct node** head){
    struct node* temp=*head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }

    printf("Total Number OF Nodes : %d\n",count);
}

void traverselefttoright(struct node** head){

    struct node* temp=*head;
    printf("Left To Right Traversal \n");
    while(temp){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void traverserighttoleft(struct node** head){

    struct node* temp=*head;
    while(temp->next){
        temp=temp->next;
    }
     printf("Right to Left Traversal \n");
    while(temp){
        printf("%d->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}

void printlist(struct node** head){
        struct node* temp=*head;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
}




int main(){

    struct node* head=NULL;

    insertatbeg(&head,56);
    insertatbeg(&head,78);
    insertatend(&head,65);
     insertatbeg(&head,4);
    insertatbeg(&head,32);
    insertatend(&head,23);
    insertatmiddle(&head,7834);
    insertatmiddle(&head,72);
    printlist(&head);


     countNodes(&head);
        traverselefttoright(&head);
        traverserighttoleft(&head);

    

    return 0;

}
