// Write a C++ program to print the level order traversal of the given tree

// Note:- Level Order Traversal is also known as BFS traversal in trees

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

void levelOrderTraversal(Node* root){

    if(!root) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *currNode = q.front();
        q.pop();
        
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);

        cout<<currNode->data<<" ";
    }

    return;
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    cout<<"The level order traversal of the given tree is : ";
    levelOrderTraversal(root);
    cout<<"\n";
    return 0;
}