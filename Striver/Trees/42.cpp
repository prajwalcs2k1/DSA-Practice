// Write a C++ program to solve Two Sum in BST

/*
    Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
*/

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

void inorderTraversal(Node* root, vector<int>& inorder){
    if(!root) return;

    inorderTraversal(root->left, inorder);
    inorder.push(root->data);
    inorderTraversal(root->right, inorder)
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
    cout<<"Enter the K value : ";
    cin>>K;

    vector<int> inorder;
    inorderTraversal(root, inorder);

    int i, j;
    i = 0, j = inorder.size()-1;
    while(i < j){
        int sum = inorder[i] + inorder[j];
        if(sum == K){
            cout<<"Sum found at index "<<i<<" & "<<j<<endl;
            return 0;
        }

        if(sum < K) i++;
        else j--;        
    }

    cout<<"Sum not found!\n";

    return 0;
}