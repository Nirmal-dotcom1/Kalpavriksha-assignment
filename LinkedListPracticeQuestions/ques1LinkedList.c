#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

int countoccurence(struct ListNode* head){
    int count=0;
    
    if(head==NULL){
        return count;
    }
    
    struct ListNode* curr=head;
    while(curr){
        if(curr->data==42){
            count++;
        }
        curr=curr->next;
    }
    
    return count;
}


struct ListNode* createlist(){
    int n;
    printf("enter No of Node : ");
    scanf("%d",&n);
    
    if(n==0){
        return NULL;
    }
    
    printf("Enter The data Of Nodes \n");
    struct ListNode* head=malloc(sizeof(struct ListNode));
    scanf("%d",&head->data);
    head->next=NULL;
    
    struct ListNode* curr=head;
    
    while(n!=1){
        struct ListNode* temp=malloc(sizeof(struct ListNode));
        scanf("%d",&temp->data);
        curr->next=temp;
        curr=temp;
        n--;
    }
    curr->next=NULL;
    
    return head;
    
}

int main() {
    struct ListNode* head=createlist();
    struct ListNode* temp=head;
    printf("Original LIST \n");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    
   int result=countoccurence(head);
    printf("\nThe No, of occurencce of 42 is : %d",result);
    
    return 0;
}
