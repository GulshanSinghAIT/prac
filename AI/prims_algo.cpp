#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

void primMST(int n, vector<vector<pii>> &adj)
{
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;

        for (auto &edge : adj[u])
        {
            int weight = edge.first;
            int v = edge.second;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({weight, v});
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int v = 1; v < n; v++)
    {
        if (parent[v] != -1)
        {
            cout << parent[v] << " - " << v << " : " << key[v] << endl;
            totalWeight += key[v];
        }
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n);

    cout << "Enter each edge (u v weight):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    primMST(n, adj);

    return 0;
}
