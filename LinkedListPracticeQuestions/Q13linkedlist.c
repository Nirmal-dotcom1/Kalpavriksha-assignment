
#include<stdlib.h>
#include<stdio.h>



struct ListNode{
    int data;
    struct ListNode* next;
};

struct ListNode* deleteNode(struct ListNode* head){
    
    int k;
    printf("Enter index of The node to be deleted");
    scanf("%d",&k);
    
    struct ListNode* curr=head;
    
    struct ListNode* prev=NULL;
    
    for(int i=0;i<k;i++){
        prev=curr;
        curr=curr->next;
    }
    
    prev->next=curr->next;
    free(curr);
    
    return head;
}

struct ListNode* createList(int arr[],int n){
    
    struct ListNode* head=malloc(sizeof(struct ListNode));
    
    head->data=arr[0];
    head->next=NULL;
    struct ListNode* curr=head;
    
    for(int i=1;i<n;i++){
        struct ListNode* temp=malloc(sizeof(struct ListNode));
        temp->data=arr[i];
        curr->next=temp;
        curr=temp;
        temp->next=NULL;
    }

    return head;
}
int main()
{
   int n;
   scanf("%d",&n);
   
   int Arr[n];
   
   for(int i=0;i<n;i++){
       scanf("%d",&Arr[i]);
   }
   
   struct ListNode* head=createList(Arr,n);
   struct ListNode* temp=head;
   while(temp){
       printf("%d ",temp->data);
       temp=temp->next;
   }
   
   struct ListNode* newhead=deleteNode(head);
    temp=newhead;
   while(temp){
       printf("%d ",temp->data);
       temp=temp->next;
   }

    return 0;
}
