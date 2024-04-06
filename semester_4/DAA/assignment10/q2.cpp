#include <bits/stdc++.h>
using namespace std;
struct Edge {
   int src, dest, weight;
};
 
int findUP(int node, vector<int> &parent) {
   if (parent[node] == -1) return node;
   return findUP(parent[node], parent);
}
 
void unionByRank(int u, int v, vector<int> &rank, vector<int> &parent) {
   int u_root = findUP(u, parent);
   int v_root = findUP(v, parent);
   if (rank[u_root] < rank[v_root])
       parent[u_root] = v_root;
   else if (rank[u_root] > rank[v_root])
       parent[v_root] = u_root;
   else {
       parent[v_root] = u_root;
       rank[u_root]++;
   }
}
 
bool compareEdges(const Edge &a, const Edge &b) {
   return a.weight < b.weight;
}
 
vector<Edge> kruskalMST(vector<Edge> &edges, int n) {
   sort(edges.begin(), edges.end(), compareEdges);
   vector<Edge> result;
   vector<int> parent(n, -1);
   vector<int> rank(n, 0);
   int e = 0, i = 0;
   while (e<n-1 && i<edges.size()) {
       Edge nextEdge = edges[i++];
       int x = findUP(nextEdge.src, parent);
       int y = findUP(nextEdge.dest, parent);
       if (x != y) {
           result.push_back(nextEdge);
           unionByRank(x, y, rank, parent);
           e++;
       }
   }
   return result;
}
 
int main() {
   int V, E;
   cin >> V >> E;
   vector<Edge> edges(E);
   for (int i=0;i<E;i++) cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
   vector<Edge> MST = kruskalMST(edges, V);
   cout << "Edges of MST:" << endl;
   for (const auto &edge : MST) {
       cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
   }
}