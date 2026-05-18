// Write a C++ program to print the Zig Zag Level Order Traversal of the given binary tree

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

void zigZagTraversal(Node* root){
    if(!root) return;
    cout<<"The Zig Zag Level Order Traversal of the given binary tree is : ";
    queue<Node*> q;
    bool leftToRight = true;
    q.push(root);

    while(!q.empty()){
        int qSize = q.size();
        vector<int> helperVec(qSize);
        for(int i=0; i<qSize; i++){
            Node* currNode = q.front();
            q.pop();
            if(leftToRight){
                helperVec[i] = currNode->data;
            }else{
                helperVec[qSize - 1 - i] = currNode->data;
            }
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        for(int ele : helperVec) cout<<ele<<" ";
        leftToRight = !leftToRight;
    }

    cout<<"\n";
    return;
}

int main(){

    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    zigZagTraversal(root); 

    return 0;
}