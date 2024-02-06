#include <iostream>
#include <algorithm>
using namespace std;


void SelectionSort(int arr[],int n){
    for(int i=0;i<n;++i){
        int temp=i;
        for(int j=i+1;j<n;++j){
            if(arr[temp]>arr[j])temp=j;
        }
        if(temp!=i)swap(arr[temp],arr[i]);
    }
}
int main(){
    int arr[8]={8,5,4,37,3,7,19,11};
    for(int i=0;i<8;++i){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    SelectionSort(arr,8);
    cout<<"sorted array\n";

    for(int i=0;i<8;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}