#include <stdio.h>

void BinarySearch(int *arr, int start, int end, int key)
{

    int i=0;
    if (start == end)
    {

        if (arr[0] == key)
        {
            printf("Element found at index %d\n", i );
        }

        else
        {
            printf("\nNot found !\n");
        }
    }

    else
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            return;
        }

        if (key < arr[mid])
        {
            BinarySearch(arr, start, mid, key);
        }

        if (key > arr[mid])
        {
            BinarySearch(arr, mid + 1, end, key);
        }
    }

        return;
}

int main()
{

    int a[30], n, key;
    printf("Enter the size of array(less than 30): ");
    scanf("%d", &n);

    int i;
    int pos = 0;

    printf("Enter the array keybers\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the keyber to be searched for ");
    scanf("%d", &key);

    int left = 0, right = n;

    BinarySearch(a, left, right, key);

    return 0;
}