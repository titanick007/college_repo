#include <stdio.h>
int main(){
    int s,i,k,j;
    printf("Enter the size of array\n");
    scanf("%d",&s);
    int arr[s];
    printf("Enter the values of array (1 to 100)\n");
    for(i=0;i<s;i++)scanf("%d",&arr[i]);
    for (i=1;i<=100;i++){
        k=0;
        for(j=0;j<s;j++){
            if(arr[j]==i) 
            k++;
        }
        if(k!=0) printf("%d occurs %d times\n",i,k);
    }
    return 0;
}