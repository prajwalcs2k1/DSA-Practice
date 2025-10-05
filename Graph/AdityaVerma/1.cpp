// Write a C++ program to implement Breadth First Search (BFS) & Depth First Search (DFS) algorithms for connected undirected graph

#include<bits/stdc++.h>
using namespace std;

class adjList{
private:
    unordered_map<int, vector<int>> mp;
    int nodes;
public:
    void constructGraph(vector<int> * edgeArr, int n){
        for(int i=0; i<n; i++){
            int v1 = edgeArr[i][0];
            int v2 = edgeArr[i][1];
            mp[v1].push_back(v2);
            mp[v2].push_back(v1);
        }
        this->nodes = mp.size();
        return;
    }

    void display(){
        for(auto it = mp.begin(); it != mp.end(); it++){
            int v1 = it->first;
            cout<<"Neighbors of "<<v1<<" are : [ ";
            for(int v2 : it->second){
                cout<<v2<<" ";
            }
            cout<<"]\n";
        }
        return;
    }

    void BFS(){
        int root;
        cout<<"Enter the root node for BFS traversal : ";
        cin>>root;
        vector<bool> vis(this->nodes+1, false);
        queue<int> q;
        q.push(root);
        vis[root] = true;
        cout<<"BFS traversal of the graph from "<<root<<" is : ";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<" ";
            for(int ver : mp[node]){
                if(!vis[ver]){
                    vis[ver] = true;
                    q.push(ver);
                }
            }
        }
        cout<<"\n";
        return;
    }

    void dfsHelper(int root, vector<bool> & vis){
        cout<<root<<" ";
        for(int ver : mp[root]){
            if(!vis[ver]){
                vis[ver] = true;
                dfsHelper(ver, vis);
            }
        }
        return;
    }

    void DFS(){
        int root;
        cout<<"Enter the root node for DFS traversal : ";
        cin>>root;
        vector<bool> vis(this->nodes+1, false);
        cout<<"DFS traversal of the graph from "<<root<<" is : ";
        vis[root] = true;
        dfsHelper(root, vis);
        cout<<"\n";
        return;
    }
};

int main(){

    int nodes, edges;
    cout<<"Enter the no. of nodes & edges : ";
    cin>>nodes>>edges;
    vector<int> * edgeArr = new vector<int>[edges];
    int v1, v2;
    cout<<"Enter the edges : ";
    for(int i=0; i<edges; i++){
        cin>>v1>>v2;
        edgeArr[i].push_back(v1);
        edgeArr[i].push_back(v2);
    }
    adjList graph;
    graph.constructGraph(edgeArr, edges);
    graph.display();
    graph.BFS();
    graph.DFS();

    delete[] edgeArr; // free memory
    return 0;
}