#include <iostream>
#include<chrono>
#include <numbers>
using namespace std;

using namespace std::chrono;

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=(low-1);
   
    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){
          i++;
          swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quickSort(int arr[],int low,int high,int kth)
{
    if(low<high)
    {
    int pi=partition(arr,low,high);
    quickSort(arr,low,pi-1,kth);
    if(kth-1<=pi-1&&kth-1>=low){
        cout<<kth<<"th element is "<<arr[kth-1]<<endl;
    }
    quickSort(arr,pi+1,high,kth);
    }
}

void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}


//kth smallest element using Merge sort

int kMerge(int arr[],int n, int k){
    mergeSort(arr,0,n);
    return arr[k-1];
}

//kth smallest element using quick sort


int main(){
    int n;
    cout<<"Enter no. of elements\n";
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;++i){
        arr1[i]=rand();
        arr2[i]=arr1[i];
    }
    int k;
    cout<<"enter which smallest element to find\n";
    cin>>k;


    printArray(arr2,n);
    cout<<endl<<endl;
    auto start2 = high_resolution_clock::now();
    quickSort(arr2,0,n,k);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);

    auto start1 = high_resolution_clock::now();
    mergeSort(arr1,0,n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);


}