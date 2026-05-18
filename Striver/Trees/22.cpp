// Write a C++ program to Print all the Nodes at a distance of K in Binary Tree

/*
    Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

    You can return the answer in any order.
*/

/*
                        3
                      /   \
                     5     1
                   / |     | \
                  6  2     0  8
                    / \
                   7   4
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

// Helper function to find all nodes that are K distance BELOW the current node
void findBottomNodes(Node* root, int K, vector<int> &res){

    // Base Case:
    // If node becomes NULL OR K becomes negative,
    // stop recursion
    if(!root || (K < 0)) return;

    // If K becomes 0,
    // current node is exactly K distance away
    if(K == 0) {

        // Store answer
        res.push_back(root->data);

        // No need to go deeper
        return;
    }

    // Move LEFT subtree
    // Distance remaining decreases by 1
    findBottomNodes(root->left, K-1, res);

    // Move RIGHT subtree
    // Distance remaining decreases by 1
    findBottomNodes(root->right, K-1, res);

    return;
}

int KDistNodes(Node* root, Node* target, int K, vector<int> & res){

    // Base Case:
    // If tree/subtree ends,
    // target not found here
    if(!root) return -1;

    // If current node itself is target
    if(root == target){

        // Find all nodes BELOW target at distance K
        findBottomNodes(root, K, res);

        // Return 0 because:
        // distance(target, target) = 0
        return 0;
    }

    // Search target in LEFT subtree
    int left = KDistNodes(root->left, target, K, res);

    // If target exists in LEFT subtree
    if(left != -1){

        // left represents:
        // distance(left child -> target)

        // So:
        // (left + 1) represents:
        // distance(current root -> target)

        // If current node itself is exactly K distance away
        if((left + 1) == K)

            // Add current node
            res.push_back(root->data);

        else

            // Otherwise search opposite subtree (RIGHT subtree)

            // Why K-left-2 ?
            //
            // left = distance(left child -> target)
            //
            // +1 edge:
            // left child -> current root
            //
            // +1 edge:
            // current root -> right subtree
            //
            // Total already consumed:
            // left + 2
            //
            // Remaining distance:
            // K - left - 2

            findBottomNodes(root->right, K-left-2, res);

        // Return distance(current root -> target)
        // to parent node
        return left + 1;
    }

    // Search target in RIGHT subtree
    int right = KDistNodes(root->right, target, K, res);

    // If target exists in RIGHT subtree
    if(right != -1){

        // right represents:
        // distance(right child -> target)

        // So:
        // (right + 1) represents:
        // distance(current root -> target)

        // If current node itself is exactly K distance away
        if((right + 1) == K)

            // Add current node
            res.push_back(root->data);

        else

            // Otherwise search opposite subtree (LEFT subtree)

            // Why K-right-2 ?
            //
            // right = distance(right child -> target)
            //
            // +1 edge:
            // right child -> current root
            //
            // +1 edge:
            // current root -> left subtree
            //
            // Total already consumed:
            // right + 2
            //
            // Remaining distance:
            // K - right - 2

            findBottomNodes(root->left, K-right-2, res);

        // Return distance(current root -> target)
        // to parent node
        return right + 1;
    }

    // Target not found in both LEFT and RIGHT subtree
    return -1;
}

int main(){

    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node * target = root->left;
    int K;
    cout<<"Enter the distance : ";
    cin>>K;
    vector<int> res;
    KDistNodes(root, target, K, res);

    for(int ele : res)  cout<<ele<<" ";
    cout<<"\n";
    return 0;
}