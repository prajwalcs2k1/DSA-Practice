// Write a C++ program to build unique binary tree using given Inorder & Postorder traversal

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

Node * buildTree(vector<int> &Inorder, vector<int> &Postorder, int st, int en, int &postOrderIndex){
    if((st > en) || (postOrderIndex < 0)) return nullptr;

    Node* root;
    root = new Node(Postorder[postOrderIndex]);
    postOrderIndex--;
    if(st == en) return root;

    int rootIndex;
    for(int i=st; i<=en; i++){
        if(Inorder[i] == root->data){
            rootIndex = i;
            break;
        }
    }

    root->right = buildTree(Inorder, Postorder, rootIndex+1, en, postOrderIndex);
    root->left = buildTree(Inorder, Postorder, st, rootIndex-1, postOrderIndex);

    return root;
}

void postOrderTraversal(Node* root){
    if(!root) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";

    return;
}

int main(){

    vector<int> Inorder = {4, 2, 1, 3};
    vector<int> Postorder = {4, 2, 3, 1};
    int postOrderIndex = Postorder.size()-1;

    Node* root = buildTree(Inorder, Postorder, 0, Inorder.size()-1, postOrderIndex);
    cout<<"Postorder traversal of the tree is : ";
    postOrderTraversal(root);
    cout<<"\n";
    return 0;
}