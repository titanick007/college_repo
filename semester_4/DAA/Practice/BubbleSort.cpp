#include <iostream>
#include <algorithm>
using namespace std;


void BubbleSort(int arr[],int n){
    for(int i=0;i<n;++i){
        int start=0;
        int j=start,k=j+1 ;
        while(j<n&&k<=n){
            if(arr[j]>arr[k])swap(arr[j],arr[k]);
            ++j;++k;
        }
        --n;
    }
}

int main(){
    int arr[8]={8,5,4,37,3,7,19,11};
    for(int i=0;i<8;++i){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    BubbleSort(arr,8);
    cout<<"sorted array\n";

    for(int i=0;i<8;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}