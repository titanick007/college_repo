#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std::chrono;
using namespace std;
int main(){
    int n,a;
    cout<<"enter no. of elements\n";
    cin>>n;
    int arr[n];cout<<"enter values"<<endl;
    for(int i=0;i<n;++i)cin>>arr[i];
    cout<<"enter element to search\n";
    cin>>a;
    cout<<"enter no. to search\n";
    cin>>a;
    auto start = high_resolution_clock::now();
    for(int i=0;i<n;++i){
        if(a==arr[i])break;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;
    return 0;
}