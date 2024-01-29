#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex > k - 1)
        {
            return quickSelect(arr, low, pivotIndex - 1, k);
        }
        else
        {
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }

    // This should not happen in a valid scenario.
    return -1;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    srand(time(0));
    int n;
    cin>>n;
    int k;
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = rand() % n + 1;
    }
    vector<int> mergeArray = array;
    vector<int> quickArray = array;
    clock_t start, end;
    int k;
    cout<<"enter which no. element to search";
    start = clock();
    mergeSort(mergeArray, 0, n - 1);
    end = clock();
    double mergeTime = ((double)end - start) / CLOCKS_PER_SEC;
    start = clock();
    quickSelect(quickArray, 0, n - 1, k);
    end = clock();
    double quickTime = ((double)end - start) / CLOCKS_PER_SEC;
    cout << "Merge Sort Time: " << mergeTime << " seconds" << endl;
    cout << "QuickSelect Time: " << quickTime << " seconds" << endl;
    return 0;
}