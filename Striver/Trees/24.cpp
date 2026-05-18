// Write a C++ program to count the total nodes of a given complete binary tree using T.C. less than O(N)

/*
                1
               / \
              2   3
             /
            4
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

int findeLeftHeight(Node* root){
    if(!root) return 0;

    return 1 + findeLeftHeight(root->left);
}

int findRightHeight(Node* root){
    if(!root) return 0;

    return 1 + findRightHeight(root->right);
}

int countNodes(Node* root){
    if(!root) return 0;
    int leftHeight = findeLeftHeight(root);
    int rightHeight = findRightHeight(root);

    if(leftHeight == rightHeight) return pow(2, leftHeight) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout<<"Total number of nodes in the given complete binary tree is : "<<countNodes(root)<<endl;

    return 0;
}