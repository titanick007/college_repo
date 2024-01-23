#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int arr[n];
    int max=0;
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
        if(arr[i]>=max) max=arr[i];
    }
    printf("The largest number is %d\n",max);
    return 0;
}