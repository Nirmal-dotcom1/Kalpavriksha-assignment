/*
9.Problem Statement:
Write a program to remove all instances of a specific character from a string.
Sample Input and Output:
1. Input: string = "banana", char = 'a'
Output: "bnn"
2. Input: string = "hello world", char = 'l'
Output: "heo word"
3. Input: string = "abcdef", char = 'x'
Output: "abcdef"
*/

#include <stdio.h>

void RemoveChar(char str[],char Alpha) {
	int flag[100];
	for(int i=0; str[i]!='\0'; i++) {
		flag[i]=0;
	}
	int i=0;
	while(str[i]!='\0') {
		if(str[i]==Alpha) {
			flag[i]=1;
		}
		i++;
	}
	int index=0;
	for(int i=0; str[i]!='\0'; i++) {
		if(flag[i]==0)
			str[index++]=str[i];
	}
	str[index]='\0';
	printf("The String After Modification \n");
	printf("%s",str);
}

int main()
{
	char str[100];
	printf("Enter The String : ");
	scanf("%[^\n]",str);
	
    getchar();
	
    char Alpha;
	printf("Enter the Char : ");
	scanf("%c",&Alpha);
	
    RemoveChar(str,Alpha);


	return 0;
}
