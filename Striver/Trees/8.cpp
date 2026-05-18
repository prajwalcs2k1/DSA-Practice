// Write a C++ program to print the diameter of the given binary tree

/*
    -- The diameter of a binary tree is the length of the longest path between any two nodes in the tree.
    -- The path may or may not pass through the root.
    -- The length can be measured in:
        - number of edges (most common in interviews)
        - number of nodes (sometimes used — clarify if needed)
*/

// Note:- Below is implemented taking edges into consideration for height.

/*
                1
               / \
              2   3
                 / \
                4   6
               /
              5  
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

int heightOfTree(Node* root){   
    if(!root) return -1; 

    int leftMaxHeight = heightOfTree(root->left);
    int rightMaxHeight = heightOfTree(root->right);

    return max(leftMaxHeight, rightMaxHeight) + 1;
}

void bruteForce(Node* root, int* mxAns){
    if(!root) return;

    bruteForce(root->left, mxAns);
    bruteForce(root->right, mxAns);

    int leftSubtreeHeight = heightOfTree(root->left);
    int rightSubtreeHeight = heightOfTree(root->right);

    *mxAns = max(*mxAns, (leftSubtreeHeight + rightSubtreeHeight + 2));

    return;
}

int optimisedApproach(Node* root, int *mxAns){
    if(!root) return -1;
    
    int leftSubtreeHeight = optimisedApproach(root->left, mxAns);
    int rightSubtreeHeight = optimisedApproach(root->right, mxAns);

    *mxAns = max(*mxAns, (leftSubtreeHeight + rightSubtreeHeight + 2));

    return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

int main(){

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    int mxAns = INT_MIN;

    // T.C. of the bruteForce approach is O(n^2)
    bruteForce(root, &mxAns);
    cout<<"Diameter of the Binary Tree is (using Bruteforce) : "<<mxAns<<endl;

    // T.C. of the optimsied appraoch is O(n)
    mxAns = INT_MIN;
    optimisedApproach(root, &mxAns);
    cout<<"Diameter of the Binary Tree is (using Optimised approach) : "<<mxAns<<endl;

    return 0;
}