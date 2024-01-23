#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

//threshold value of 75 elements
int partition(int arr[],int low,int high){

int pivot=arr[high];
int i=(low-1);

for(int j=low;j<=high;j++)
{
	if(arr[j]<pivot){
        i++;
	    swap(arr[i],arr[j]);
	}
}
swap(arr[i+1],arr[high]);
return (i+1);
}
void quickSort(int arr[],int low,int high){

    if(low<high){
    
    	int pi=partition(arr,low,high);
    	quickSort(arr,low,pi-1);
    	quickSort(arr,pi+1,high);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void hybridSort(int arr[],int n){
    if(n<75){
        insertionSort(arr,n);
    }
    else quickSort(arr,0,n-1);
}

int main(){
    int n;
    cout<<"enter no of elements\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)arr[i]=rand();
    auto start = high_resolution_clock::now();
    hybridSort(arr,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++){
	    cout<<arr[i]<<" ";
    }
    cout<<"\n"; 
    cout << "Time taken by sort function: "
         << duration.count() << " nanoseconds" << endl;
    return 0;
}

