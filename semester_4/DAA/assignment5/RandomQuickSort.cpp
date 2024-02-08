
#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high)
{
	// pivot
	int pivot = arr[high]; 

	// Index of smaller element
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{
		// If current element is smaller
		// than or equal to pivot
		if (arr[j] <= pivot) {

			// increment index of 
			// smaller element
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot
int partition_r(int arr[], int low, int high)
{

	srand(time(NULL));
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high]
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high) {

		int pi = partition_r(arr, low, high);


		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)cout<<arr[i]<<" "; 
	cout<<endl;
}


int main()
{
	int n;
	cout<<"Enter no. of elements\n";
	cin>>n;

	int arr[n];
	for(int i=0;i<n;++i){
		arr[i]=rand();
	}
	
	auto start = high_resolution_clock::now();
	quickSort(arr, 0, n - 1);
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

	printf("Sorted array: \n");
	printArray(arr, n);
	cout << "Time taken by function: "<< duration.count() << " nanoseconds" << endl<<endl;

	
	return 0;
}
