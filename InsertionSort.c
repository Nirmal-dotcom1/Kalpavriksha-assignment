#include <stdio.h>

void InsertionSort(int Array[], int size)
{

    for (int i = 1; i < size; i++)
    {
        int x = Array[i];
        int j = i - 1;
        while (j >= 0 && x < Array[j])
        {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = x;
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
    printf("\nBefore Insertion Sort : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    InsertionSort(Array, size);
    printf("\nAfter Insertion Sort : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    return 0;
}