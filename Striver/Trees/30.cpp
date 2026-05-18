// Write a C++ program to find a search element in the given binary search tree

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

/*
    Node* searchInBST(Node* root, int target){
        if(!root) return nullptr;

        while((root) && (root->data != target)){
            root = (root->data > target) ? root->left : root->right;
        }

        return root;
    }
*/

Node* searchInBST(Node* root, int target){
    if(!root) return nullptr;

    if(target == root->data) return root;

    if(target > root->data) return searchInBST(root->right, target);

    return searchInBST(root->left, target);
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

    int target;
    cout<<"Enter the search element : ";
    cin>>target;

    Node* node = searchInBST(root, target);
    if(!node) cout<<"Target element is not present in the BST!\n";
    else cout<<"Target element is present in the BST\n";

    return 0;
}