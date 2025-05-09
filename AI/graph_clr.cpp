#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& colors, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && colors[i] == c) { // Check adjacent vertices
            return false;
        }
    }
    return true;
};

bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& colors, int m, int v) {
    if (v == graph.size()) {
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c; // Assign color to vertex v
            if (graphColoringUtil(graph, colors, m, v + 1)) {
                return true;
            }
            colors[v] = 0; // Backtrack
        }
    }

    return false; // No color could be assigned
};

bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> colors(graph.size(), 0); // Color of each vertex initialized to 0 (no color)
    if (graphColoringUtil(graph, colors, m, 0)) {
        cout << "Solution found: " << endl;
        for (int i = 0; i < graph.size(); i++) {
            cout << "Vertex " << i << " -> Color " << colors[i] << endl;
        }
        return true;
    }
    return false; // No solution exists
};

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix (0 for no edge, 1 for edge): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    if (!graphColoring(graph, m)) {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}
