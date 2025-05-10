/*Given an array of positive integers and a positive integer Target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/


#include<stdio.h>
#include<stdlib.h>

int MinSubArrayLen(int *Array,int Target,int NoOfElement){
    int left=0;
    int curr_sum=0;
    int res=1000;
    
    for(int right=0;right<NoOfElement;right++){
        curr_sum+=Array[right];
        
        while(curr_sum>=Target){
            if(res>right-left+1){
                res=right-left+1;
            }
            curr_sum=curr_sum-Array[left];
            left++;
        }
    }
    return res;
}

int main(){
    int NoOfElement;
    printf("Enter Number Of element in Array : ");
    scanf("%d",&NoOfElement);

    int *Array=(int *)malloc(NoOfElement * sizeof(int));
  printf("Enter Values of Array : \n");
    for(int i=0;i<NoOfElement;i++){
        scanf("%d",&Array[i]);
    }
    int Target;
    printf("Enter the Target Sum");
    scanf("%d",&Target);
    int MinLen=MinSubArrayLen(Array,Target,NoOfElement);
    printf(" The minimum subArray len is : %d",MinLen);
}
