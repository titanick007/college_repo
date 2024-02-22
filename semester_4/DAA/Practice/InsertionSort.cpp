#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int arr[], int n){
    for(int i=1;i<n;++i){
        int temp=arr[i];int j=i-1;
        while (j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            --j;
        }
        
        arr[j+1]=temp;
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

    InsertionSort(arr,10);
    cout<<"Sorted array\n";
    printarr(arr,10);

}