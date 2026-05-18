// Write a C++ program to find if given 2 trees are identical or not

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

bool isIdentical(Node* p, Node* q){
    if(!p && !q) return true;
    if(!p || !q) return false;

    if(p->data != q->data) return false;

    return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}

int main(){

    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(-7);

    Node *root2 = new Node(-10);
    root2->left = new Node(9);
    root2->right = new Node(20);
    root2->right->left = new Node(15);
    root2->right->right = new Node(-7);

    cout<<"Given 2 trees are "<<(isIdentical(root, root2) ? "identical." : "not identical.")<<endl;

    return 0;
}