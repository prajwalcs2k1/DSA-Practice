// Write a C++ program to find the Preorder, InOrder & PostOrder Traversal for the below Binary-Tree

// Note: PreOrder, InOrder, PostOrder are also known as DFS traversals in Trees

/*
            1
           / \
          2   3
           \
            4
*/

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;   

        Node (int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }

};

void preOrder(Node* root){
    if(!root) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

    return;
}

void inOrder(Node * root){
    if(!root) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

    return;
}

void postOrder(Node * root){
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
    return;
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    cout<<"PreOrder Traversal for the given tree is : ";
    preOrder(root);
    cout<<endl;
    cout<<"InOrder Traversal for the given tree is : ";
    inOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal for the given tree is : ";
    postOrder(root);
    cout<<endl;

    return 0;
}