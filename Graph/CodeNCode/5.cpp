// Write a C++ program to check if the given graph is a bipartite graph or not

#include<bits/stdc++.h>
#define MAX 100
using namespace std;

bool bipartiteHelper(vector<int> *graph, int nodes, vector<int>&color, int currNode, int currColor){
    if(color[currNode] != -1){
        if(color[currNode] != currColor) return false;
        return true;
    }
    color[currNode] = currColor;
    for(auto it : graph[currNode]){
        if(!bipartiteHelper(graph, nodes, color, it, !currColor)) return false;
    }

    return true;
}

string isBipartite(vector<int> *graph, int nodes){
    vector<int> color(nodes, -1);
    return bipartiteHelper(graph, nodes, color, 0, 0) ? "bipartite" : "not bipartite";
}


int main(){
    vector<int> bipartiteGraph[4];
    vector<int> nonBipartiteGraph[3];

    // 4 nodes: 0, 1, 2, 3
    // Edges: (0-1), (0-3), (1-2), (2-3)
    bipartiteGraph[0].push_back(1);
    bipartiteGraph[0].push_back(3);
    
    bipartiteGraph[1].push_back(0);
    bipartiteGraph[1].push_back(2);
    
    bipartiteGraph[2].push_back(1);
    bipartiteGraph[2].push_back(3);
    
    bipartiteGraph[3].push_back(0);
    bipartiteGraph[3].push_back(2);

    // 3 nodes: 0, 1, 2
    // Edges: (0-1), (1-2), (2-0)
    nonBipartiteGraph[0].push_back(1);
    nonBipartiteGraph[0].push_back(2);
    
    nonBipartiteGraph[1].push_back(0);
    nonBipartiteGraph[1].push_back(2);
    
    nonBipartiteGraph[2].push_back(0);
    nonBipartiteGraph[2].push_back(1);

    cout<<"Graph 1 is "<<isBipartite(bipartiteGraph, 4)<<endl;
    cout<<"Graph 2 is "<<isBipartite(nonBipartiteGraph, 3)<<endl;
    

    return 0;
}