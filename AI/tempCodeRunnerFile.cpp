}

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
}