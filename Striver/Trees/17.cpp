// Write a C++ program to check if the given binary tree is Symmetrical

/*
                1
               / \
              2   2
             /     \
            3       3
           / \     / \  
          4   5   5   4
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

bool isSymmetrical(Node* p, Node* q){
    if(!p && !q) return true;
    if(!p || !q) return false;

    if(p->data != q->data) return false;

    return isSymmetrical(p->left, q->right) && isSymmetrical(p->right, q->left);
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->right->right->left = new Node(5); 
    root->right->right->right = new Node(4); 

    cout<<"Given binary tree is "<<(isSymmetrical(root, root) ? "Symmetrical." : "Not symmetrical.")<<endl;

    return 0;
}