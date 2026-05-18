// Write a C++ program to print the LCA (Lowest Common Ancestor) of given 2 nodes in a binary tree

/*
                1
               / \
              2   3
             / \
            4   5
               / \
              6   7
             /   / \
            10  8   9
*/

// Note:- It should be guaranteed with the interviewer that both the nodes are present in the tree, else write a helper function to check the presence of both nodes in tree and throw error in the very beginning

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

bool rootToNodePath(Node* root, int node, vector<int> &pathVec){
    if(!root) return false;

    pathVec.push_back(root->data);
    if(node == root->data) return true;

    if(rootToNodePath(root->left, node, pathVec) || rootToNodePath(root->right, node, pathVec)) return true;

    pathVec.pop_back();

    return false;
}

int findLCABruteforce(Node* root, int A, int B){
    vector<int> pathA, pathB;
    rootToNodePath(root, A, pathA);
    rootToNodePath(root, B, pathB);

    int lcaIndex = -1;
    int i=0, j=0, m=pathA.size(), n=pathB.size();

    while((i<m) && (j<n)){
        if(pathA[i] != pathB[j]) break;
        lcaIndex = i;
        i++;
        j++;
    }

    return lcaIndex == -1 ? -1 : pathA[lcaIndex];
}

int findLCAOptimised(Node* root, int A, int B){
    if(!root) return -1;
    if((root->data == A) || (root->data == B)) return root->data;

    int left = findLCAOptimised(root->left, A, B);
    int right = findLCAOptimised(root->right, A, B);

    if((left == -1) && (right == -1)) return -1;
    else if(left == -1) return right;
    else if(right == -1) return left;

    return root->data;
}

bool findNode(Node* root, int data){
    if(!root) return false;
    if(root->data == data) return true;
    return findNode(root->left, data) || findNode(root->right, data);
}

int main(){

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->left->right->left = new Node(6); 
    root->left->right->left->left = new Node(10); 
    root->left->right->right = new Node(7); 
    root->left->right->right->left = new Node(8); 
    root->left->right->right->right = new Node(9);

    int A, B;
    cout<<"Enter the 2 nodes : ";
    cin>>A>>B;

    if(!(findNode(root, A) && findNode(root, B))){
        cout<<"Both nodes does not exist in tree.\n";
        return 0;
    }

    // T.C. of the below approach is O(N) & S.C. is O(N)
    cout<<"The LCA of the given 2 nodes is (bruteforce): "<<findLCABruteforce(root, A, B)<<endl;

    // T.C. of the optimised approach is O(N) & S.C. is O(1)
    cout<<"The LCA of the given 2 nodes is (optimised): "<<findLCAOptimised(root, A, B)<<endl;    

    return 0;
}