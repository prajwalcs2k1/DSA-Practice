// Write a C++ porgram to print the vertical order traversal of the given binary tree

/*
                1
               / \
              2   3
             / \
            4   5
               / \
              6   7
             /   / \
            10  8   9
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

void verticalOrderTraversal(Node* root, map<int, vector<int>> &mp){
    if(!root) return;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto [node, vertical] = q.front();
        q.pop();
        
        mp[vertical].push_back(node->data);
        if(node->left) q.push({node->left, vertical-1});
        if(node->right) q.push({node->right, vertical+1});
    }
    
    return;
}

void displayMap(map<int, vector<int>> mp){
    cout<<"Vertical order traversal is as follows : ";
    for(auto &it : mp){
        for(auto ele : it.second) cout<<ele<<" ";
    }
    cout<<"\n";

    return;
}

int main(){

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6); 
    root->left->right->left->left = new Node(10); 
    root->left->right->right = new Node(7); 
    root->left->right->right->left = new Node(8); 
    root->left->right->right->right = new Node(9);

    map<int, vector<int>> mp;       // using ordered_map here because it sorts the vertical values by default which helps in printing the correct node values 
    verticalOrderTraversal(root, mp);

    displayMap(mp);

    return 0;
}