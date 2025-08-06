// Write a C++ program to print the single source shortest path from a target node to every other node in a unidrected acyclic graph
/*
    Note: Single Source Shortest Path in a unirected acyclic graph means path value from target node to every other nodes in the graph
    Undirected Acyclic Graph = Tree
    So it will be more justified if this is called as finding SSSP on a tree
*/

#include<bits/stdc++.h>
using namespace std;

void dfsHelper(vector<int>&ans, vector<bool>&vis, vector<int>*adjList, int currNode, int dist){
    if(vis[currNode]) return;
    vis[currNode] = true;
    ans[currNode] = dist;
    for(auto it : adjList[currNode]) dfsHelper(ans, vis, adjList, it, dist + 1);
    return;
}

void SSSP(vector<int>&ans, vector<int>*adjList, const int N, int targetNode){
    vector<bool>vis(N+1, false);
    dfsHelper(ans, vis, adjList, targetNode, 0);
    return;
}

void printSSSP(vector<int>&ans, int targetNode, const int N){
    for(int i=1; i<(N+1); i++){
        cout<<"Distance from "<<targetNode<<" to "<<i<<" is : "<<ans[i]<<"\n";
    }
    return;
}

int main(){
    const int N = 6;
    int targetNode;
    cout<<"Select the target node from 1 to 6 : ";
    cin>>targetNode;
    if((targetNode <= 0) || (targetNode > 6)){
        cout<<"Invalid target node provided!!\n";
        return 0;
    }
    vector<int> adjList[N+1];
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[2].push_back(3);
    adjList[2].push_back(4);
    adjList[3].push_back(2);
    adjList[4].push_back(2);
    adjList[4].push_back(5);
    adjList[4].push_back(6);
    adjList[5].push_back(4);
    adjList[6].push_back(4);
    vector<int>ans(N+1, 0);
    SSSP(ans, adjList, N, targetNode);
    printSSSP(ans, targetNode, N);
    return 0;
}