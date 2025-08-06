// Write a C++ program to implement undirected graph using Adjacency List

#include<bits/stdc++.h>
using namespace std;

void graphUsingArrayOfVectors(int nodes, int edges, pair<int, int> p[]){
    vector<int> graph[nodes+1];       // Static memory allocation
    for(int i=0; i<edges; i++){
        int v1 = p[i].first;
        int v2 = p[i].second;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // Display graph
    for(int i=1; i<(nodes+1); i++){
        cout<<i<<" ---> [ ";
        for(auto it : graph[i]) cout<<it<<" ";
        cout<<"]\n";
    }
    return;
}

void graphUsingVectorsOfVectors(int nodes, int edges, pair<int, int> *p){
    vector<vector<int>> graph(nodes+1);         // Outer vector is static, Inner vector is dynamic
    for(int i=0; i<edges; i++){
        int v1 = p[i].first;
        int v2 = p[i].second;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // Display graph
    for(int i=1; i<(nodes+1); i++){
        cout<<i<<" ---> [ ";
        for(auto it : graph[i]) cout<<it<<" ";
        cout<<"]\n";
    }
    return;
}

int main(){

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
    graphUsingArrayOfVectors(n, m, p);
    graphUsingVectorsOfVectors(n, m, p);
    return 0;
}