/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

for eg input 1 1 1
             1 0 1
             1 1 1
             
output       1 0 1
            0 0 0
            1 1 1
            
            */
#include <stdio.h>
#include<stdlib.h>

void setZero(int **Mat,int row,int col){
   int *RowArray=(int *)malloc(row*sizeof(int));
   int *ColArray=(int *)malloc(col*sizeof(int));
   for(int i=0;i<row;i++){
       RowArray[i]=0;
   }
   for(int i=0;i<col;i++){
       ColArray[i]=0;
   }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(Mat[i][j]==0){
                RowArray[i]=1;
                ColArray[j]=1;
                
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(RowArray[i] || ColArray[j]){
                Mat[i][j]=0;
            }
        }
    }
}

void printMatrix(int **Mat,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",Mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
   int row;
   printf("Enter the number of rows : ");
   scanf("%d",&row);
   
   int col;
   printf("Enter the number of column : ");
   scanf("%d",&col);
   
   int **Mat=(int **)malloc(row * sizeof(int *));
       for(int i=0;i<row;i++){
           Mat[i]=(int *)malloc(col * sizeof(int));
       }
   
   printf("Enter The Matrix value \n");
   for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
           printf("Enter value for (%d,%d) : ",i,j);
           scanf("%d",&Mat[i][j]);
       }
   }
   
   printf("------------Before Matrix--------------\n");
   printMatrix(Mat,row,col);
   printf("------------After Matrix---------------\n");
   setZero(Mat, row, col);
   printMatrix(Mat,row,col);
   

    return 0;
}
