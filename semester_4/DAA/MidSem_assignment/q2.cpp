#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

#define INT_MAX 100000
using namespace std;
using namespace std::chrono;

void NumSwapsBubbleSort(vector<int>& arr, int n, int& swapCount) {
    swapCount = 0;
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n-i-1; ++j) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                ++swapCount;
            }
        }
    }
}

void NumSwapsInsertionSort(vector<int>& arr, int n, int& swapCount) {
    swapCount = 0;
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
}

void NumSwapsSelectionSort(vector<int>& arr, int n, int& swapCount) {
    swapCount = 0;
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
}

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> arr1, arr2, arr3;
    for(int i = 0; i < n; ++i) {
        arr1.push_back(rand());
        arr2.push_back(arr1[i]);
        arr3.push_back(arr1[i]);
    }

    int swapCount;
    auto start = high_resolution_clock::now();
    NumSwapsBubbleSort(arr1, n, swapCount);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Bubble Sort:" << endl;
    cout << "Number of swaps: " << swapCount << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl << endl;

    start = high_resolution_clock::now();
    NumSwapsInsertionSort(arr2, n, swapCount);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Insertion Sort:" << endl;
    cout << "Number of swaps: " << swapCount << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl << endl;

    start = high_resolution_clock::now();
    NumSwapsSelectionSort(arr3, n, swapCount);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Selection Sort:" << endl;
    cout << "Number of swaps: " << swapCount << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl << endl;

    return 0;
}
