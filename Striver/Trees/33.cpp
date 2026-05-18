// Write a C++ program to delete a node from the BST using inorder predecessor

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

Node* inorderPredecessor(Node* root){
    if(!root) return nullptr;

    while(root->right){
        root = root->right;
    }

    return root;
}

Node* deleteFromBST(Node* root, int K){
    if(!root) return nullptr;

    if(K < root->data){
        root->left = deleteFromBST(root->left, K);
    }
    else if(K > root->data){
        root->right = deleteFromBST(root->right, K);
    }else{
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }else if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
            Node* predecessorNode = inorderPredecessor(root->left);
            root->data = predecessorNode->data;
            root->left = deleteFromBST(root->left, predecessorNode->data);
        }
    }
    return root;
}

void displayInorderSequence(Node* root){
    if(!root) return;

    displayInorderSequence(root->left);    
    cout<<root->data<<" ";
    displayInorderSequence(root->right);

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
    cout<<"Enter the new node to delete from BST : ";
    cin>>K;

    cout<<"BST before deleting "<<K<<" : ";
    displayInorderSequence(root);
    cout<<"\n";

    root = deleteFromBST(root, K);

    cout<<"BST after deleting "<<K<<" : ";
    displayInorderSequence(root);
    cout<<"\n";

    return 0;
}