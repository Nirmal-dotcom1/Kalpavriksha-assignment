#include <stdio.h>
int ispalindrome(char str[],int start,int end) {

	while(start<=end) {
		if(str[start]!=str[end])
			return 0;
		start++;
		end--;
	}
	return 1;
}

void LongestSubstring(char str[]) {
	int len=0;
	int max=0;
	int stindex=0;
	int endindex=0;
	for(int i=0; str[i]!='\0'; i++) {
		for(int j=i; str[j]!='\0'; j++) {
			if(ispalindrome(str,i,j)) {
				//   printf("%d",i);
				len=j-i+1;
				if(len>max) {
					max=len;
					stindex=i;
					endindex=j;
				}
			}
		}
	}
	char ans[100];
	int ind=0;
	for(int i=stindex; i<=endindex; i++) {
		ans[ind++]=str[i];
	}
	ans[endindex-stindex+1]='\0';
	printf("The Longest Plaindromic Substring Is : \n");
	printf("%s",ans);
	
}
int main()
{	char str[100];
	printf("Enter The String : ");
	scanf("%s",str);
	LongestSubstring(str);

return 0;
}
