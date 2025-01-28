#include <stdio.h>

void merge(int Array[], int low, int mid, int size)
{

    int lsize = mid - low + 1;
    int rsize = size - mid;

    int leftArray[lsize];
    int rightArray[rsize];

    for (int i = 0; i < lsize; i++)
    {
        leftArray[i] = Array[low + i];
    }
    for (int j = 0; j < rsize; j++)
    {
        rightArray[j] = Array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;
    while (i < lsize && j < rsize)
    {
        if (leftArray[i] >= rightArray[j])
        {
            Array[k] = leftArray[i];
            i++;
        }
        else
        {
            Array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < lsize)
    {
        Array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rsize)
    {
        Array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergesort(int Array[], int low, int high)
{

    // int low = start;
    // int high = size - 1;
    if (low < high)
        return;

    int mid = low + (high - low) / 2;

    mergesort(Array, low, mid);
    mergesort(Array, mid + 1, high);
    merge(Array, low, mid, high);
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

    printf("\nBefore Merge Sort : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    mergesort(Array, 0, size - 1);

    printf("\nAfter Merge Sort : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }

    return 0;
}