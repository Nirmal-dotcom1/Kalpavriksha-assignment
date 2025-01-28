#include <stdio.h>

void swap(int *Num1, int *Num2)
{
    int temp = *Num1;
    *Num1 = *Num2;
    *Num2 = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int index = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            index++;
            swap(&arr[index], &arr[j]);
        }
    }

    swap(&arr[index + 1], &arr[high]);

    return (index + 1);
}

void quicksort(int arr[], int low, int high)
{
    if (low > high)
        return;
    int partitionIndex = partition(arr, low, high);

    quicksort(arr, low, partitionIndex - 1);
    quicksort(arr, partitionIndex + 1, high);
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

    printf("\nBefore Quick Sort : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    quicksort(Array, 0, size - 1);

    printf("\nAfter Quick Sort : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    return 0;
}