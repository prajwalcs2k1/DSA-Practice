// Write a C++ program to print the Maximum Width of the given Binary Tree

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

// Max width is from node 10 to 9, which is 4.

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

int maxWidth(Node* root){
    // Edge case: empty tree
    if(!root) return 0;

    int ans = 0; // stores maximum width

    // Queue stores: {node, index}
    // Index represents position of node in a "virtual complete binary tree"
    queue<pair<Node*, long long>> q;
    q.push({root, 0}); // root at index 0

    while(!q.empty()){
        int size = q.size(); // number of nodes at current level

        long long firstIndex, lastIndex;

        // Get the minimum index at this level to normalize indices
        // This prevents overflow when tree is deep
        long long minIndex = q.front().second;

        for(int i = 0; i < size; i++){
            Node* node = q.front().first;
            long long index = q.front().second;
            q.pop();

            // Normalize index to avoid very large values
            // After normalization, indices at this level start from 0
            index = index - minIndex;

            // Store first and last index of this level
            if(i == 0) firstIndex = index;
            if(i == size - 1) lastIndex = index;

            // Assign indices to children based on complete binary tree logic
            // Left child  -> 2*i + 1
            // Right child -> 2*i + 2
            if(node->left)
                q.push({node->left, 2 * index + 1});

            if(node->right)
                q.push({node->right, 2 * index + 2});
        }

        // Width of current level = distance between first and last node
        // +1 because both ends are inclusive
        ans = max(ans, (int)(lastIndex - firstIndex + 1));
    }

    return ans; // return maximum width found
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

    cout<<"Max width of the given binary tree is : "<<maxWidth(root)<<endl;

    return 0;
}