// Write a C++ program to traverse and print the Inorder, Preorder & Postorder traversal of a binary tree using iterative approach 

/*
            1
           / \
          2   3
           \
            4
*/


#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

void preOrder(Node* root){

    stack<Node*> st;
    st.push(root);
    cout<<"Preorder traversal (iterative): ";
    while(!st.empty()){
        Node* currNode = st.top();
        st.pop();

        cout<<currNode->data<<" ";

        if(currNode->right) st.push(currNode->right);
        if(currNode->left) st.push(currNode->left);
    }

    cout<<"\n";

    return;
}

void inOrder(Node* root){

    stack<Node*> st;
    Node* curr = root;
    cout<<"Inorder traversal (iterative): ";

    while(true){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }else{
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }

    }
    cout<<"\n";
    return;
}

void postOrder(Node* root){

    stack<Node*> st, st2;
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        st2.push(curr);

        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }

    cout<<"Postorder traversal (iterative): ";
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
    cout<<"\n";
    return;
}

void postOrderInOneStack(Node* root){
    stack<Node*> st;
    Node* curr = root;
    cout<<"Postorder using 1 stack (iterative): ";

    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }else{
            Node* temp = st.top()->right;
            if(!temp){
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && (temp == st.top()->right)){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }else curr = temp;

        }
    }
    cout<<"\n";
    return;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    preOrder(root);
    inOrder(root);
    postOrder(root);
    postOrderInOneStack(root);

    return 0;
}