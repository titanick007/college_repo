#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector <int> a(n);
        int count=0;
        while(n--){
            int h;
            cin>>h;
            a.push_back(h);
            if(h>k) count+=1;
        }
        cout<<count<<endl;
    }
    return 0;
}