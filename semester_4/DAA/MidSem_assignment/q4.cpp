#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int prev1=0;
int prev2=1;
int result=0;


//checking for Fibonacci number
void checkFibonacci(int key){
    if(key<0){
    cout<<key<<" is not a Fibonacci number\nNearest number is 0\n\n";
    return;
    }
    if(key==0||key==1){
        cout<<key<<" is a Fibonacci number\n\n";
        return;
    }
    while(key>result){
        result=prev1+prev2;
        if(key<=result)break;
        prev1=prev2;
        prev2=result;
    }
    if(key==result){
        cout<<key<<" is a Fibonacci number\n\n";
    }
    else {
        if(key-prev2>result-key)cout<<key<<" is not a Fibonacci number\nNearest number is "<<result<<"\n\n";
        else if(key-prev2<result-key)cout<<key<<" is not a Fibonacci number\nNearest number is "<<prev2<<"\n\n";
        else cout<<key<<" is not a Fibonacci number\nNearest Fibonacci numbers are "<<result<<" and "<<prev2<<endl<<endl;
    }
}

int main(){
    int key;
    cout<<"Enter a integer\n\n";
    cin>>key;

    auto start = high_resolution_clock::now();

    checkFibonacci(key);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken: " << duration.count() << " microseconds" << endl << endl;


    return 0;
}