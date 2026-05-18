// Write a C++ prgoram to check if the given binary tree is balanced or not

/*
    In a Balanced Binary Tree, for every node in the tree, the difference between the height of its left subtree and right subtree is at most 1
*/

/*
                1
               / \
              2   3
                 / \
                4   6
               /
              5  
*/

// Note:- Here i've taken nodes into consideratoin to calculate height of the tree

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

int heightOfTree(Node* root){
    if(!root) return 0;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight, rightHeight) + 1;
}

bool checkBalanced(Node* root){
    if(!root) return true;

    bool leftCheck = checkBalanced(root->left);
    bool rightCehck = checkBalanced(root->right);
    if(!leftCheck || !rightCehck) return false;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    if(abs(leftHeight - rightHeight) > 1) return false;

    return true;
}

int optimisedApproach(Node* root){
    if(!root) return 0;

    int leftSubtreeHeight = optimisedApproach(root->left);
    int rightSubtreeHeight = optimisedApproach(root->right);

    if((leftSubtreeHeight == -1) || (rightSubtreeHeight == -1)) return -1;

    if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1) return -1;

    return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
} 

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);

    // This approach recomputes height again & again, hence the T.C. of this approach is O(n^2) in the worst case (in the case of skewed tree)
    cout<<"Given binary tree is "<<(checkBalanced(root) ? "balanced." : "not balanced.")<<endl;

    // Optimised approach will return height if the subtree is balanced else returns -1, T.C. of this approach is O(n)
    cout<<"Given binary tree is "<<((optimisedApproach(root) == -1) ? "not balanced." : "balanced.")<<endl;

    return 0;
}