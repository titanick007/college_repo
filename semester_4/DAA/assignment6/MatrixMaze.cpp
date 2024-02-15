#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cstring>

using namespace std;
using namespace std::chrono;



int numberOfPaths_bruteforce(int m, int n)
{

    if (m == 1 || n == 1)
        return 1;
 

    return numberOfPaths_bruteforce(m - 1, n)
           + numberOfPaths_bruteforce(m, n - 1);
}


int numPaths_dp(int m,int n,int dp[500][500]){
    if (n == 1 || m == 1)
        return dp[m][n] = 1;

    if (dp[m][n] == 0)
        dp[m][n] = numPaths_dp(m - 1, n, dp)
                   + numPaths_dp(m, n - 1, dp);
 
    return dp[n][m];
}
int main()
{

    int m,n;
    cout<<"Enter m and n\n";
    cin>>m>>n;
    int dp[500][500];
    memset(dp, -1, sizeof dp);
    auto start1=high_resolution_clock::now();
    cout<<"number of ways to reach using brute force "<<n<<"th stair is "<<numberOfPaths_bruteforce(m,n)<<endl;
    auto stop1=high_resolution_clock::now();
    auto duration1=duration_cast<microseconds>(stop1-start1);

    auto start2=high_resolution_clock::now();

    cout<<"number of ways to reach using optimized method "<<n<<"th stair is "<<numPaths_dp(m,n,dp)<<endl;

    auto stop2=high_resolution_clock::now();
    auto duration2=duration_cast<microseconds>(stop2-start2);

    cout<<"Time taken by brute force method : "<<duration1.count()<<" microseconds\n\n";
    cout<<"Time taken by optimized method : "<<duration2.count()<<" microseconds\n\n";
   



    return 0;
}