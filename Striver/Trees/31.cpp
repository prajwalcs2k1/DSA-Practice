// Write a C++ program to find a Ceil & Floor of a given element in the BST

/*
                        8
                      /   \
                     5     12
                   /  \   /  \
                  4    7 10  14
                      /     /   
                     6     13
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

void findCeilAndFloor(Node* root, int target, int &ceil, int &floor){
    if(!root) return ;

    if(root->data == target) {
        ceil = floor = root->data;
        return;
    }

    ceil = ((root->data > target) && (root->data < ceil)) ? root->data : ceil;
    floor = ((root->data < target) && (root->data > floor)) ? root->data : floor;

    if(target < root->data) findCeilAndFloor(root->left, target, ceil, floor);
    else findCeilAndFloor(root->right, target, ceil, floor);

    return;
}


int main(){

    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(13);

    int target;
    cout<<"Enter the target element : ";
    cin>>target;

    int ceil, floor;
    ceil = INT_MAX;
    floor = INT_MIN;
    findCeilAndFloor(root, target, ceil, floor);
    cout<<"The Ceil of "<<target<<" is "<<((ceil == INT_MAX) ? -1 : ceil)<<endl;
    cout<<"The Floor of "<<target<<" is "<<((floor == INT_MIN) ? -1 : floor)<<endl;

    return 0;
}