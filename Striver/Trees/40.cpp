// Write a C++ program to find the Inorder Successor & Predecessor of a input from the given BST

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

void inorderPredecessor(Node* root, Node* &pred){
    if(!root) return;
    pred = root;

    while(root->right){
        root = root->right;
    }
    pred = root;
    return;
}

void inorderSuccessor(Node* root, Node* &succ){
    if(!root) return;
    succ = root;

    while(root->left){
        root = root->left;
    }
    succ = root;
    return;
}

void findInorderSuccessorAndPredecessor(Node* root, int K, Node* &pred, Node* &succ){
    if(!root) return ;

    if(root->data == K){
        inorderPredecessor(root->left, pred);
        inorderSuccessor(root->right, succ);
        return;
    }

    if(root->data < K) {
        pred = root;
        findInorderSuccessorAndPredecessor(root->right, K, pred, succ);
    }
    else if(root->data > K) {
        succ = root;
        findInorderSuccessorAndPredecessor(root->left, K, pred, succ);
    }

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

    Node* pred = nullptr;
    Node* succ = nullptr;

    int K;
    cout<<"Enter the K value : ";
    cin>>K;

    findInorderSuccessorAndPredecessor(root, K, pred, succ);

    if(pred)
        cout<<"Inorder predecessor of "<<K<<" is : "<<pred->data<<endl;
    else
        cout<<"No inorder predecessor exists\n";

    if(succ)
        cout<<"Inorder successor of "<<K<<" is : "<<succ->data<<endl;
    else
        cout<<"No inorder successor exists\n";


    return 0;
}