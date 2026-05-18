// Write a C++ program to maintain Children Sum Property in Binary Tree

/*
                2
               / \
             35   10
            / \   / \
           2  3   5  2
*/

/*
    Time Complexity: O(N)

    Space Complexity: O(H), where H is tree height due to recursion stack.
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

bool isLeaf(Node* root) {
    if(!root->left && !root->right) return true;
    return false;
}

void childrenSum(Node* root){
    if(!root) return;
    if(isLeaf(root)) return;

    if(!root->left){
        if(root->data < root->right->data) root->data = root->right->data;
        else root->right->data = root->data;

        childrenSum(root->right);
    }
    else if(!root->right){
        if(root->data < root->left->data) root->data = root->left->data;
        else root->left->data = root->data;

        childrenSum(root->left);
    }
    else{
        int leftChild = root->left->data;
        int rightChild = root->right->data;

        if(root->data <= (leftChild + rightChild)){
            root->data = leftChild + rightChild;
        }else {
            if(leftChild < rightChild) root->left->data = root->data - rightChild;
            else root->right->data = root->data - leftChild;
        }

        childrenSum(root->left);
        childrenSum(root->right);

        leftChild = root->left->data;
        rightChild = root->right->data;

        root->data = leftChild + rightChild;
    }

    return;
}

/*
    bool checkChldrenSumValid(Node* root){
        if(!root) return true;
        if(isLeaf(root)) return true;

        int leftChild = root->left ? root->left->data : 0;
        int rightChild = root->right ? root->right->data : 0;

        return (root->data == (leftChild + rightChild)) && checkChldrenSumValid(root->right) && checkChldrenSumValid(root->left);
    }
*/

int main(){

    Node* root = new Node(2);
    root->left = new Node(35);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(2);

    childrenSum(root);

    return 0;
}