// Write a C++ program to build unique binary tree using given Inorder & Preorder traversal

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

Node * buildTree(vector<int> &Inorder, vector<int> &Preorder, int st, int en, int &preOrderIndex){
    if((st > en) || (preOrderIndex >= Preorder.size())) return nullptr;

    Node* root = new Node(Preorder[preOrderIndex]);
    preOrderIndex++;
    if(st == en) return root;

    int rootIndex;
    for(int i=st; i<=en; i++){
        if(Inorder[i] == root->data) {
            rootIndex = i;
            break;
        }
    }
    root->left = buildTree(Inorder, Preorder, st, rootIndex-1, preOrderIndex);
    root->right = buildTree(Inorder, Preorder, rootIndex+1, en, preOrderIndex);

    return root;
}

void preOrderTraversal(Node* root){
    if(!root) return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

    return;
}

int main(){

    vector<int> Inorder = {4, 2, 1, 3};
    vector<int> Preorder = {1, 2, 4, 3};
    int preOrderIndex = 0;

    Node* root = buildTree(Inorder, Preorder, 0, Inorder.size()-1, preOrderIndex);
    cout<<"Preorder traversal of the tree is : ";
    preOrderTraversal(root);
    cout<<"\n";
    return 0;
}