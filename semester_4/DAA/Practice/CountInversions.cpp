#include <bits/stdc++.h>
using namespace std;

int merge(int arr[],int lb,int mid,int ub){
    int count=0;
    int i=lb,j=mid+1,k=0;
    int temp_arr[ub-lb+1];
    while(i<=mid&&j<=ub){
        if(arr[i]<=arr[j]){
            temp_arr[k]=arr[i];
            ++i;++k;
        }
        else{
            temp_arr[k]=arr[j];
            count+=mid-i+1;
            ++j;++k;
        }
    }
    while(i<=mid){
        temp_arr[k]=arr[i];
        ++i;++k;
    }
    while(j<=ub){
        temp_arr[k]=arr[j];
        ++j;++k;
    }
    for(k=0;k<ub-lb+1;++k){
        arr[k+lb]=temp_arr[k];
    }
    return count;
}

int Mergesort(int arr[],int lb,int ub){
    int count=0;
    if(lb<ub){
        int mid=(lb+ub)/2;
        count+=Mergesort(arr,lb,mid);
        count+=Mergesort(arr,mid+1,ub);
        count+=merge(arr,lb,mid,ub);
        return count;
    }
    return 0;
}

int countInversions(int arr[],int n){
    return Mergesort(arr,0,n-1);
}

void printarr(int arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[10]={7,5,3,22,1,4,8,3,10,6};

    printarr(arr,10);

    cout<<"number of inversions : "<<countInversions(arr,10)<<endl;

}

