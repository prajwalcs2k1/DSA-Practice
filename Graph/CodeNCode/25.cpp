// Write a C++ program to find the distance between the given 2 nodes in a tree

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> * adjList, vector<int> &levelArr, vector<vector<int>> &up, int currNode, int parent, int level){
    levelArr[currNode] = level;
    up[currNode][0] = parent;
    for(int child : adjList[currNode]){
        if(child == parent) continue;
        dfs(adjList, levelArr, up, child, currNode, level+1);
    }

    return;
}

int findDist(vector<int> * adjList, int nodes, int v1, int v2){
    vector<int> level(nodes+1, 0);
    int LOG = ceil(log2(nodes));
    vector<vector<int>> up(nodes+1, vector<int>(LOG, -1));
    int res, lca;
    int n1 = v1;
    int n2 = v2;
    dfs(adjList, level, up, 1, -1, 0);
    for(int i=1; i<=nodes; i++){
        for(int j=1; j<LOG; j++){
            up[i][j] = up[i][j-1] == -1 ? -1 : up[up[i][j-1]][j-1];
        }
    }

    if(level[n1] < level[n2]) swap(n1, n2);
    int diff = level[n1] - level[n2];

    for(int i=0; i<LOG; i++){
        if(diff & (1 << i)){
            n1 = up[n1][i];
        }
    }

    if(n1 == n2){
        lca = n1;
        res = level[v1] + level[v2] - (2*level[lca]);
    }
    else{
        for(int i=LOG-1; i>=0; i--){
            if(up[n1][i] != -1){
                if(up[n1][i] != up[n2][i]){
                    n1 = up[n1][i];
                    n2 = up[n2][i];
                }
            }
        }
        lca = up[n1][0];
        res = level[v1] + level[v2] - (2*level[lca]);
    }

    return res;
}


int main(){
    int nodes, edges;
    cout<<"Enter the no. of nodes & edges of the tree : ";
    cin>>nodes>>edges;
    vector<int> * adjList = new vector<int>[nodes+1];
    int v1, v2;
    cout<<"Enter the edges : ";
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    cout<<"Enter the 2 nodes to find the distance : ";
    cin>>v1>>v2;
    cout<<"The distance between the 2 given nodes is : "<<findDist(adjList, nodes, v1, v2)<<endl;

    return 0;
}