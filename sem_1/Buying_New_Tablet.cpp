#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,b;
        cin>>n>>b;
        int area=0;
        while(n--){
            int a[n];
            scanf("%d %d %d",&a[0],&a[1],&a[2]);
            if(a[2]<=b){
                if(a[1]*a[0]>area) area=a[1]*a[0];
            }
        }
        if(area>0) cout<<area<<endl;
        else cout<<"no tablet\n";
    }
    return 0;
}