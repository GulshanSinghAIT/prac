#include <bits/stdc++.h>
using namespace std;

// Add an undirected edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS function with depth limit
bool DFS(const vector<vector<int>>& adj, int v, vector<bool>& visited, int element, int depth, int maxDepth) {
    if (depth > maxDepth) return false;
    visited[v] = true;
    cout << v << " ";
    if (v == element) {
        cout << "\nElement found using DFS" << endl;
        return true;
    }
    for (int neighbor : adj[v]) {
        if (!visited[neighbor] && DFS(adj, neighbor, visited, element, depth + 1, maxDepth))
            return true;
    }
    return false;
}

// BFS function with level limit
bool BFS(const vector<vector<int>>& adj, int V, vector<bool>& visited, int start, int element, int maxLevel) {
    queue<pair<int, int>> q; // pair<node, level>
    visited[start] = true;
    q.push({start, 0});
    while (!q.empty()) {
        pair<int, int> front = q.front(); q.pop();
        int current = front.first;
        int level = front.second;

        if (level > maxLevel) continue;
        cout << current << " ";
        if (current == element) {
            cout << "\nElement found using BFS" << endl;
            return true;
        }
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, level + 1});
            }
        }
    }
    return false;
}

int main() {
    int vertices, edges, start, element, limit;
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
    cout << "Enter the depth/level limit: ";
    cin >> limit;

    vector<bool> visitedBFS(vertices, false), visitedDFS(vertices, false);

    cout << "BFS path (level-limited): ";
    if (!BFS(adj, vertices, visitedBFS, start, element, limit))
        cout << "Element not found using BFS" << endl;

    cout << "DFS path (depth-limited): ";
    if (!DFS(adj, start, visitedDFS, element, 0, limit))
        cout << "Element not found using DFS" << endl;

    return 0;
}
