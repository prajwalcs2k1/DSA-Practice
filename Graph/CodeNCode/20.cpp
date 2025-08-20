// Write a C++ program to print the Strongly Connected Components in a directed graph using Tarjan's algorithm
/*
    For a node 𝑢 in a directed graph,
    lowlink[u] = the smallest discovery time (DFS number) of any node that can be reached from 𝑢, including:
        -𝑢 itself
        -all nodes reachable from 𝑢 through its DFS subtree
        -and possibly through back edges.
*/

/*
    Back edge in an undirected graph
    In DFS of an undirected graph:
        -A back edge is an edge that connects a node to an already visited ancestor (other than its parent).
        -That’s why we check low[u] = min(low[u], disc[v]) in bridge/articulation point problems.

    Back edge in a directed graph
    In DFS of a directed graph:
        -A back edge is an edge 𝑢→𝑣 where v is an ancestor of u in the DFS tree.
        -This indicates the presence of a cycle.
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> * adjList, vector<bool> &vis, stack<int> &activeNodes, vector<bool> &onStack, vector<int> &disc, vector<int> &low, int parent, int *counter){
    for(int child : adjList[parent]){
        if(!vis[child]){
            vis[child] = true;
            activeNodes.push(child);
            onStack[child] = true;
            disc[child] = low[child] = *counter;
            (*counter)++;
            dfs(adjList, vis, activeNodes, onStack, disc, low, child, counter);
            low[parent] = min(low[parent], low[child]);
        }else{
            if(onStack[child]){
                low[parent] = min(disc[child], low[parent]);
            }
        }
    }
    
    if(disc[parent] == low[parent]){
        cout << "SCC: ";
        while(true){
            int v = activeNodes.top();
            cout<<v<<" ";
            onStack[v] = false;
            activeNodes.pop();
            if(parent == v) break;
        }
        cout<<"\n";
    }

    return;
}

void printSCC(vector<int> * adjList, int nodes){
    vector<bool> vis(nodes+1, false);
    stack<int> activeNodes;
    vector<bool> onStack(nodes+1, false);
    vector<int> disc(nodes+1, 0), low(nodes+1, 0);
    int counter = 1;
    for(int i=1; i<=nodes; i++){
        if(!vis[i]){
            vis[i] = true;
            activeNodes.push(i);
            onStack[i] = true;
            disc[i] = counter;
            low[i] = counter;
            counter++;
            dfs(adjList, vis, activeNodes, onStack, disc, low, i, &counter);
        }
    }
    return;
}

int main(){
    int nodes, edges;
    cout<<"Enter the no. of nodes & edges of a directed graph : ";
    cin>>nodes>>edges;
    vector<int> * adjList = new vector<int>[nodes + 1];
    cout<<"Enter the edges : ";
    int v1, v2;
    while(edges--){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
    }
    printSCC(adjList, nodes);
    return 0;
}