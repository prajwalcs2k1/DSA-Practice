// Write a C++ program to find arituclation points (cut-vertices) of a given undirect unweighted graph
/*
    Note :- Cut vertices are always part of bridges in a graph.
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *adjList, vector<bool> &vis, vector<int> &in, vector<int> &low, int currNode, int parent, int &timer){
    vis[currNode] = true;
    in[currNode] = low[currNode] = timer;
    timer++;
    int children = 0;
    for(auto child : adjList[currNode]){
        if(child == parent) continue;
        if(vis[child]){
            low[currNode] = min(low[currNode], in[child]);
        }
        else{
            dfs(adjList, vis, in, low, child, currNode, timer);
            low[currNode] = min(low[currNode] , low[child]);
            if((low[child] >= in[currNode]) && (parent != -1)) cout<<currNode<<" is an articulation point.\n";
            children++;
        }
    }
    if((children > 1) && (parent == -1)) cout<<currNode<<" is an articulation point.\n";
    return;
}

void findCutVertices(vector<int>*adjList, int nodes){
    vector<bool> vis(nodes + 1, false);
    vector<int> in(nodes + 1, 0);
    vector<int> low(nodes + 1, 0);
    int timer = 0;
    for(int i=1; i<nodes+1; i++){
        if(!vis[i]) dfs(adjList, vis, in, low, i, -1, timer);
    }
    return;
}

int main(){

    int nodes, edges;
    cout<<"Enter the no. of nodes & edges : ";
    cin>>nodes>>edges;
    vector<int> * adjList = new vector<int>[nodes + 1];
    int v1, v2;
    cout<<"Enter the edges : ";
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    findCutVertices(adjList, nodes);
    return 0;
}