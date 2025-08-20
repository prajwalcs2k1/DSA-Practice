// Write a C++ program to print the Strongly Connected Components in a directed graph

/*
    Kosaraju’s Algorithm (to find Strongly Connected Components)
    Input: A directed graph 𝐺=(𝑉,𝐸)
    Output: All Strongly Connected Components (SCCs) of the graph
*/

/*
    Steps:

    1. First DFS (on original graph)

        -Initialize all nodes as unvisited.
        -For each unvisited node, run DFS and, after fully exploring a node, push it onto a stack (or record finishing time).
        -This gives us nodes ordered by decreasing finishing times.

    2. Transpose the graph

        -Reverse the direction of every edge in the graph.
        -(If edge was u → v, make it v → u).

    3. Second DFS (on transposed graph)

        -Reset all nodes as unvisited.
        -While the stack is not empty:
            --Pop the top node u.
            --If u is unvisited, run DFS from u on the transposed graph.
            --All nodes reached in this DFS form one SCC.
        -Repeat until stack is empty.
*/

#include<bits/stdc++.h>
using namespace std;

void dfs1(vector<int> * adjList, int parent, stack<int> &out, vector<bool> &vis){
    for(int child : adjList[parent]){
        if(!vis[child]){
            vis[child] = true;
            dfs1(adjList, child, out, vis);
        }
    }
    out.push(parent);
    return;
}

void transpose(vector<int> * transposedGraph, vector<int> * adjList, int nodes){
    int k = nodes;
    while(nodes){
        for(int child : adjList[nodes]){
            transposedGraph[child].push_back(nodes);
        }
        nodes--;
    }
    return;
}

void dfs2(vector<int> * transposedGraph, int parent, vector<bool> &vis){
    cout<<parent<<" ";
    for(int child : transposedGraph[parent]){
        if(!vis[child]){
            vis[child] = true;
            dfs2(transposedGraph, child, vis);
        }
    }
    return;
}

void printSCC(vector<int> * adjList, int nodes){
    stack<int> out;

    // First traverse the given graph and fill the stack
    vector<bool> vis(nodes+1, false);
    for(int i=1; i<=nodes; i++){
        if(!vis[i]){
            dfs1(adjList, i, out, vis);
        }
    }

    // Transpose the graph
    vector<int> * transposedGraph = new vector<int>[nodes+1];
    transpose(transposedGraph , adjList, nodes);

    // Traverse the transposed graph to find & print the SCCs
    vis = vector<bool>(nodes+1, false);
    int count = 1;
    while(!out.empty()){
        if(!vis[out.top()]){
            cout<<"Vertices of SCC"<<count<<" is : ";
            vis[out.top()] = true;
            dfs2(transposedGraph, out.top(), vis);
            cout<<"\n";
            count++;
        }
        out.pop();
    }
}

int main(){

    int nodes, edges;
    cout<<"Enter the nodes no. of nodes & edges of a directed graph : ";
    cin>>nodes>>edges;
    vector<int> * adjList = new vector<int>[nodes+1];
    int v1, v2;
    cout<<"Enter the edges of the graph : ";
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
    }
    printSCC(adjList, nodes);
    return 0;
}