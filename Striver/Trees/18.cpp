// Write a C++ program to print the path from Root to given Node of a binary tree

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

bool rootToNodePath(Node* root, int node, vector<int> &res){
    if(!root) return false;

    res.push_back(root->data);
    if(root->data == node) return true;

    if(rootToNodePath(root->left, node, res) || rootToNodePath(root->right, node, res)) return true;
    
    res.pop_back();
    return false;
}

void printPath(vector<int> res){

    cout<<"The path is : ";
    for(int ele : res) cout<<ele<<" ";
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

    vector<int> res;
    int node;
    cout<<"Enter the node to print path: ";
    cin>>node;
    rootToNodePath(root, node, res);

    printPath(res);

    return 0;
}