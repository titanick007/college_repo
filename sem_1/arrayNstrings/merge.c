#include <stdio.h>
int main()
{
    int size,i;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    printf("Enter the values of the first array\n");
    int a1[size],a2[size],b[size*2];
    for(i=0;i<size;i++)   scanf("%d",&a1[i]);
    printf("Enter the values of the second array\n");
    for(i=0;i<size;i++) scanf("%d",&a2[i]);
    for (i=0;i<size;i++){
        b[i]=a1[i];
    }
    for (i=0;i<size;i++) b[i+size]=a2[i];
    for (i=0;i<size*2;i++) printf("%d ",b[i]);
    printf("\n");
    return 0;
}
