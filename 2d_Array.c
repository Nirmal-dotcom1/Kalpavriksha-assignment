#include<stdio.h>

#define MaxRow 11
#define MaxCols 101
#define MaxChar 51

int StartWithVowel(char letter){
    if(letter=='A' || letter=='a' || letter=='E' || letter=='e' || letter=='I' || letter=='i' || letter=='O' || letter=='o' || letter=='U' || letter=='u')
    return 1;
    
return 0;    
}

void VowelCount(char StudentName[MaxRow][MaxCols][MaxChar],int NumOfRows, int NumOfCols){
    int wordCount=0;
    for(int i=0;i<NumOfRows;i++){
        for(int j=0;j<NumOfCols;j++){
            if(StartWithVowel(StudentName[i][j][0])==1)
                wordCount++;
        }
     }
     printf("Number of names starting with a vowel: %d",wordCount);
}

int CalculateLength(char StudentName[]){
    int length=0;
    while(StudentName[length]!='\0'){
        length++;
    }
    return length;
}

int main(){
    int NumOfRows;
    int NumOfCols;
    printf("Enter the Number Of Rows : ");
    scanf("%d",&NumOfRows);
    printf("Enter the Number Of Rows : ");
    scanf("%d",&NumOfCols);
    char StudentName[MaxRow][MaxCols][MaxChar];
    int MaxLen=0;
    printf("Enter the Names : \n");
    for(int i=0;i<NumOfRows;i++){
        for(int j=0;j<NumOfCols;j++){
            printf("Name at (%d,%d): ",i,j);
            scanf("%s",StudentName[i][j]);
             int lenOfWord=CalculateLength(StudentName[i][j]);
          if(lenOfWord>MaxLen)
              MaxLen=lenOfWord;
            }
        }
    
    printf("The 2D array of names is: \n");
    for(int i=0;i<NumOfRows;i++){
        for(int j=0;j<NumOfCols;j++){
            printf("%s ",StudentName[i][j]);
          }
           printf("\n");
    }
    
    VowelCount(StudentName,NumOfRows,NumOfCols);
    
     for(int i=0;i<NumOfRows;i++) {
        for(int j=0;j<NumOfCols;j++){
            if (CalculateLength(StudentName[i][j])==MaxLen){
                printf("\nThe longest name: %s", StudentName[i][j]);
                return 0;}
            }
        }

    return 0;
}