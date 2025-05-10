/* program to check two string are anagrams or not 

for eg input : str1="listen"
               str2="silent"
        output yes
        
        input : str1="nirmal"
                str2="vkohli"
        output  no
*/                

#include <stdio.h>

int string_length(char str[100]) {
    int length =0;
    while (str[length]!='\0') {
        length++;
    }
    return length;
}


int CheckAnagrams(char str1[100], char str2[100]) {
    int len1=string_length(str1);
    int len2=string_length(str2);

   
    if(len1!=len2) {
        return 0;
    }

    
    int count1[26]={0};  
    int count2[26]={0}; 


    for(int i=0;str1[i]!='\0';i++) {
      
        count1[str1[i] - 'a']++;
        count2[str2[i] - 'a']++;
    }

    for(int i=0;i<26;i++) {
        if (count1[i]!=count2[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100];

    printf("Enter the first string: ");
    scanf("%[^\n]",str1);
    getchar();
    char str2[100];
    printf("Enter the second string: ");
    scanf("%[^\n]",str2);

    if(CheckAnagrams(str1, str2)) {
        printf("'%s' and '%s' are anagrams.\n", str1, str2);
    }
    else{
        printf("'%s' and '%s' are not anagrams.\n", str1, str2);
    }

    return 0;
}
