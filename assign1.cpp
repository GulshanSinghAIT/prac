#include <bits/stdc++.h>
using namespace std;

// Add an undirected edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS function
bool DFS(const vector<vector<int>>& adj, int v, vector<bool>& visited, int element) {
    visited[v] = true;
    cout << v << " ";
    if (v == element) {
        cout << "\nElement found using DFS" << endl;
        return true;
    }
    for (int neighbor : adj[v]) {
        if (!visited[neighbor] && DFS(adj, neighbor, visited, element)) return true;
    }
    return false;
}

// BFS function
bool BFS(const vector<vector<int>>& adj, int V, vector<bool>& visited, int start, int element) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int current = q.front(); q.pop();
        cout << current << " ";
        if (current == element) {
            cout << "\nElement found using BFS" << endl;
            return true;
        }
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    int vertices, edges, start, element;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> adj(vertices);
    cout << "Enter edges (u v): \n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    cout << "Enter the starting vertex: ";
    cin >> start;
    cout << "Enter the element to search: ";
    cin >> element;

    vector<bool> visitedBFS(vertices, false), visitedDFS(vertices, false);

    cout << "BFS path: ";
    if (!BFS(adj, vertices, visitedBFS, start, element)) cout << "Element not found using BFS" << endl;

    cout << "DFS path: ";
    if (!DFS(adj, start, visitedDFS, element)) cout << "Element not found using DFS" << endl;

    return 0;
}
