// Write a C++ program to implement a BST Iterator

/*
                8
               / \
              5   10   
             / \    \
            1   7    11   
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

/*
<-------------------------------BruteFoce Appraoch------------------------------->
    class BSTIterator{
            vector<int> inorderArr;
            int size;
            int index;

            void inorderTraversal(Node* root){
                if(!root) return;

                inorderTraversal(root->left);
                inorderArr.push_back(root->data);
                inorderTraversal(root->right);

                return;
            }

        public:
            BSTIterator(Node* root){
                inorderTraversal(root);
                size = inorderArr.size();
                index = 0;
            }

            int next(){
                if(index < size) return inorderArr[index++];
                return -1;
            }

            bool hasNext(){
                return (index < size);
            }
    };
<-------------------------------------------------------------------------------->
*/

class BSTIterator{
    stack<Node*> st;

    void pushToStack(Node* root){
        if(!root) return;

        st.push(root);
        pushToStack(root->left);

        return;
    }

public:
    BSTIterator(Node* root){
        pushToStack(root);
    }

    int next(){
        if(st.empty()) return -1;
        Node* currNode = st.top();
        st.pop();

        if(currNode->right) pushToStack(currNode->right);
        return currNode->data;
    }

    bool hasNext(){
        return !st.empty();
    }

};

int main(){

    Node* root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right = new Node(10);
    root->right->right = new Node(11);

    BSTIterator bstIterator(root);

    while(true){
        int choice;
        cout<<"1. next()  2. hasNext()\n";
        cout<<"Choose an option from above: ";
        cin>>choice;

        switch(choice){
            case 1:{
                    int next = bstIterator.next();
                    if(next == -1){
                        cout<<"Tree is traversed completely!\n";
                        return 0;
                    }

                    cout<<"Node: "<<next<<endl;
                    break;
            }

            case 2:{
                    bool hasNext = bstIterator.hasNext();

                    cout<<(hasNext ? "True" : "False")<<endl;
                    break;
            }

            default : {
                    if(choice > 2) return 0;
                    break;
            }
        }

        cout<<"\n";

    }

    return 0;
}