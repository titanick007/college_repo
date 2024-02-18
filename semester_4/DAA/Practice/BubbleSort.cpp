#include <bits/stdc++.h>
using namespace std;


void Bubblesort(int arr[], int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(arr[j+1]<arr[j])swap(arr[j+1],arr[j]);
        }
        --n;
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

    Bubblesort(arr,10);
    cout<<"Sorted array\n";
    printarr(arr,10);
}