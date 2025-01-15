#include <stdio.h>

int CalculateLength(char string[]) {

	int length=0;
	while(string[length]!='\0') {
		length++;
	}

	return length;
}

void sortString(char *string) {

	for(int i=0;string[i]!='\0'; i++) {
		for(int j=i+1; string[j]!='\0'; j++) {
			if(string[i]>string[j]) {
				char temp=string[i];
				string[i]=string[j];
				string[j]=temp;
			}
		}
	}
}

int stringEqual(char string1[],char string2[],int length){
    
    for(int i=0;i<length;i++){
        if(string1[i]!=string2[i])
        return 0;
    }
    
    return 1;
}
void checkAnagram(char string1[],char string2[]) {

	int len1=CalculateLength(string1);
	int len2=CalculateLength(string2);

	if(len1!=len2) {
		printf("These are not Anagrams");
		return;
	}

	sortString(string1);
	sortString(string2);

	if(stringEqual(string1,string2,len1)) {
		printf("These are Anagrams");
	}
	else {
		printf("These are not Anagrams");
	}

}
int main()
{
	char str1[100];
	printf("Enter The first String : ");

	scanf("%[^\n]",str1);

	char str2[100];
	getchar();
	printf("Enter The second String : ");

	scanf("%[^\n]",str2);

	checkAnagram(str1,str2);

	return 0;

}
