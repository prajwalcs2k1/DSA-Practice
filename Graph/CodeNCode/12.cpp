// Given a unweighted undirected graph find all the back edges
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

void findBackEdges(vector<int> *adjList, vector<pair<int, int>>&backEdges, vector<bool>&vis, int currNode, int parent){
    vis[currNode] = true;
    for(auto child : adjList[currNode]){
        if(vis[child] && (child != parent)) {
            if(currNode < child)  // ensure only one direction is recorded
                backEdges.push_back({currNode, child});
        }
        if(!vis[child]) findBackEdges(adjList, backEdges, vis, child, currNode);
    }
    return;
}

int main(){

    int nodes, edges;
    cout<<"Enter the no. of nodes & edges : ";
    cin>>nodes>>edges;
    vector<int> * adjList = new vector<int>[nodes + 1];
    cout<<"Enter the edges of the graph : ";
    for(int i=0; i<edges; i++){
        int v1,v2;
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    vector<bool>vis(nodes+1, false);

    vector<pair<int, int>> backEdges;
    findBackEdges(adjList, backEdges, vis, 1, 1);

    cout<<"Back edges of the given graph are as follows :\n";
    for(auto it : backEdges){
        cout<<it.first<<"---"<<it.second<<endl;
    }
    return 0;
}