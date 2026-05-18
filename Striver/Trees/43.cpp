// Write a C++ program to Recover BST

/*
                        6
                      /   \
                     5     12
                   /  \   /  \
                  4    7 10  14
                      /     /   
                     8     13
*/
/*
    You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

void inorderTraversal(Node* root, pair<Node*, Node*> &swappedNodes, Node* &prev){
    if(!root) return;

    inorderTraversal(root->left, swappedNodes, prev);

    if(prev && (root->data < prev->data)){        
        if(swappedNodes.first) swappedNodes.second = root;
        else{
            swappedNodes.first = prev;
            swappedNodes.second = root;
        }
    }

    prev = root;

    inorderTraversal(root->right, swappedNodes, prev);

    return;
}

int main(){

    Node* root = new Node(6);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(8);
    root->right->right->left = new Node(13);

    pair<Node*, Node*> swappedNodes;
    swappedNodes.first = nullptr;
    swappedNodes.second = nullptr;

    Node* prev = nullptr;

    inorderTraversal(root, swappedNodes, prev);

    if(swappedNodes.first && swappedNodes.second){
        swap(swappedNodes.first->data, swappedNodes.second->data);
        cout<<"Nodes are found and BST is corrected\n";
    }

    return 0;
}