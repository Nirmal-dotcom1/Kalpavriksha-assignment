#include <stdio.h>

void Sorting(char String[100],int Length){
    for(int i=0;i<Length-1;i++){
        for(int j=i+1;j<Length;j++){
            if(String[i]>String[j]){
                char temp=String[i];
                String[i]=String[j];
                String[j]=temp;
            }
        }
    }
}

void FrequencyOfCharacter(char String[100], int Length){

        int flag[Length];

        for(int i=0;i<Length;i++){
            flag[i]=0;
        }

        int countArr[Length];

        for(int i=0;i<Length;i++){
            countArr[i]=0;
        }
    
        for(int i=0;i<Length;i++){
            int count=1;
            for(int j=i+1;j<Length;j++){
            
            if(String[i]==String[j]){
                count++;
                flag[j]=1;
                }
            }
        countArr[i]=count;
        
        }

        for(int i=0;i<Length;i++){
            if(flag[i]==0){
                printf("%c",String[i]);
                printf("%d",countArr[i]);
        }   
    }
}

int main() {

    char String[100];
    scanf("%[^\n]",String);

    int Length=0;
    while(String[Length]!='\0'){
        Length++;
    }

    Sorting(String,Length);

    FrequencyOfCharacter(String,Length);
    
    return 0;
}