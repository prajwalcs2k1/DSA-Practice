// Given a undirected unweighted acyclic graph, construct an array subSize[], where subSize[V] stores the size of subtree rooted at node V

#include<bits/stdc++.h>
using namespace std;

void subTreeSizeFinderHelper(vector<int> *adjList, vector<int>&ans, int currNode, int parentNode){
    for(auto it : adjList[currNode]){
        if(it != parentNode){
            subTreeSizeFinderHelper(adjList, ans, it, currNode);
            ans[currNode] += ans[it];
        }
    }
    ans[currNode] += 1;
    return;
}

vector<int> subTreeSizeFinder(vector<int> * adjList, int nodes){
    vector<int> ans(nodes + 1, 0);
    subTreeSizeFinderHelper(adjList, ans, 1, 1);
    return ans;
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
    int V;
    cout<<"Enter the node to find the subtree size : ";
    cin>>V;
    if(V > nodes){
        cout<<"Invalid node provided!!\n";
        return 0;
    }
    vector<int> res = subTreeSizeFinder(adjList, nodes);
    cout<<"Subtree size of node "<<V<<" is "<<res[V]<<endl;
    return 0;
}