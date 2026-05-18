// Construct a BST from a preorder traversal

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

// using pass by reference style here
Node* buildBSTBruteForceHlpr(Node* &root, int ele){
    if(!root){
        root = new Node(ele);
        return root;
    }

    if(ele < root->data) root->left = buildBSTBruteForceHlpr(root->left, ele);
    else root->right = buildBSTBruteForceHlpr(root->right, ele);

    return root;
}

Node* buildBSTBruteForce(vector<int> preorder){
    Node * root = nullptr;
    for(int i=0; i<preorder.size(); i++){
        buildBSTBruteForceHlpr(root, preorder[i]);
    }

    return root;
}

void printPreorder(Node* root){
    if(!root) return;

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);

    return;
}

Node* buildBSTOptimisedHlpr(vector<int> &preorder, int &index, int upperBound){
    if((index >= preorder.size()) || (preorder[index] > upperBound)) return nullptr;

    Node* root = new Node(preorder[index]);
    index++;

    root->left = buildBSTOptimisedHlpr(preorder, index, root->data);
    root->right = buildBSTOptimisedHlpr(preorder, index, upperBound);

    return root;
}

Node* buildBSTOptimised(vector<int> preorder){
    Node* root = nullptr;
    int index = 0;
    root = buildBSTOptimisedHlpr(preorder, index, INT_MAX);
    return root;
}

int main(){

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    cout<<"Preorder traversal (bruteForce): ";
    Node* rootA = buildBSTBruteForce(preorder);
    printPreorder(rootA);
    cout<<"\n";

    cout<<"Preorder traversal (optimised): ";
    Node* rootB = buildBSTOptimised(preorder);
    printPreorder(rootB);
    cout<<"\n";

    delete rootA, rootB;
    return 0;
}