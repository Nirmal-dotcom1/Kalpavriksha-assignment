#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int data;
	struct ListNode* next;
	struct ListNode* down;
};




void sparsematrix(int mat[][101],int row,int col) {

	struct ListNode* Matrix[row][col];
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			struct ListNode* temp=malloc(sizeof(struct ListNode));
			temp->data=mat[i][j];
			temp->next=NULL;
			temp->down=NULL;
			if(j+1<col) {
				temp->next=malloc(sizeof(struct ListNode));
				temp->next->data=mat[i][j+1];
				temp->next->next=NULL;
			}
			else {
				temp->next=NULL;
			}

			if(i+1<row) {
				temp->down=malloc(sizeof(struct ListNode));
				temp->down->data=mat[i+1][j];
				temp->down->down=NULL;
			}
			else {
				temp->down=NULL;
			}

			Matrix[i][j]=temp;
		}
	}

	printf(" Linked List Representation:\n");
	for (int i=0; i<row;i++) {
		for (int j=0;j<col;j++) {
			printf("Node(%d,%d)-> %d; ",i,j,Matrix[i][j]->data);
			if (Matrix[i][j]->next != NULL) {
				printf("Next: %d; ",Matrix[i][j]->next->data);
			}
			if (Matrix[i][j]->down!= NULL) {
				printf("Down: %d; ", Matrix[i][j]->down->data);
			}
			printf("\n");
		}
	}

}



int main()
{
	int row;
	printf("Enter The No. of rows : ");
	scanf("%d",&row);
	int col;
	printf("Enter The No. of col : ");
	scanf("%d",&col);

	int mat[row][col];

	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	sparsematrix(mat,row,col);


	return 0;
}
