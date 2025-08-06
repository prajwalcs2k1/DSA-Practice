// Write a C++ program to find the number of connected components in a given undirected acyclic graph.

#include<bits/stdc++.h>
using namespace std;

void dfsHelper(vector<int>*adj, vector<bool>&vis, int currNode){
    if(vis[currNode]) return;
    vis[currNode] = true;
    for(auto it : adj[currNode]) dfsHelper(adj, vis, it);
    return;
}

int connectedComponents(vector<int>*adj, const int N){
    vector<bool> vis(N, false);
    int count = 0;
    for(int i=0; i<N; i++){
        if(!vis[i]){
            dfsHelper(adj, vis, i);
            count++;
        }
    }
    return count;
}

int main(){
    const int N = 10; // maximum number of nodes
    vector<int> adj[N]; 

    // Component 1: Nodes 0 - 2
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    // Component 2: Nodes 3 - 5
    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(5);
    adj[5].push_back(4);

    // Component 3: Nodes 6 - 9
    adj[6].push_back(7);
    adj[7].push_back(6);

    adj[7].push_back(8);
    adj[8].push_back(7);

    adj[8].push_back(9);
    adj[9].push_back(8);
    cout<<"Connected components : "<<connectedComponents(adj, N)<<endl;
    return 0;
}