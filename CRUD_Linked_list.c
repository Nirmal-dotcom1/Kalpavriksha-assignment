#include<stdio.h>
#include<stdlib.h>

struct SinglyLinkedList{
    int Data;
    struct SinglyLinkedList* next;

};

void Addatbeginning(struct SinglyLinkedList **head){
    struct SinglyLinkedList* newHead=malloc(sizeof(struct SinglyLinkedList));
    int val;
    printf(" \n Enter The Data you want to Insert at the beginning : ");
    scanf("%d",&val);
    newHead->Data=val;

    newHead->next=*head;
    *head=newHead;

}

void AddatEnd(struct SinglyLinkedList **head){
    struct SinglyLinkedList *newNode=malloc(sizeof(struct SinglyLinkedList));
    int val;
    printf("\nEnter The Data you want to Insert at End : ");
    scanf("%d",&val);
    newNode->Data=val;

    if(*head==NULL){
        *head=newNode;
        return;
        }
        
        struct SinglyLinkedList* TempPtr=*head;
        while(TempPtr->next){
            TempPtr=TempPtr->next;
        }

        TempPtr->next=newNode;
        newNode->next=NULL;
}


void addAtposition(struct SinglyLinkedList **head){
    struct SinglyLinkedList *prevptr=*head;
    struct SinglyLinkedList *currentptr=malloc(sizeof(struct SinglyLinkedList));

    int position;
    printf("\nEnter the position yo insert the node : ");
    scanf("%d",&position);

    int count=0;
    struct SinglyLinkedList *temp=*head;
    while(temp){
        temp=temp->next;
        count++;
    }

    if(position>count+1 || position<=0){
        printf("\nEnter valid position");
        return;
    }

    int val;
    printf("\nEnter The Data you want to Insert : ");
    scanf("%d",&val);
    currentptr->Data=val;

    if (position == 1) {
        currentptr->next = *head;
        *head= currentptr;
        return;
    }


    for(int i=1;i<position-1;i++){
        prevptr=prevptr->next;
    }

    
    currentptr->next=prevptr->next;
    prevptr->next=currentptr;

}

// void updateAtbeginning(struct SinglyLinkedList *head){
//         int newval;
//         printf("\nEnter the updated data");
//         scanf("%d",&newval);

//         if(head==NULL){
//             printf("\nCannot update the data");
//             return;
//         }

//         head->Data=newval;
// }


// void updateAtEnd(struct SinglyLinkedList **head){

//     struct SinglyLinkedList *temp=*head;

//     int newval;
//         printf("\nEnter the updated data");
//         scanf("%d",&newval);

//     while(temp->next){
//         temp=temp->next;
//     }

//     temp->Data=newval;
// }

void updateAtposition(struct SinglyLinkedList **head){

    struct SinglyLinkedList *currPtr=*head;

    int position;
    printf("\nEnter the position where to update");
    scanf("%d",&position);

    int count=0;
    struct SinglyLinkedList *temp=*head;
    while(temp){
        temp=temp->next;
        count++;
    }

    if(position>count || position<=0){
        printf("\nEnter valid position");
        return;
    }

    int newval;
    printf("\nEnter The Data you want to update: ");
    scanf("%d",&newval);

    //  if (position==1) {
    //     currPtr->Data=newval;
 //     return;
    // }
    
    for(int i=1;i<position;i++){
        currPtr=currPtr->next;
    }

    currPtr->Data=newval;


}
void DisplayList(struct SinglyLinkedList *head){

    if(head==NULL){
        printf("\nEmpty List");
    }

    while(head){
        printf("%d",head->Data);
        if(head->next!=NULL){
            printf("->");
        }
        else {
            printf("->NULL");
        }
        head=head->next;
    }
}

void deleteAtbeginning(struct SinglyLinkedList** head){
       struct SinglyLinkedList* temp=*head;
        if(temp==NULL){
        printf("\nInvalid Operation");
        return;
    }

       *head=temp->next;

       free(temp);
}

void deleteAtEnd(struct SinglyLinkedList **head){
    struct SinglyLinkedList* temp=*head;
        if(temp==NULL){
        printf("\nInvalid Operation");
        return;
    }
    struct SinglyLinkedList* prev=NULL;
    while(temp->next){
        prev=temp;
        temp=temp->next;

    }

    if(prev!=NULL){
        prev->next=NULL;
    }
    else{
        *head=NULL;
    }

free(temp);

}

void deleteAtPosition(struct SinglyLinkedList **head) {
    struct SinglyLinkedList* temp = *head;

    if (temp == NULL) {
        printf("\nInvalid Operation: List is empty\n");
        return;
    }

    int position;
    printf("\nEnter The Position Where to perform Delete Operation: ");
    scanf("%d",&position);

    int count=1;
    while(temp) {
        if(count==position) {
            if(count==1) {
                *head=temp->next; 
                free(temp);          
                return;
            }
            struct SinglyLinkedList* prev=*head;
            for (int i=1; i<position-1;i++) { 
                prev=prev->next;
            }
            temp=prev->next;
            prev->next=temp->next;
            free(temp);
            return;
        }
        temp=temp->next;
        count++;
    }

    printf("\nInvalid Position\n");
}


int main(){
    
struct SinglyLinkedList* head=NULL;

int noOfOperation;
printf("Enter The No. of operation To be Performed");
scanf("%d",&noOfOperation);

while(noOfOperation--){
    int choice;
    printf("\n1.Add new element at the end of the list.\n");
    printf("2.Add new element at the beginning the list.\n");
    printf("3.Add a new element at a specific position in the list.\n");
    printf("4.Display The Linked List.\n");
    printf("5.Update the value of the element at a specific position\n");
    printf("6.Delete The Element at the Beginning.\n");
    printf("7.Delete The Element at the End\n");
    printf("8.Delete Element at a specificc Position.\n");
    printf("Enter your Choice : ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                AddatEnd(&head);
                break;

            case 2 : 
                Addatbeginning(&head);
                break;

            case 3 : 
            addAtposition(&head);
            break;

            case 4 : DisplayList(head);
            break;

            case 5 : updateAtposition(&head);
            break;

            case 6 : deleteAtbeginning(&head);
            break;

            case 7 : deleteAtEnd(&head);
            break;

            case 8 : deleteAtPosition(&head);
            break;

            default:
            printf("Enter a Valid Choice ");
                break;
            }
}


}
