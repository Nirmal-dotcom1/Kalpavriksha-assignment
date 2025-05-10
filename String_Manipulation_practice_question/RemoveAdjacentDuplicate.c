/*Remove Adjacent Duplicates
Problem Statement:
Write a program to remove adjacent duplicate characters in a string recursively until no 
adjacent duplicates remain.
Sample Input and Output:

2. Input: "abbaca"
Output: "ca"
Explanation: Removing "bb" → "aaca", then removing "aa" → "ca".
*/

// aabbddbccd
// abbaca
// a top 1
// b top =1 top 2
// b top 3
#include <stdio.h>

void RemoveAdjDuplicate(char str[],char stack[],int top){
    // char res[100];
	for(int i=0; str[i]!='\0'; i++) {
		stack[++top]=str[i];

		if(top>=1 && stack[top]==stack[top-1]) {
			top--;
			top--;
		}
	}

	stack[top+1]='\0';

printf("After Modification : \n");
	printf("%s",stack);
}

int main() {

	char str[100];
	printf("Enter The String : ");
	scanf("%[^\n]",str);

	getchar();

	char stack[100];
	int top=-1;

	RemoveAdjDuplicate(str,stack,top);

	return 0;
}


