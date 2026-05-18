// Write a C++ program to print the Inorder, Preorder, Postorder traversals using iterative approach in One traversal

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

void allInOne(Node* root, vector<int> &inorder, vector<int> &preorder, vector<int> &postorder){

    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        auto [node, counter] = st.top();
        st.pop();

        if(counter == 3){
            postorder.push_back(node->data);
        }else if(counter == 2){
            inorder.push_back(node->data);
            st.push({node, counter+1});
            if(node->right) st.push({node->right, 1});
        }else{
            preorder.push_back(node->data);
            st.push({node, counter+1});
            if(node->left) st.push({node->left, 1});
        }
    }

    return;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    vector<int> inorder, preorder, postorder;
    allInOne(root, inorder, preorder, postorder);

    cout<<"Inorder: ";
    for(int ele : inorder) cout<<ele<<" ";
    cout<<"\n";

    cout<<"Preorder: ";
    for(int ele : preorder) cout<<ele<<" ";
    cout<<"\n";

    cout<<"Postorder: ";
    for(int ele : postorder) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}