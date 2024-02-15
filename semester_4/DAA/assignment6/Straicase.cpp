#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;
using namespace std::chrono;

int fib(int n){
    if(n==0||n==1)return n;
    else return fib(n-1)+fib(n-2);
}
int num_waysBruteforce(int n){
    return fib(n+1);
}


int num_ways_dp(int n, int dp[]){
    if(n==0||n==1)return dp[n]=1;
    else if(dp[n]!=-1)return dp[n];
    dp[n]=num_ways_dp(n-1,dp)+num_ways_dp(n-2,dp);
    return dp[n];
}


int main(){
    int n;
    cout<<"Enter no of stairs\n";
    cin>>n;
    int dp[n+1];
    memset(dp, -1, sizeof dp);
    auto start1=high_resolution_clock::now();
    cout<<"number of ways to reach using brute force "<<n<<"th stair is "<<num_waysBruteforce(n)<<endl;
    auto stop1=high_resolution_clock::now();
    auto duration1=duration_cast<microseconds>(stop1-start1);

    auto start2=high_resolution_clock::now();

    cout<<"number of ways to reach using optimized method "<<n<<"th stair is "<<num_ways_dp(n,dp)<<endl;

    auto stop2=high_resolution_clock::now();
    auto duration2=duration_cast<microseconds>(stop2-start2);

    cout<<"Time taken by brute force method : "<<duration1.count()<<" microseconds\n\n";
    cout<<"Time taken by optimized method : "<<duration2.count()<<" microseconds\n\n";
   


}