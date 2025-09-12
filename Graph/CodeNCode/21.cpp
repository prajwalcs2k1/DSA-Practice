// Write a C++ program to find the sum of edges of the minimum spanning tree using Kruskal's algorithm of a given weighted undirected graph
/*
    A Minimum Spanning Tree (MST) is defined as:
        -A spanning tree of a connected, weighted, undirected graph that connects all the vertices together with the minimum possible total edge weight.

    Key points:
        -Spanning Tree → A subgraph that includes all the vertices of the original graph and is a tree (connected and has no cycles).
        -Minimum → Out of all possible spanning trees, the MST has the smallest possible sum of edge weights.
        -Uniqueness → An MST may not always be unique; if multiple edges have the same weights, there can be more than one MST.
*/
#include<bits/stdc++.h>
using namespace std;

class DSU{
private:
    vector<int> ds, rank;
public:
    DSU(int nodes){
        ds = vector<int>(nodes+1, 0);
        rank = vector<int>(nodes+1, 0);
        for(int i=1; i<=nodes; i++){
            ds[i] = i;
        }
    }

    int find(int v){
        if(ds[v] == v) return v;
        return ds[v] = find(ds[v]);
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(rank[u] == rank[v]){
            rank[u]++;
            ds[v] = u;
        }else if(rank[v] > rank[u]){
            ds[u] = v;
        }else if(rank[u] > rank[v]){
            ds[v] = u;
        }
    }
};


int mstUsingKruskalAlgo(vector<tuple<int, int, int>> edges, int nodes){
    sort(edges.begin(), edges.end());
    DSU ds(nodes);
    int mstWeight = 0;
    int n = edges.size();
    for(int i=0; i<n; i++){
        int w = get<0>(edges[i]);
        int v1 = get<1>(edges[i]);
        int v2 = get<2>(edges[i]);
        if(ds.find(v1) == ds.find(v2)) continue;
        minEdgeWeight += w;
        ds.merge(v1, v2);
    }
    return mstWeight;
}

int main(){

    int nodes, edges;
    cout<<"Enter the no. of nodes & edges : ";
    cin>>nodes>>edges;
    /*
        vector<int> * adjList = new vector<int>[edges];     // adjList is a pointer pointing to the first element where each element is of type vector<int> & size of adjList is 'edges'
        for(int i=0; i<edges; i++){
            adjList[i].resize(3, 0);                        // initially every vector's size is 0, hence resizing each element of adjList to 3
        }
    */
    cout<<"Enter the < edge_weight, vertex_1, vertex_2 > in order : ";
    vector<tuple<int, int, int>> adjList(edges);
    int v1, v2, e;
    for(int i=0; i<edges; i++){
        cin>>e>>v1>>v2;
        adjList[i] = {e,v1,v2};
    }

    cout<<"Edge weight of mst of the given graph is : "<<mstUsingKruskalAlgo(adjList, nodes)<<endl;
    return 0;
}