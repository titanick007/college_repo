#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int BinarySearch(int arr[],int low,int high,int value){
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value)
            return mid;
        else if (arr[mid] > value)
            return BinarySearch(arr, low, mid - 1, value);
        else // arr[mid] < value
            return BinarySearch(arr, mid + 1, high, value);
    }
    return -1; // Element not found
}

int main(){
    int arr[6]={7,4,29,4,33,2};
    sort(arr,arr+6);
    cout<<"Enter value to search\n";
    int val;
    cin>>val;
    int position=BinarySearch(arr,0,6,val);
    if(position>=0)printf("%d is in position %d\n",val,position);
    else printf("element is not in the array\n");
}