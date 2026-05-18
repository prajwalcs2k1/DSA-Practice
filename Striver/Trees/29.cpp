// Write a C++ program to flatten the given binary tree to linked list

/*
    Given the root of a binary tree, flatten the tree into a "linked list":
        The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
        The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

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

Node* flattenBTreeHelper(Node* root){
    if(!root) return nullptr;
    if(!root->left && !root->right) return root;

    Node* head = root;
    Node* leftHead = flattenBTreeHelper(root->left);
    Node* rightHead = flattenBTreeHelper(root->right);
    head->left = nullptr;
    head->right = leftHead;

    while(head->right){
        head = head->right;
    }

    head->right = rightHead;
    return root;
}

void flattenBTree(Node* root){
    if(!root) return;
    flattenBTreeHelper(root);
    return;
}

void printNodes(Node* root){
    if(!root) return;

    cout<<root->data<<" ";
    printNodes(root->right);

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

    flattenBTree(root);
    printNodes(root);
    cout<<"\n";

    return 0;

}