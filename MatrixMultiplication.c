// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>

void MultiplyMatrices(int row1,int col1,int **Matrix1,int row2,int col2,int **Matrix2,int **ResultMatrix){
    
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
           ResultMatrix[i][j]=0;
            
        }
    }
    
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            for(int k=0;k<col1 ;k++){
            ResultMatrix[i][j]+=Matrix1[i][k]*Matrix2[k][j];
                
            }
        }
      
    }
}
int main() {
    int row1;
    printf("Enter Number of Rows for Matrix 1 : ");
    scanf("%d",&row1);
    
    int col1;
    printf("Enter Number of Column for Matrix 1 : ");
    scanf("%d",&col1);
    
     int row2;
    printf("Enter Number of Rows for Matrix 2 : ");
    scanf("%d",&row2);
    
    int col2;
    printf("Enter Number of Colum for Matrix 2 : ");
    scanf("%d",&col2);
    
    int **Matrix1=(int **)malloc(row1 *sizeof(int *));
    for(int i=0;i<row1;i++){
        Matrix1[i]=(int *)malloc(col1 *sizeof(int));
    }
    
    int **Matrix2=(int **)malloc(row2 *sizeof(int *));
    for(int i=0;i<row2;i++){
       Matrix2[i]=(int *)malloc(col2 *sizeof(int));
    }
    
    
    printf("Enter Values for First Matrix \n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("value at (%d,%d) :",i,j);
            scanf("%d",&Matrix1[i][j]);
            
        }
    }
        
     printf("Enter Values for Second Matrix \n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            printf("value at (%d,%d) :",i,j);
            scanf("%d",&Matrix2[i][j]);
            
        }
    }
    
    
    int **ResultMatrix=(int **)malloc(row1 *sizeof(int *));
    for(int i=0;i<row1;i++){
       ResultMatrix[i]=(int *)malloc(col2 *sizeof(int));
    }
    
    MultiplyMatrices(row1, col1, Matrix1, row2, col2, Matrix2,ResultMatrix);
   
      printf("------The Resultant Matrix---\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            printf("%d ", ResultMatrix[i][j]);
            
        }
        printf("\n");
    }
    
    for(int i=0;i<row1;i++){
        free(Matrix1[i]);
    }
    free(Matrix1);
    
    for(int i=0;i<row2;i++){
        free(Matrix2[i]);
    }
    free(Matrix2);
    
    for(int i=0;i<row2;i++){
        free(ResultMatrix[i]);
    }
    free(ResultMatrix);
    
    return 0;
}