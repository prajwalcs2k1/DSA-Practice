// Write a C++ program to print the Bottom View of the given binary tree

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

void bottomView(Node* root, int &minHD, int &maxHD, unordered_map<int, int> &mp){
    if(!root) return;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto [node, vertical] = q.front();
        q.pop();

        minHD = min(minHD, vertical);
        maxHD = max(maxHD, vertical);

        mp[vertical] = node->data;
        if(node->left) q.push({node->left, vertical-1});
        if(node->right) q.push({node->right, vertical+1});
    }

    return;
}

void displayMap(unordered_map<int, int> mp, int minHD, int maxHD){

    for(int i=minHD; i<=maxHD; i++){
        cout<<mp[i]<<" ";
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

    int minHD = INT_MAX;
    int maxHD = INT_MIN;
    unordered_map<int, int> mp;
    bottomView(root, minHD, maxHD, mp);

    displayMap(mp, minHD, maxHD);

    return 0;
}