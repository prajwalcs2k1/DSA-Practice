// Write a C++ program to print the Left & Right View of the given binary tree

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

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

/*
-----------------------------------Cleaner Code-----------------------------------
    void getLeftAndRightView(Node* root, vector<vector<int>> &res){
        if(!root) return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                Node* curr = q.front();
                q.pop();

                if(i == 0) res[0].push_back(curr->data);           // left view
                if(i == size - 1) res[1].push_back(curr->data);    // right view

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
----------------------------------------------------------------------------------
*/

void getLeftAndRightView(Node* root, vector<vector<int>> &res){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    Node* curr, *prev;
    curr = prev = nullptr;

    while(!q.empty()){
        prev = curr;
        curr = q.front();
        q.pop();

        if(!prev && !curr) break;       // indicates the traversal is complete
        
        if(prev == nullptr) res[0].push_back(curr->data);       // add the first node->data of the level (left view)
        else if(prev && (curr == nullptr)) res[1].push_back(prev->data);        // add the last node->data of the level (right view)


        if(!curr) { 
            q.push(nullptr);        // indicates the end of a level hence pushing nullptr to mark the end of next level
            continue;
        }        

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    return;
}

void printLeftAndRightView(vector<vector<int>> res){
    cout<<"Left View : ";
    for(auto ele : res[0]) cout<<ele<<" ";
    cout<<"\n";
    cout<<"Right View : ";
    for(auto ele : res[1]) cout<<ele<<" ";
    cout<<"\n";
    return;
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

    vector<vector<int>> ans(2);
    getLeftAndRightView(root, ans);

    printLeftAndRightView(ans);

    return 0;
}