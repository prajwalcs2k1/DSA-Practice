// Write a C++ program to find the size of the largest Binary Search Tree in the given binary tree

/*
            5
           / \
          2   4
         / \
        1   3    
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

struct Info{
    bool isBst;
    int size;
    int minVal;
    int maxVal;
};

Info largestBSTHlpr(Node* root, int &ans){
    if(!root){
        return {true, 0, INT_MAX, INT_MIN};
    }

    Info left = largestBSTHlpr(root->left, ans);
    Info right = largestBSTHlpr(root->right, ans);

    Info curr;

    if(left.isBst && right.isBst && (root->data < right.minVal) && (root->data > left.maxVal)){
        curr.isBst = true;
        curr.size = left.size + right.size + 1;
        curr.minVal = min(root->data, left.minVal);
        curr.maxVal = max(root->data, right.maxVal);

        ans = max(ans, (left.size + right.size + 1));
    }
    else{
        curr.isBst = false;
        curr.size = 0;
    }

    return curr;
}

int largestBST(Node* root){
    int ans = 1;
    largestBSTHlpr(root, ans);
    return ans;
}

int main(){

    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout<<"Largest BST in the given binary tree is : "<<largestBST(root)<<endl;

    return 0;
}