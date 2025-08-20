// Write a C++ program to find the single source shortest path from node V to all the other nodes in an undirected unweighted cyclic/acyclic graph

#include<bits/stdc++.h>
using namespace std;

vector<int> SSSP(vector<int>*adjList, int nodes, int V){
    vector<bool> vis(nodes + 1, false);
    vector<int> ans(nodes + 1, 0);
    queue<int>q;
    q.push(V);
    vis[V] = true;
    while(q.size()){
        int node = q.front();
        q.pop();
        for(auto it : adjList[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
                ans[it] = ans[node] + 1;
            }
        }
    }
    return ans;
}

int main(){

    int nodes, edges;
    cout<<"Enter the no. nodes and edges : ";
    cin>>nodes>>edges;
    vector<int> *adjList = new vector<int>[nodes+1];
    cout<<"Enter the edges : ";
    for(int i=0; i<edges; i++){
        int v1, v2;
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    int V;
    cout<<"Enter the root node : ";
    cin>>V;
    vector<int> res = SSSP(adjList, nodes, V);
    for(int i=1; i<nodes+1; i++){
        cout<<"SSSP from node "<<V<<" to "<<i<<" is : "<<res[i]<<endl;
    }
    return 0;
}