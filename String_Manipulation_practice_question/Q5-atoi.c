/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int checkDigit(char ch) {
	return ch>='0' && ch<='9';
}

void stringToInt(char str[]) {
	int num=0;
	int itr=0;
	int negative=0;
	int countHypen=0;

	while(str[itr]!='\0') {

		if(str[itr]!='-' && checkDigit(str[itr])==0 ) {
// 			printf("%d",num);
			break;
		}
		if(str[itr]=='-') {
			negative=1;
			countHypen++;
			itr++;

		}
		if(countHypen>1) {
			num=0;
			break;
		}
		while(checkDigit(str[itr] )) {
			num=num*10 + (str[itr]-'0');
			itr++;
		}
		if(negative) {
			num=-num;
		}

	}

	printf("%d",num);

}
int main()
{
	char str[100];
	printf("Enter The String : ");

	scanf("%[^\n]",str);

	stringToInt(str);
	return 0;

}
