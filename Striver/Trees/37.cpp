// Write a C++ program to check if the given binary tree is a BST or not

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

bool checkValidBST(Node* curr, Node* &parent){
    if(!curr) return true;

    if(!checkValidBST(curr->left, parent)) return false;

    if(parent != nullptr){
        if(curr->data < parent->data) return false;
    }
    parent = curr;

    return checkValidBST(curr->right, parent);
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

    Node* parent = nullptr;

    bool isBSTValid = checkValidBST(root, parent);

    cout<<"Given binary tree is "<<(isBSTValid ? "a BST." : "not a BST.")<<endl;

    return 0;
}