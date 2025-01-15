#include <stdio.h>

int CalculateLength(char str[]){
    
    int length=0;
	while(str[length]!='\0') {

	length++;
	}
	return length;
}
void HandleSpace(char *str,int StrLength){
    
    int index = 0;
	for (int i = 0; i <StrLength; i++) {
		while (str[i] == ' ') {
			i++;
		}
		while (str[i] != ' ' && str[i] != '\0') {
			str[index++] = str[i++];
		}
		if (str[i] == ' ' && index > 0) {
			str[index++] = ' ';
		}
	}
	if (index > 0 && str[index - 1] == ' ') {
		index--;
	}

	str[index] = '\0';
}

void CountWord(char str[]){
    
    int Count=1;
    int i=0;
    while(str[i]!='\0'){
        
        if(str[i]==' '){
            Count++;
        }
        i++;
    }
    printf("No. Of Words in the Entered String is : %d",Count);
}

int main()
{
	char str[1000];
	
	printf("Enter The String");
	scanf("%[^\n]",str);
    getchar();
    int StrLength=CalculateLength(str);
    
    HandleSpace(str,StrLength);
    
    CountWord(str);
    
}
