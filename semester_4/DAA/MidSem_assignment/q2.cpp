#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std::chrono;
using namespace std;

int NumSwapsBubbleSort(int arr[], int n) {
    int swapCount = 0;
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n-i-1; ++j) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                ++swapCount;
            }
        }
    }
    return swapCount;
}

int NumSwapsInsertionSort(int arr[], int n) {
    int swapCount = 0;
    for(int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            ++swapCount;
            j = j - 1;
        }
        arr[j+1] = key;
    }
    return swapCount;
}

int NumSwapsSelectionSort(int arr[], int n) {
    int swapCount = 0;
    for(int i = 0; i < n-1; ++i) {
        int minIndex = i;
        for(int j = i+1; j < n; ++j) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
            ++swapCount;
        }
    }
    return swapCount;
}

int main() {
    int arr1[1000];
    int arr2[1000];
    int arr3[1000];
    for(int i = 0; i < 1000; ++i) {
        arr1[i] = rand();
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    int numSwaps = 0;

    //number of swaps in bubble sort
    auto start1 = high_resolution_clock::now();
    numSwaps = NumSwapsBubbleSort(arr1, 1000);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Number of swaps in Bubble sort is " << numSwaps << endl;
    cout << "Time taken by Bubble sort: " << duration1.count() << " milliseconds" << endl << endl;

    //number of swaps in insertion sort
    auto start2 = high_resolution_clock::now();
    numSwaps = NumSwapsInsertionSort(arr2, 1000);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Number of swaps in Insertion sort is " << numSwaps << endl;
    cout << "Time taken by Insertion sort: " << duration2.count() << " milliseconds" << endl << endl;

    //number of swaps in selection sort
    auto start3 = high_resolution_clock::now();
    numSwaps = NumSwapsSelectionSort(arr3, 1000);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(stop3 - start3);
    cout << "Number of swaps in Selection sort is " << numSwaps << endl;
    cout << "Time taken by Selection sort: " << duration3.count() << " milliseconds" << endl << endl;

    return 0;
}
