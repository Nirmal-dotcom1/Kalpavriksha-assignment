#include <stdio.h>

void swap(int *Num1, int *Num2)
{
    int temp = *Num1;
    *Num1 = *Num2;
    *Num2 = temp;
}

void SelectionSort(int Array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int MinIndex = i;
        for (int j = i; j < size; j++)
        {
            if (Array[MinIndex] > Array[j])
            {
                swap(&Array[MinIndex], &Array[j]);
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

    printf("\nBefore Selection Sort : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    SelectionSort(Array, size);

    printf("\nAfter Selection Sort : \n");
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    return 0;
}