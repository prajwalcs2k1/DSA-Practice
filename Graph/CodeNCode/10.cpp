// Write a C++ program to print the BFS traversal of a undirected unweighted graph

#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<int>*adjList, int nodes){
    vector<int>res;
    vector<bool>vis(nodes + 1);
    queue<int>q;
    q.push(1);
    vis[1] = true;
    while(q.size()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto child : adjList[node]) { 
            if(!vis[child]){
                vis[child] = true;
                q.push(child);
            }
        }
    }
    return res;
}

int main(){

    int nodes, edges;
    cout<<"Enter the no. of nodes & edges : ";
    cin>>nodes>>edges;
    cout<<"Enter the edges : ";
    vector<int> *adjList = new vector<int>[nodes + 1];
    for(int i=0; i<edges; i++){
        int v1, v2;
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    vector<int> ans = BFS(adjList, nodes);
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}