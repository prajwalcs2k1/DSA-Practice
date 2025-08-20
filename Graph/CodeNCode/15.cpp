// Write a C++ program to print the topological sorting of a directed acyclic graph

#include<bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int>* adjList, int nodes, vector<int>&inDegree){

    queue<int>q;
    for(int i=1; i<nodes+1; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adjList[node]){
            if(inDegree[it] != 0){
                inDegree[it]--;
            }
            if(inDegree[it] == 0) q.push(it);
        }
        cout<<node<<" ";
    }
    cout<<"\n";
    return;
}

int main() {

    int nodes, edges;
    cout<<"Enter the no. of nodes & edges of a directed graph : ";
    cin>>nodes>>edges;
    vector<int> * adjList = new vector<int>[nodes + 1];
    vector<int> inDegree(nodes + 1, 0);
    int v1, v2;
    cout<<"Enter the edges : ";
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        inDegree[v2]++;
    }
    topologicalSort(adjList, nodes, inDegree);
    return 0;
}