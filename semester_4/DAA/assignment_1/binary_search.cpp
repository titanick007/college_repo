#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
int binary_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  

        if (arr[mid] == x) {
            return mid;  
        } else if (arr[mid] < x) {
            low = mid + 1;  
        } else {
            high = mid - 1;  
        }
    }

    return -1;  // Element not found
}
int main(){
    int n,a;
    cout<<"enter no. of elements\n";
    cin>>n;
    int arr[n];cout<<"enter values"<<endl;
    for(int i=0;i<n;++i)cin>>arr[i];
    cout<<"enter element to search\n";
    cin>>a;
    sort(arr,arr+n);
    auto start = high_resolution_clock::now();
    int ans= binary_search(arr,n,a);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    if(ans!=-1)cout<<"element is in position "<<ans<<endl;
    else cout<<"element not found"<<endl;
    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;

}