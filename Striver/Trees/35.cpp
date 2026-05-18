// Write a C++ program to find the Kth largest & smallest element from the given BST

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

void inorderTraversal(Node* root, vector<int> &inorder){
    if(!root) return;

    inorderTraversal((*root).left, inorder);
    inorder.push_back(root->data);
    inorderTraversal((*root).right, inorder);

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
    cout<<"Enter the value of K : ";
    cin>>K;

    vector<int> inorder;
    inorderTraversal(root, inorder);

    cout<<"The "<<K<<"th smallest element is : "<<inorder[K-1]<<endl;
    cout<<"The "<<K<<"th largest element is : "<<inorder[inorder.size() - K]<<endl;

    return 0;
}