// Write a C++ program to find the shortest distance from a root node to all other nodes in a directed/undirected weighted (positive edges) graph using Dijkstra algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstraAlgo(vector<pair<int, int>> * adjList, int nodes, int root){
    vector<int> res(nodes+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, root));
    res[root] = 0;
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        if(node.first > res[node.second])   continue;
        // cout<<"[ "<<node.first<<","<<node.second<<" ]"<<endl;
        for(auto child : adjList[node.second]){
            if((node.first + child.first) < res[child.second]){
                int weight = node.first + child.first;
                res[child.second] = weight;
                pq.push({weight, child.second});
            }
        }
    }

    return res;
}


int main(){
    int nodes, edges;
    cout<<"Enter the no. of nodes & edges in the graph : ";
    cin>>nodes>>edges;
    vector<pair<int, int>> * adjList = new vector<pair<int, int>>[nodes+1];
    int v1, v2, w, root;
    cout<<"Enter the edges with edge weight : ";
    while(edges--){
        cin>>v1>>v2>>w;
        adjList[v1].push_back({w, v2});
        adjList[v2].push_back({w, v1});
    }
    cout<<"Enter the root node : ";
    cin>>root;
    vector<int> res = dijkstraAlgo(adjList, nodes, root);
    for(int i=1; i<=nodes; i++){
        cout<<"Shortest distance from "<<root<<" to "<<i<<" is : "<<res[i]<<endl;
    }
    cout<<"\n";
    return 0;
}