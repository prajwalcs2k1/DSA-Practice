// Write a C++ program to check if the given undirected singly conncted component graph is cyclic or not
#include<bits/stdc++.h>
using namespace std;

bool isCyclicHelper(vector<int> *adjList, vector<bool>&vis, int currNode, int parentNode){
    vis[currNode] = true;
    for(auto it : adjList[currNode]){
        if(!vis[it]){
            if(isCyclicHelper(adjList, vis, it, currNode)) return true;
        }else{
            if(it != parentNode) return true;
        }
    }
    return false;
}

string isCyclic(vector<int> *adjList, int nodes){
    vector<bool> vis(nodes+1, false);
    return isCyclicHelper(adjList, vis, 1, 1) ? "cyclic." : "acyclic.";
}

int main(){

    int nodes, edges;
    cout<<"Enter the number of nodes & edges : ";
    cin>>nodes>>edges;
    vector<int> *adjList = new vector<int>[nodes+1];
    cout<<"Enter the edges of the graph : ";
    for(int i=0; i<edges; i++){
        int v1, v2;
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    cout<<"Given graph is "<<isCyclic(adjList, nodes)<<endl;
    delete[] adjList;
    return 0;
}