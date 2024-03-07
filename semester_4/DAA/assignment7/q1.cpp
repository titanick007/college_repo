#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


struct Job {

	char id;
	int dead; 
	int profit; 
};

// Comparator function for sorting jobs
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n){
	sort(arr, arr + n, comparison);

	int result[n];
	bool slot[n];
	for (int i = 0; i < n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++) {
		// Find a free slot for this job
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			// Free slot found
			if (slot[j] == false) {
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}
    // Print the result
    int total_profit=0;
	for (int i = 0; i < n; i++){
		if (slot[i]){
			cout << arr[result[i]].id << " ";
            total_profit+=arr[result[i]].profit;
        }
    }
    cout<<"total profit :"<<total_profit<<endl;
}

// Driver's code
int main()
{
	Job arr[] = { { '1', 2, 100 },
              { '2', 1, 19 },
              { '3', 2, 27 },
              { '4', 1, 25 },
              { '5', 3, 15 },
              { '6', 2, 50 },
              { '7', 3, 35 },
              { '8', 1, 70 },
              { '9', 2, 10 },
              { '0', 3, 45 },
              { 'a', 1, 30 },
              { 'b', 2, 40 },
              { 'c', 1, 20 },
              { 'd', 3, 55 },
              { 'e', 2, 5 },
              { 'f', 1, 60 },
              { 'g', 2, 12 },
              { 'h', 3, 22 },
              { 'i', 1, 33 },
              { 'j', 3, 18 },
              { 'k', 2, 47 },
              { 'l', 1, 31 },
              { 'm', 3, 28 },
              { 'n', 1, 24 },
              { 'o', 2, 36 },
              { 'p', 1, 38 },
              { 'q', 3, 42 },
              { 'r', 2, 23 },
              { 's', 1, 17 },
              { 't', 3, 11 },
              { 'u', 2, 13 },
              { 'v', 1, 37 },
              { 'w', 2, 29 },
              { 'x', 3, 34 },
              { 'y', 1, 43 },
              { 'z', 3, 16 },
              { 'A', 2, 21 },
              { 'B', 1, 32 },
              { 'C', 3, 26 },
              { 'D', 1, 44 },
              { 'E', 2, 46 },
              { 'F', 3, 41 },
              { 'G', 1, 39 },
              { 'H', 2, 48 },
              { 'I', 3, 49 },
              { 'J', 1, 51 },
              { 'K', 2, 53 },
              { 'L', 3, 54 },
              { 'M', 1, 57 },
              { 'N', 2, 58 },
              { 'O', 3, 59 },
              { 'P', 1, 63 },
              { 'Q', 2, 65 },
              { 'R', 3, 67 },
              { 'S', 1, 69 },
              { 'T', 2, 71 },
              { 'U', 3, 72 },
              { 'V', 1, 73 },
              { 'W', 2, 74 },
              { 'X', 3, 76 },
              { 'Y', 1, 77 },
              { 'Z', 2, 80 } };


	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
			"\n";

	// Function call
    auto start=high_resolution_clock::now();
	printJobScheduling(arr, n);
    auto stop=high_resolution_clock::now();
    cout<<endl;
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<"execution time: "<<duration.count()<<"microseconds\n";
	return 0;
}
