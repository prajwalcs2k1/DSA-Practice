// Write a C++ program to find the LCA of 2 nodes in the given BST

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

bool checkForNodes(Node* root, int A){
    if(!root) return false;
    if(root->data == A) return true;

    if(root->data > A) return checkForNodes(root->left, A);
    return checkForNodes(root->right, A);
}

int LCA(Node* root, int M, int N){
    if(!root) return -1;

    if((root->data > M) && (root->data > N)) return LCA(root->left, M, N);

    if((root->data < M) && (root->data < N)) return LCA(root->right, M, N);

    return root->data;
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

    int M, N;
    cout<<"Enter the search nodes : ";
    cin>>M>>N;

    int A, B;
    A = (M < N) ? M : N;
    B = (N > M) ? N : M;

    if(!(checkForNodes(root, M) && checkForNodes(root, N))){
        cout<<"Both nodes are not present in the BST!\n";
        return 0;
    }

    cout<<"LCA of "<<M<<" & "<<N<<" is : "<<LCA(root, A, B)<<endl;

    return 0;

}