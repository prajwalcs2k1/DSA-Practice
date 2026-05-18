// Write a C++ program to insert a node in the BST

/*
                        8
                      /   \
                     5     12
                   /  \   /  \
                  4    7 10  14
                      /     /   
                     6     13
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

void insertInBST(Node* root, int K){
    if(!root) return;
    if(!root->left && !root->right){
        if(K < root->data) root->left = new Node(K);
        else root->right = new Node(K);
        return;
    }

    if(K < root->data) {
        if(!root->left) {
            root->left = new Node(K);
            return;
        }
        else insertInBST(root->left, K);
    }
    else {
        if(!root->right) {
            root->right = new Node(K);
            return;
        }
        else insertInBST(root->right, K);
    }

    return;
}

int main(){

    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(13);

    int K;
    cout<<"Enter the new node to insert in BST : ";
    cin>>K;

    insertInBST(root, K);

    return 0;
}