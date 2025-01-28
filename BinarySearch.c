#include <stdio.h>

void BinarySearch(int Array[], int size, int target)
{

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (Array[mid] == target)
        {
            printf("Element found at %dth position", mid);
            return;
        }
        else if (Array[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    printf("Elment Not found");
}

int main()
{
    int size;
    printf("Enter The Number Of elemenets In the Array : ");
    scanf("%d", &size);

    int Array[size];

    printf("Enter the elements in sorted accending Order : \n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &Array[i]);
    }

    int target;
    printf("Enter The ELement to be searched : ");
    scanf("%d", &target);

    BinarySearch(Array, size, target);

    return 0;
}