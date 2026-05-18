// Write a C++ program to print the boundary nodes of the below given binary tree

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

// Boundary traversal is the process of visiting all the boundary (outermost) nodes of a binary tree in a specific order.

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

bool isLeaf(Node* root){
    if(!root->left && !root->right) return true;
    return false;
}

void leftBoundary(Node* root, vector<int> &res){
    Node* curr = root->left;

    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }

    return;
}

void inOrderTraversal(Node* root, vector<int> &res){
    if(!root) return;
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }

    inOrderTraversal(root->left, res);
    inOrderTraversal(root->right, res);

    return;
}

void rightBoundary(Node* root, vector<int> &res){
    if(!root) return;
    vector<int> aux;
    Node* curr = root->right;
    while(curr){
        if(!isLeaf(curr)) aux.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i=aux.size()-1; i>=0; i--) res.push_back(aux[i]);

    return;

}

vector<int> boundaryTraversal(Node* root){
    vector<int> res;

    if(!root) return res;
    res.push_back(root->data);
    if(isLeaf(root)) return res;

    leftBoundary(root, res);
    inOrderTraversal(root, res);            // you can use any traversal as we first traverse left subtree and then right subtree
    rightBoundary(root, res);


    return res;
}

void displayVector(vector<int> res){

    cout<<"Boundary traversal is : ";
    for(int ele : res) cout<<ele<<" ";
    cout<<"\n";
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

    vector<int> res = boundaryTraversal(root);
    displayVector(res);

    return 0;
}