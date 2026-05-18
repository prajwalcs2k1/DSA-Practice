// Write a C++ program to find the height for the given binary tree

/*
                1
               / \
              2   3
                 / \
                4   6
               /
              5  

*/

// Note:- Here i've taken nodes into consideratoin to calculate height of the tree

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

int heightOfTree(Node* root){
    if(!root) return 0;
    
    int leftDepth = heightOfTree(root->left);
    int rightDepth = heightOfTree(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);

    cout<<"Maximum depth of the given binary tree is : "<<heightOfTree(root)<<endl;

    return 0;
}