#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int lb,int ub){
    int pivot=arr[ub];
    int i=lb-1;
    for(int j=lb;j<=ub;++j){
        if(arr[j]<pivot){
            ++i;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[ub]);
    return i+1;
}

void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=partition(arr,lb,ub);
        quicksort(arr,lb,mid-1);
        quicksort(arr,mid+1,ub);
    }
}




void printarr(int arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}   

int main(){
    int arr[10]={7,5,3,22,1,4,8,3,10,6};

    cout<<"Unsorted array\n";
    printarr(arr,10);

    quicksort(arr,0,10-1);
    cout<<"Sorted array\n";
    printarr(arr,10);
}
