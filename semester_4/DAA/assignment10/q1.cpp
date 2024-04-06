#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mst=0;
    int n;
    cin>>n;
    vector<pair<int,int>> buildings[n];
    for(int i=0;i<n;i++){
        int b1,b2,w;
        cin>>b1>>b2>>w;
        buildings[b1].push_back({b2,w});
        buildings[b2].push_back({b1,w});
    }
    vector<bool>vis(n,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int curBweight=pq.top().first;
        int curB=pq.top().second;
        pq.pop();
        if(vis[curB]) continue;
        mst+=curBweight;
        vis[curB]=1;
        for(auto x:buildings[curB]){
            int nextWeight=x.second;
            int nextB=x.first;
            if(!vis[nextB]){
                pq.push({nextWeight, nextB});
            }
        }
    }
    cout<<"The total cost for laying down the fiber-optic cables is : "<<mst<<endl;
}