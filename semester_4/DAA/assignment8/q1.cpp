#include <bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int> >& graph, int S,vector<int>& par, vector<int>& dist)
{
    // queue to store the nodes in the order they are
    // visited
    queue<int> q;
    // Mark the distance of the source node as 0
    dist[S] = 0;
    // Push the source node to the queue
    q.push(S);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbour : graph[node]) {
            if (dist[neighbour] == 1e9) {
                par[neighbour] = node;
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }
}
void printShortestDistanceBFS(vector<vector<int> >& graph,
                           int S, int D, int V)
{
    vector<int> par(V, -1);
    vector<int> dist(V, 1e9);
    bfs(graph, S, par, dist);

    if (dist[D] == 1e9) {
        cout << "Source and Destination are not connected";
        return;
    }
    vector<int> path;
    int currentNode = D;
    path.push_back(D);
    while (par[currentNode] != -1) {
        path.push_back(par[currentNode]);
        currentNode = par[currentNode];
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

bool DFS(vector<int> adj[], int src, int dest, vector<int>& path, unordered_set<int>& visited) {
    path.push_back(src); // Add current node to the path
    visited.insert(src); // Mark current node as visited

    if (src == dest)
        return true;

    for (int neighbor : adj[src]) {
        if (visited.find(neighbor) == visited.end()) { // If neighbor is not visited
            if (DFS(adj, neighbor, dest, path, visited))
                return true;
        }
    }

    path.pop_back(); // If no path found from current node, remove it from the path
    return false;
}

// Function to find the shortest path between two nodes
vector<int> shortestPath(vector<int> adj[], int V, int src, int dest) {
    vector<int> path;
    unordered_set<int> visited;
    
    DFS(adj, src, dest, path, visited);

    return path;
}

// Driver program to test above functions
int main()
{
    // no. of vertices
    int V = 8, E = 10;
    // Source and Destination vertex
    int S = 2, D = 4;
    // edge list
    vector<vector<int> > edges
        = { { 0, 1 }, { 1, 2 }, { 0, 3 }, { 3, 4 },
            { 4, 7 }, { 3, 7 }, { 6, 7 }, { 4, 5 },
            { 4, 6 }, { 5, 6 } };

    // vector to store the graph as adjacency list
    vector<vector<int> > graph(V);
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    printShortestDistanceBFS(graph, S, D, V);
    return 0;
}