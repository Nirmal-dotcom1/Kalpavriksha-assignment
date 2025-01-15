/* 
7.Problem Statement:
Write a program to find the longest word in a given sentence. Assume words are separated by 
spaces.
Sample Input and Output:
1. Input: "The quick brown fox jumps"
Output: "jumps"
2. Input: "Hello world"
Output: "Hello"
3. Input: "a abc abcd"
Output: "abcd"
*/

#include<stdio.h>

int FindLongest(char str[],int *index) {
	int max=0;


	int i=0;
	while(str[i]!='\0') {
		int count=0;
		while(str[i]!=' ' && str[i]!='\0' ) {
			count++;
			i++;
		}

		if(count>max) {
			max=count;
			*index=i-max;
		}


		if(str[i]==' ' ) {
			i++;
		}

	}
	return max;
}

int main()
{
	char str[1000];
	scanf("%[^\n]",str);

	int index=0;
	int maxi=FindLongest(str,&index);
	char arr2[100];
	int j=0;
	for(int i=index; i<index+maxi; i++) {
		arr2[j++]=str[i];
	}
	arr2[j]='\0';

	printf("%s",arr2);

	return 0;
}


