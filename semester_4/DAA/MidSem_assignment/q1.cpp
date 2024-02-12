#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

vector<int> largestSortedSubsequence(int arr[],int n){
    int length=1;       //length of largest sorted subarray
    int temp_len=1;     //temporary length for each sorted subarray
    vector<int> sorted_array;   //storing largest sorted subarray
    

    for(int i=0;i<n;++i){
        vector<int> temp_sorted_subarray;       //temp variable to store sorted subarray. Also clears the contents of the previous subarray
        temp_sorted_subarray.push_back(arr[i]); //first element is sorted and is a sorted subarray
        temp_len=1;
        for(int j=i;j<n-1;++j){
            if(arr[j+1]>=arr[j]){
                ++temp_len;
                temp_sorted_subarray.push_back(arr[j+1]);
            }
            else break;
        }
        if(temp_len>=length){
            length=temp_len;
            sorted_array=temp_sorted_subarray;
        }
    }
    return sorted_array;
}


int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    auto start=high_resolution_clock::now();

    vector<int> largest_Sorted_Subarray=largestSortedSubsequence(arr,10);

    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<"\nlargest sorted subsequence in this array is\n\n ";
    for(int i=0;i<largest_Sorted_Subarray.size();++i){
        cout<<largest_Sorted_Subarray[i]<<" ";
    }



    cout << "\n\nTime taken for algorithm: " << duration.count() << " microseconds" << endl << endl;

}