#include<stdlib.h>
#include<stdio.h>


  struct ListNode {
      int data;
     struct ListNode *next;
  };
 
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* temp=head;
    int n=0;
    while(temp){
        n++;
        temp=temp->next;
    }
   if(n==0){
    return head;
   }
     k=k%n;
    if(k==0 || head==NULL){
        return head;
    }
    struct ListNode* curr=head;
    struct ListNode* prev=NULL;
    struct ListNode* front=head;

    for(int i=0;i<n-k;i++){
        prev=front;
        front=front->next;
    }

    prev->next=NULL;

    struct ListNode* last=front;

    while(last->next){
        last=last->next;
    }

    last->next=head;
    head=front;
    return head;
}

struct ListNode* createlist(){
    int n;
    printf("enter No of Node : ");
    scanf("%d",&n);
    
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
    int k;
    printf("\nEnter number of rotation : ");
    scanf("%d",&k);
    
    struct ListNode* newhead=rotateRight(head,k);
    printf("after rotation \n");
    temp=newhead;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    return 0;
}