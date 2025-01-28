#include <stdio.h>

void LinearSearch(int Array[], int size, int target)
{

    for (int i = 0; i < size; i++)
    {
        if (Array[i] == target)
        {
            printf("Element Found At %dth position", i);
            return;
        }
    }
    printf("Elmenet not found in the array");
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

    int target;
    printf("Enter The ELement to be searched : ");
    scanf("%d", &target);

    LinearSearch(Array, size, target);
    return 0;
}