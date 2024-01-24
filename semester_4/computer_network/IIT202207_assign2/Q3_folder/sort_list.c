#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    FILE *fptr;
    fptr=fopen("nums.txt","r");
    int arr[100];
    int n=0,temp;
    if(fptr==NULL){
        printf("error in opening file\n");
        return 1;
    }
    while(fscanf(fptr,"%d",&arr[n])==1){
        ++n;
    }

    fclose(fptr);

    insertionSort(arr,n);
    for(int i=0;i<n;++i)printf("%d ",arr[i]);
    printf("\n");
    
    return 0;
}