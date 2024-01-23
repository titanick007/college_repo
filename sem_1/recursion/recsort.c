#include <stdio.h>

int search(int arr[], int x, int i, int size)
{
    if (i >= size)
    {
        return 0;
    }

    if (arr[i] == x)
    {
        return 1;
    }

    else
    {
        i += 1;
        search(arr, x, i, size);
    }
}
int main()
{
    int n; 
    printf("Size of Array: ");
    scanf("%d", &n);
    
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    int x, i = 0;
    scanf("%d", &x);

    int temp = search(arr, x, i, n);
    if (temp == 1)
    {
        printf("FOUND\n");
    }

    else 
    {
        printf("NOT FOUND\n");
    }
}