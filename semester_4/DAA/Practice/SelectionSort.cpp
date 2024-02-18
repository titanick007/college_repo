#include <iostream>
#include <algorithm>
using namespace std;

void Selectionsort(int arr[],int n){
    for(int i=0;i<n;++i){
        int min_index=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[min_index])min_index=j;
        }
        if(min_index!=i)swap(arr[i],arr[min_index]);
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

    Selectionsort(arr,10);
    cout<<"Sorted array\n";
    printarr(arr,10);
}