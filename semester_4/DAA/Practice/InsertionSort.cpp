#include <iostream>
#include <algorithm>
using namespace std;


void InsertionSort(int arr[],int n){
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            if(arr[i]>arr[j])swap(arr[i],arr[j]);
        }
    }
}

int main(){
    int arr[8]={8,5,4,37,3,7,19,11};
    for(int i=0;i<8;++i){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    InsertionSort(arr,8);
    cout<<"sorted array\n";

    for(int i=0;i<8;++i){
        cout<<arr[i]<<" ";
    }
    return 0;
}