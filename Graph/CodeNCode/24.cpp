// Write a C++ program to find the Lowest Common Ancestor of 2 nodes using Binary Lifting in a tree

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> & adjList, int currNode, int parent, vector<int> & levelArr, int level, vector<vector<int>> & binaryLiftingArr){
    levelArr[currNode] = level;
    binaryLiftingArr[currNode][0] = parent;
    for(int child : adjList[currNode]){
        if(child == parent) continue;
        dfs(adjList, child, currNode, levelArr, level+1, binaryLiftingArr);
    }
    return;
}

int LCA(vector<vector<int>> & adjList, int nodes, int v1, int v2){
    vector<int>level(nodes+1, 0);
    int LOG = ceil(log2(nodes));
    vector<vector<int>> binaryLiftingArr(nodes+1, vector<int>(LOG, -1));
    dfs(adjList, 1, -1, level, 0, binaryLiftingArr);
    for(int i=1; i<=nodes; i++){
        for(int j=1; j<LOG; j++){
            binaryLiftingArr[i][j] = binaryLiftingArr[i][j-1] == -1 ? -1 : binaryLiftingArr[binaryLiftingArr[i][j-1]][j-1];
        }
    }
    if(level[v1] < level[v2]) swap(v1, v2);
    int diff = level[v1] - level[v2];
    for(int i=0; i<LOG; i++){
        if(diff & (1 << i)){
            v1 = binaryLiftingArr[v1][i];
        }
    }
    if(v1 == v2){
        return v1;
    }
    for(int i=LOG-1; i>=0; i--){
        if(binaryLiftingArr[v1][i] != -1){
            if(binaryLiftingArr[v1][i] != binaryLiftingArr[v2][i]){
                v1 = binaryLiftingArr[v1][i];
                v2 = binaryLiftingArr[v2][i];
            }
        }
    }
    return binaryLiftingArr[v1][0];
}

int main(){

    int nodes, edges;
    cout<<"Enter the no. of nodes & edges in the tree : ";
    cin>>nodes>>edges;
    vector<vector<int>> adjList(nodes+1);
    int v1, v2;
    cout<<"Enter the edges : ";
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    cout<<"Enter the 2 nodes to find LCA : ";
    cin>>v1>>v2;
    cout<<"LCA of the given 2 nodes are : "<<LCA(adjList, nodes, v1, v2)<<endl;
    return 0;
}