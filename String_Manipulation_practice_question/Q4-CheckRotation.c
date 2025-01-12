#include <stdio.h>

int getlen(char str[]) {
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    return len;
}

void CheckRotation(char str1[],char str2[],int len1,int len2){
   
    char temp[200];
    for(int i = 0;i<len1;i++) {
        temp[i] = str1[i];
    }
    for(int i=0; i<len1; i++) {
        temp[len1 + i] = str1[i];
    }
    temp[len1+len2]= '\0';

    int found=0;
    for(int i = 0; i <= len1; i++) {
        int j = 0;
        while(j<len2 && temp[i + j]== str2[j]) {
            j++;
        }
        if(j== len2) {
            found = 1;
            break;
        }
    }
    if(found) {
        printf("true");
    } else{
        printf("false");
    }
}

int main() {
    char str1[100];
    scanf("%[^\n]", str1);
    getchar(); 
    char str2[100];
    scanf("%[^\n]", str2);

    int len1=getlen(str1);
    int len2=getlen(str2);
    if(len1!= len2) {
        printf("false");
        return 1;
    }
    CheckRotation(str1,str2,len1,len2);

    

    return 0;
}
