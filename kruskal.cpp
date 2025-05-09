#include<bits/stdc++.h>
using namespace std;
struct  Edge
{
    int u,v,weight;
};
// compare edges by weight
bool compare(Edge a , Edge b){
    return a.weight<b.weight;
}

class DSU{

    vector<int>parent,rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0 ; i < n;++i){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(parent[u] != u){
            parent[u] = findParent(parent[u]);// path compression
        }
        return parent[u];
    }
    void unite(int u, int v){
        u = findParent(u);
        v = findParent(v);

        if(u==v) return;
        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[u]>rank[v]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }
   
};
int main(){
    int v,e;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;

    vector<Edge>edges(e);
    cout<<"Enter edges (u v weight):\n";
    for(int i = 0 ; i < e ; ++i){
        cin>>edges[i].u>>edges[i].v>>edges[i].weight;
    }

    sort(edges.begin(),edges.end(),compare);

    DSU dsu(v);
    int mst_weight = 0;
    cout<<"\nEdges in MST:\n";
    for(auto &e:edges){
        if(dsu.findParent(e.u) != dsu.findParent(e.v)){
            dsu.unite(e.u,e.v);
            mst_weight+=e.weight;
            cout<<e.u<<" - "<<e.v<<" : "<<e.weight<<'\n';
        }
    }
    cout<<"\nTotal weight of MST: "<<mst_weight<<'\n';
    return 0;

    
}



// output
// Enter number of vertices and edges: 4 5
// Enter edges (u v weight):
// 0 1 10
// 0 2 6
// 0 3 5
// 1 3 15
// 2 3 4