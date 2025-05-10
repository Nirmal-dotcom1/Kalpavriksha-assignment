#include <stdio.h>

void CountFreq(char string[]) {
	int countarr[26]= {0};

	for(int i=0; string[i]!='\0'; i++) {
		countarr[string[i]-'a']++;
	}
	int index=0;
	for(int i=0; i<26; i++) {
		if(countarr[i]>0) {
			printf("%c",i+97);
			printf("%d",countarr[i]);
		}
	}
}

int main()
{
  char string[100];
	printf("Enter The string : ");
	scanf("%[^\n]",string);
  
  CountFreq(string);
  return 0;
}
