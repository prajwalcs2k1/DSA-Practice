// Given 2 nodes A & B, write a C++ program to check if node A belongs to the subtree of node B
#include<bits/stdc++.h>
using namespace std;

void checkSubtreeHelper(vector<int> *adjList, vector<int>&in, vector<int>&out, vector<bool>&vis, int node, int &timer){
    in[node] = timer++;
    vis[node] = true;
    for(auto it : adjList[node]){
        if(!vis[it]){
            checkSubtreeHelper(adjList, in, out, vis, it, timer);
        }
    }
    out[node] = timer++;
    return;
}

bool checkSubtree(vector<int> *adjList, int nodes, int node1, int node2){
    vector<int> in(nodes + 1);
    vector<int> out(nodes + 1);
    vector<bool>vis(nodes + 1, false);
    int timer = 1;
    checkSubtreeHelper(adjList, in, out, vis, 1, timer);
    return (in[node1] < in[node2]) && (out[node1] > out[node2]);
}

int main(){

    int nodes, edges;
    cout<<"Enter the no. of nodes and edges in the graph : ";
    cin>>nodes>>edges;
    vector<int> adjList[nodes+1];       // 1 indexed graph hence using nodes+1 as size in the array definition
    cout<<"Enter the edges : ";
    for(int i=0; i<edges; i++){
        int v1, v2;
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    int node1, node2;
    cout<<"Enter the 2 nodes : ";
    cin>>node1>>node2;
    bool isPartOfSubTree = checkSubtree(adjList, nodes, node1, node2);
    if(isPartOfSubTree){
        cout<<node2<<" is part of subtree of "<<node1<<endl;
    }else{
        cout<<node2<<" is not a part of subtree of "<<node1<<endl;
    }
    return 0;
}