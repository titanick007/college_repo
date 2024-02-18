#include <bits/stdc++.h>
using namespace std;


void merge(int arr[],int lb,int mid,int ub){
    int i=lb,j=mid+1,k=0;
    int temp_arr[ub-lb+1];
    while(i<=mid&&j<=ub){
        if(arr[i]<=arr[j]){
            temp_arr[k]=arr[i];
            ++i;++k;
        }
        else{
            temp_arr[k]=arr[j];
            ++j;++k;
        }
    }
    while(i<=mid){
        temp_arr[k]=arr[i];
        ++i;++k;
    }
    while (j<=ub){
        temp_arr[k]=arr[j];
        ++j;++k;
    }
    for(k=0;k<ub-lb+1;++k){
        arr[k+lb]=temp_arr[k];
    }
}

void Mergesort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        Mergesort(arr,lb,mid);
        Mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
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

    Mergesort(arr,0,10-1);
    cout<<"Sorted array\n";
    printarr(arr,10);
}