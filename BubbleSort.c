#include <stdio.h>

void swap(int *Num1, int *Num2)
{
    int temp = *Num1;
    *Num1 = *Num2;
    *Num2 = temp;
}

void BubbleSort(int Array[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                swap(&Array[j], &Array[j + 1]);
            }
        }
    }
}

int main()
{

    int size;
    printf("Enter The Number Of elemenets In the Array : ");
    scanf("%d", &size);

    int Array[size];
    printf("Enter the elements : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &Array[i]);
    }
    printf("\nBefore Bubble Sort : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    BubbleSort(Array, size);
    printf("\nAfter Bubble Sort : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    return 0;
}