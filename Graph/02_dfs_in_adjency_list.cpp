#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    void dfsUtil(int node, vector<bool>& visited) {
        /*
        Time Complexity: O(V + E)
        - Each node visited once
        - Each edge explored once

        Space Complexity: O(V)
        - Visited array + recursion stack
        */

        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal starting from node " << start << ": ";
        dfsUtil(start, visited);
        cout << endl;
    }
};

// 🔰 Main Function for Testing
int main() {
    /*
    Sample Graph:
        0 — 1
        |   |
        3 — 2
    */

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    g.dfs(0); // Start DFS from node 0

    return 0;
}