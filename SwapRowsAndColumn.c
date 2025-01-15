/* To swap the rows and column accordance to the given value*/

#include <stdio.h>
#include<stdlib.h>

int swaping(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void SwapRows(int **Mat,int row,int col,int k){

    for(int i=0;i<k;i++){
        for(int j=0;j<col;j++){
            swaping(&Mat[i][j] , &Mat[row-i-1][j]);
        }
    }   
}
void SwapCols(int **Mat,int row,int col,int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<row;j++){
            swaping(&Mat[j][i],&Mat[j][col -i -1]);
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
    int k;
  printf("Enter the number of rows and column to swap : ");
  scanf("%d",&k);
  if(k>row/2){
      printf("Swapping Can't Be done");
  }
     SwapRows(Mat,row,col,k);
     printf("After Swapping The Rows %d Times \n" ,k);
     printMatrix(Mat,row,col);
     
     SwapCols(Mat,row,col,k);
     printf("After Swapping The Columns %d Times \n" ,k);
     printMatrix(Mat,row,col);
   return 0;
   
}
