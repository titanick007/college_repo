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

int kth_smallest(int arr[],int lb,int ub ,int k){
    if(lb<=ub){
        int mid=partition(arr,lb,ub);
        if(mid==k-1)return arr[mid];
        else if(mid<k-1) return kth_smallest(arr,mid+1,ub,k);
        else return kth_smallest(arr,lb,mid-1,k);
    }
    return -1;
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
    int arr[10]={7,5,3,22,1,4,8,3,10,6};int k;
    cout<<"Enter which smallest number : ";
    cin>>k;
    cout<<"Unsorted array\n";
    printarr(arr,10);

    quicksort(arr,0,10-1);
    cout<<"Sorted array\n";
    printarr(arr,10);

    cout<<k<<"th smallest element in array is "<<kth_smallest(arr,0,10-1,k)<<endl;
}