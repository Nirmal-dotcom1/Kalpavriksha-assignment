/*1. Problem Statement:
Write a program to remove all duplicate characters from a given string. The resulting string 
should retain the order of first appearance of characters and should not contain any duplicate 
letters.
Sample Input and Output:
1. Input: "programming"
Output: "progamin"
2. Input: "banana"
Output: "ban"
3. Input: "abacabad"
Output: "abcd"
*/
#include <stdio.h>

void RemoveDuplicate(char str[100]){
    int flag[100];
    for(int i=0;str[i]!='\0';i++){
        flag[i]=0;
    }
    

    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            continue;
        }
        for(int j=i+1;str[j]!='\0';j++){
            if(str[i]==str[j]){
                flag[j]=1;
            }
        }
    }
    char result[100];
    int index=0;
    for(int i=0;str[i]!='\0';i++){
        if(flag[i]==0){
            result[index++]=str[i];
        }
    }
    printf("The String After Removing The Duplicate Character : ");
    printf("%s",result);
}

int main()
{
    char str[100];
    printf("Enter the String : ");
    scanf("%[^\n]",str);
    
    RemoveDuplicate(str);
    return 0;
}
