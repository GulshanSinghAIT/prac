#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    set<pair<int, int>> st;
    st.insert({0, S});

    while (!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjnode = it[0];
            int edw = it[1];

            if (dis + edw < dist[adjnode])
            {
                st.erase({dist[adjnode], adjnode});
                dist[adjnode] = dis + edw;
                st.insert({dist[adjnode], adjnode});
            }
        }
    }

    return dist;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];

    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // Uncomment the following line for undirected graphs
        // adj[v].push_back({u, w});
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    vector<int> dist = dijkstra(V, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}
