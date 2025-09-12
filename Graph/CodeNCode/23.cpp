// Write a C++ program to find Kth ancestor of a node in a acyclic unweighted undirected graph ( basically a tree ) using binary lifting

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> * adjList, vector<int> &levelArr, vector<vector<int>> &binaryLiftingArr, int currNode, int parent, int level=0){
    levelArr[currNode] = level;
    binaryLiftingArr[currNode][0] = parent;
    for(int child : adjList[currNode]){
        if(child == parent) continue;
        dfs(adjList, levelArr, binaryLiftingArr, child, currNode, level+1);
    }
    return;
}


int KthAncestor(vector<int> * adjList, int nodes, int root, int K){
    vector<int> level(nodes+1, 0);
    int LOG = ceil(log2(nodes));
    vector<vector<int>> binaryLiftingArr(nodes+1, vector<int>(LOG, -1));
    // vector<bool> vis(nodes+1, false);            // not required as it is already known we are given acyclic unweighted undirected graph ( basically a tree )
    int res = root;
    dfs(adjList, level, binaryLiftingArr, 1, -1, 0);
    for(int i=1; i<=nodes; i++){
        for(int j=1; j<LOG; j++){
            binaryLiftingArr[i][j] = binaryLiftingArr[i][j-1] == -1 ? -1 : binaryLiftingArr[binaryLiftingArr[i][j-1]][j-1];
        }
    }

    for(int j=0; j<LOG; j++){
        if(K & (1 << j)){
            res = binaryLiftingArr[res][j];
            if(res == -1) return res;
        }
    }
    return res;    
}

int main(){

    int nodes, edges, K, root;
    cout<<"Enter the no. of nodes & edges of the graph : ";
    cin>>nodes>>edges;
    vector<int> * adjList = new vector<int>[nodes+1];
    int v1, v2;
    cout<<"Enter the edges of the graph : ";
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    cout<<"Enter the Kth value & root node for which the Kth value is to be found : ";
    cin>>K>>root;
    if((K>=nodes) || (root>nodes)){
        cout<<"Invalid values provided!!\n";
        return 0;
    }
    cout<<K<<"th ancestor of "<<root<<" is : "<<KthAncestor(adjList, nodes, root, K)<<endl;
    return 0;
}