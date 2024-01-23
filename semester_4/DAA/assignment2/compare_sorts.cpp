#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

//Comparing quick sort, insertion sort and bubble sort on the same array
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


void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
int main() {
    int n;
    cout<<"enter no of elements\n";
    cin>>n;
    int arr1[n],arr2[n],arr3[n];
    cout<<"enter values\n";
    for(int i=0;i<n;++i){
        arr1[i]=rand();
        arr2[i]=arr1[i];
        arr3[i]=arr1[i];
    };
    auto start = high_resolution_clock::now();
    //quick sort
    quickSort(arr1,0,n-1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++){
	    cout<<arr1[i]<<" ";
    }
    cout<<"\n"; 
    cout << "Time taken by quicksort function: "
         << duration.count() << " nanoseconds" << endl;

    //insertion sort
    auto start1 = high_resolution_clock::now();
    insertionSort(arr2,n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);

    cout<<"\n"; 
    cout << "Time taken by insertion sort function: "
         << duration1.count() << " nanoseconds" << endl;

    //bubble sort
    auto start2 = high_resolution_clock::now();
    bubbleSort(arr3,n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);

    cout<<"\n"; 
    cout << "Time taken by bubble sort function: "
         << duration2.count() << " nanoseconds" << endl;

    return 0;
}
