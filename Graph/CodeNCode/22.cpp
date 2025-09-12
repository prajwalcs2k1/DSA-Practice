// Write a C++ program to find Lowest Common Ancestor(LCA) of 2 given nodes in an undirected unweighted graph

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> & adjList, int node, vector<int> &path, vector<bool> &vis, int currNode){
    path.push_back(currNode);
    if(currNode == node) return true;
    for(int child : adjList[currNode]){
        if(!vis[child]){
            vis[child] = true;
            if(dfs(adjList, node, path, vis, child)) return true;
        }
    }
    path.pop_back();
    return false;
}

int findLCAUsingBF1(vector<vector<int>> & adjList, int node1, int node2, int nodes){
    vector<int> path1, path2;
    vector<bool> vis(nodes+1, false);
    vis[1]= true;
    dfs(adjList, node1, path1, vis, 1);
    vis = vector<bool>(nodes+1, false);
    vis[1]= true;
    dfs(adjList, node2, path2, vis, 1);
    int lca = -1;
    for(int i=0; i<path1.size() && i<path2.size(); i++){
        if(path1[i] == path2[i]){
            lca = path1[i];
        }else break;
    }
    return lca;
}

void findParentsAndLevel(vector<vector<int>> & adjList, vector<int>&parent, vector<int>&levelArr, vector<bool> &vis, int currNode, int parentNode, int level){
    parent[currNode] = parentNode;
    for(int child : adjList[currNode]){
        if(vis[child]) continue;
        vis[child] = true;
        levelArr[child] = level+1;
        findParentsAndLevel(adjList, parent, levelArr, vis, child, currNode, level+1);
    }
    return;
}

int findLCAUsingBF2(vector<vector<int>> & adjList, int node1, int node2, int nodes){
    vector<int> parent(nodes+1, -1), level(nodes+1, 0);
    vector<bool> vis(nodes+1, false);
    vis[1] = true;
    findParentsAndLevel(adjList, parent, level, vis, 1, -1, 0);
    if(level[node1] < level[node2]) swap(node1, node2);
    int diff = level[node1]-level[node2];
    while(diff){
        node1 = parent[node1];
        diff--;
    }
    if(node1 == node2) return node1;
    while(node1 != node2){
        node1 = parent[node1];
        node2 = parent[node2];
    }
    return node1;
}

int main(){
    int nodes, edges;
    cout<<"Enter the no. of nodes & edges: ";
    cin>>nodes>>edges;
    vector<vector<int>> adjList(nodes+1);
    int v1, v2;
    cout<<"Enter "<<edges<<" edges: ";
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    int u, v;
    cout<<"Enter the 2 nodes to find LCA: ";
    cin>>u>>v;
    cout<<"LCA of "<<u<<" & "<<v<<" is : "<<findLCAUsingBF1(adjList, u, v, nodes)<<endl;
    cout<<"LCA of "<<u<<" & "<<v<<" is : "<<findLCAUsingBF2(adjList, u, v, nodes)<<endl;


    return 0;
}