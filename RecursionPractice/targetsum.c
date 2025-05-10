/*  ques  You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

*/




#include<stdio.h>

int solve(int *nums,int numsSize,int target,int index,int sum){

        if(index==numsSize){

            if(sum==target){
            return 1;
            }
            else 
            return 0;
        }

        int plus=solve(nums,numsSize,target,index+1,sum+nums[index]);
        int minus=solve(nums,numsSize,target,index+1,sum-nums[index]);

        return plus+minus;


}

int findTargetSumWays(int* nums, int numsSize, int target) {

    int index=0;
    int sum=0;
    int result=solve(nums,numsSize,target,index,sum);
    return result;

}


int main() {
    int numsSize;
    int target;
    printf("Enter the number of elements: ");
    scanf("%d",&numsSize);
 
 int nums[numsSize];
    printf("Enter the elements of the array: ");
    for (int i=0;i<numsSize;i++) {
        scanf("%d",&nums[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d",&target);

    int result=findTargetSumWays(nums, numsSize, target);
    
    printf("The number of ways is: %d\n", result);

    return 0;
}