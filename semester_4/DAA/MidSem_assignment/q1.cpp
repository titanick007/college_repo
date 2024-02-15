#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std::chrono;
using namespace std;

pair<int, vector<int>> longestIncreasingSubsequences(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  // Initialize the dynamic programming array to store lengths
    vector<int> startIndices(n, 0);  // Initialize an array to store start indices

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                startIndices[i] = j;
            }
        }
    }

    int maxLength = *max_element(dp.begin(), dp.end());
    vector<int> longestStartIndices;
    for (int i = 0; i < n; ++i) {
        if (dp[i] == maxLength) {
            longestStartIndices.push_back(i);
        }
    }

    // Construct the longest increasing subsequence
    vector<int> longestSubsequence;
    for (int i : longestStartIndices) {
        vector<int> subsequence;
        while (subsequence.size() < maxLength) {
            subsequence.push_back(arr[i]);
            i = startIndices[i];
        }
        reverse(subsequence.begin(), subsequence.end());
        longestSubsequence.insert(longestSubsequence.end(), subsequence.begin(), subsequence.end());
    }

    return make_pair(maxLength, longestSubsequence);
}

int main() {
    vector<int> arr;
    int n;
    cout<<"Enter no of elements\n\n";
    cin>>n;
    for(int i=0;i<n;++i){
        arr.push_back(rand());
    }
    auto start=high_resolution_clock::now();
    auto result = longestIncreasingSubsequences(arr);
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout << "Length of the largest sorted subsequence: " << result.first << endl;
    cout << "Largest sorted subsequence: ";
    for (int i : result.second) {
        cout << i << " ";
    }
    cout << endl;

    cout<<"Time taken by algorithm: "<<duration.count()<<" microseconds\n\n";

    return 0;
}
