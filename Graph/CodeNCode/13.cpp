// Given a undirected unweighted graph write a C++ program to find all the bridge edges
/*
    Bridge Edge :- In graph theory, a bridge (also called a cut-edge) is an edge whose removal increases the number of connected components of the graph.
------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Back Edge :- A back edge in a graph is an edge that connects a vertex to one of its ancestors in a DFS (Depth-First Search) tree.

                It’s important to note:
                * Back edges exist only in directed or undirected graphs when you’re looking at them through DFS traversal.
                * They do not point to the immediate parent (that’s just the DFS tree edge); instead, they point upward in the DFS tree to an already visited vertex that is not the parent.
------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> * adjList, vector<bool> &vis, vector<int> &in, vector<int> &low, int currNode, int parent, int &timer){
    vis[currNode] = true;
    in[currNode] = low[currNode] = timer;
    timer++;
    for(auto child : adjList[currNode]){
        if(child == parent) continue;
        if(vis[child]){
            low[currNode] = min(low[currNode] , in[child]);         // by this we can know there was another way to reach the currNode
        }
        else{
            dfs(adjList, vis, in, low, child, currNode, timer);
            low[currNode] = min(low[currNode], low[child]);         // after dfs traversal we will check if the child node could be reached another way or not. this info will be stored in low[]
            if(low[child] > in[currNode]) cout<<currNode<<" - "<<child<<" is a bride edge.\n";          // if the low[chld] is greater than the in[currNode] then it means there is only one way to reach the childNode & that is via currNode, if there was another way to reach the child then the low[child] would be lesser than in[currNode]
        }
    }
    return;
}

void findBridgeEdges(vector<int> * adjList, int nodes){
    vector<bool> vis(nodes+1, false);
    vector<int> in(nodes+1, 0);
    vector<int> low(nodes+1, 0);
    int timer = 0;
    dfs(adjList, vis, in, low, 1, 1, timer);
    return;
}

int main(){

    int nodes, edges;
    cout<<"Enter the no. of nodes & edges : ";
    cin>>nodes>>edges;
    vector<int> * adjList = new vector<int>[nodes + 1];
    cout<<"Enter the edges : ";
    int v1,v2;
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    findBridgeEdges(adjList, nodes);
    return 0;
}