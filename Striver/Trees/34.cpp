// Write a C++ program to delete a node from the BST using inorder successor

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

Node* findInorderSuccessor(Node* root){
    root = root->right;

    while(root->left){
        root = root->left;
    }

    return root;
}

Node* deleteFromBST(Node* root, int K){

    if(!root) return NULL;

    // Search in left subtree
    if(K < root->data){
        root->left = deleteFromBST(root->left, K);
    }

    // Search in right subtree
    else if(K > root->data){
        root->right = deleteFromBST(root->right, K);
    }

    // Node found
    else{

        // Case 1: Leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        // Case 2: Only left child
        else if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Only right child
        else if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 4: Both children exist
        else{
            Node* successor = findInorderSuccessor(root);

            root->data = successor->data;

            root->right = deleteFromBST(root->right, successor->data);
        }
    }

    return root;
}

void inorderTraversal(Node* root){

    if(!root) return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
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
    inorderTraversal(root);
    cout<<"\n";

    root = deleteFromBST(root, K);

    cout<<"BST after deleting "<<K<<" : ";
    inorderTraversal(root);
    cout<<"\n";

    return 0;
}