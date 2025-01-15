#include <stdio.h>

int LongestSubString(char str[100]){
   
   
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    int Result = 0;
    int visited[256] = {0};

    for(int i= 0;i<len;i++) {
        for(int j =0;j<256; j++) {
            visited[j] = 0;
        }

        for(int j=i;j<len; j++) {
            if(visited[str[j]]==1) {  
                break;  
            }

            visited[str[j]]=1; 
            int currentLength=j - i + 1; 


            if(currentLength>Result) {
                Result=currentLength;
            }
        }
    }
    return Result;
}
int main() {
    char str[100];
    printf("Enter The string \n");
    scanf("%[^\n]", str);

   int Answer=LongestSubString(str);
    printf("Longest SubString without repeating character %d  \n", Answer); 
    return 0;
}
