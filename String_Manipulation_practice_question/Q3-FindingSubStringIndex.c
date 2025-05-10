#include <stdio.h>

int CalculateLength(char str[]) {
	int length=0;

	while(str[length]!='\0') {
		length++;
	}
	return length;
}

int FindingIndex(char str[],char sub[],int lenstr,int lensub) {
	int resindex=-1;
	int count=0;
	int flag=0;

	if(lenstr<lensub) {
		return -1;
	}
	for(int i=0; i<lenstr; i++) {
		while(sub[count]==str[i]) {
			count++;
			i++;
			flag=1;
			if(count==lensub) {

				resindex=i-lensub;
				return resindex;
			}

		}
		if(flag) {
			count=0;
			i--;
			flag=0;
		}
	}


	return resindex;
}

int main() {
	char str[100];
	printf("Enter the String : ");
	scanf("%[^\n]",str);
	getchar();
	char sub[100];
	printf("Enter The Substring : ");
	scanf("%[^\n]",sub);

	int lenstr=CalculateLength(str);
	int lensub=CalculateLength(sub);

	int ind=FindingIndex(str,sub,lenstr,lensub);
	printf("%d",ind);

	return 0;
}
