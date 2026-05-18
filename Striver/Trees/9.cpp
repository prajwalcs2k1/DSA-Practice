// Write a C++ program to print the Maximum Path Sum for the given binary tree

/*
            -10
            /  \
           9    20
               /  \
              15   7
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

int maxPathSum(Node* root, int *mxAns){
    if(!root) return 0;
    
    int leftSum = maxPathSum(root->left, mxAns);
    int rightSum = maxPathSum(root->right, mxAns);

    *mxAns = max(*mxAns, leftSum + rightSum + root->data);

    if((leftSum + rightSum + root->data) < 0) return 0;     // to handle negative sum

    return root->data + max(leftSum, rightSum);
}

int main(){

    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int mxAns = INT_MIN;

    // This code takes O(n) T.C.
    maxPathSum(root, &mxAns);
    cout<<"Maximum path sum of the given binary tree is : "<<mxAns<<endl;

    return 0;
}