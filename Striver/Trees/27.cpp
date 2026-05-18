// Write a C++ program to serialize & de-serialize a binary tree

/*
    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
*/

/*
            1
           / \
          2   3
         /   / \
        6   4   5      
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

class Codec{
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string str = "";

        queue<Node*> q;
        q.push(root);

        str = str + to_string(root->data) + ',';

        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();

            if(!currNode->left){
                str = str + "N,";
            }else{
                q.push(currNode->left);
                str = str + to_string(currNode->left->data) + ',';
            }

            if(!currNode->right){
                str = str + "N,";
            }else{
                q.push(currNode->right);
                str = str + to_string(currNode->right->data) + ',';
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream s(data);
        string str;
        queue<Node*> q;
        getline(s, str, ',');
        Node* root = new Node(stoi(str));

        q.push(root);

        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "N"){
                currNode->left = nullptr;
            }else{
                currNode->left = new Node(stoi(str));
                q.push(currNode->left);
            }

            getline(s, str, ',');
            if(str == "N"){
                currNode->right = nullptr;
            }else{
                currNode->right = new Node(stoi(str));
                q.push(currNode->right);
            }
        }

        return root;        
    }

};

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    return;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(6);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout<<"Inorder traversal (before serialize & de-serialization): ";
    inorder(root);
    cout<<"\n";

    Codec obj;
    string serializedStr = obj.serialize(root);
    Node* deSerializedRoot = obj.deserialize(serializedStr);

    cout<<"Inorder traversal (after serialize & de-serialization): ";
    inorder(deSerializedRoot);
    cout<<"\n";

    return 0;
}