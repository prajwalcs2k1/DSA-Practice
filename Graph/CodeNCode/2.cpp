// Write a C++ program to print the DFS [Depth First Search] traversal of a acyclic undirected graph
// T.C. is O(N+E) where N->nodes & E->edges
#include<bits/stdc++.h>
using namespace std;

void graphUsingArrayOfVectors(int nodes, int edges, pair<int, int> *p, vector<int> *graph){
    for(int i=0; i<edges; i++){
        int v1 = p[i].first;
        int v2 = p[i].second;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    return;
}

void dfsHelper(vector<int> *graph, vector<bool>&vis, vector<int>&res, int currNode){
    if(vis[currNode]) return;
    vis[currNode] = true;
    res.push_back(currNode);
    for(auto it : graph[currNode]) dfsHelper(graph, vis, res, it);
    return;
}


vector<int> DFS(vector<int> *graph, int nodes){
    vector<bool> vis(nodes+1 , false);
    vector<int> res;
    dfsHelper(graph, vis, res, 1);
    return res;
}

void displayDFS(vector<int>&ans){
    for(auto it : ans) cout<<it<<" ";
    return;
}

int main(){

    // Build a acyclic undirected graph
    int n, m;
    cout<<"Enter the number of nodes & edges : ";
    cin>>n>>m;
    pair<int, int> p[m];
    cout<<"Enter the edges : ";
    for(int i=0; i<m; i++){
        int v1, v2;
        cin>>v1>>v2;
        p[i].first = v1;
        p[i].second = v2;

    }
    vector<int> graph[n+1];
    graphUsingArrayOfVectors(n, m, p, graph);
    vector<int> ans = DFS(graph, n);
    displayDFS(ans);
    return 0;
}