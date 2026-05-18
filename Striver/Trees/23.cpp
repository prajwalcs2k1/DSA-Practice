// Write a C++ program to solve given problem

/*
    You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

    Each minute, a node becomes infected if:
        The node is currently uninfected.
        The node is adjacent to an infected node.
    
    Return the number of minutes needed for the entire tree to be infected.
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

// Function to calculate HEIGHT of a subtree
//
// IMPORTANT:
// ---------------------------
// This function returns height in terms of NUMBER OF NODES
//
// Example:
//
//        1
//       /
//      2
//
// Height = 2
//
// because:
// path = 1 -> 2
// total nodes = 2
//
// ---------------------------------
// But infection/burning time is measured in:
// NUMBER OF EDGES / MINUTES
//
// So:
//
// height in edges = height in nodes - 1
//
// Example:
//
//        1
//       /
//      2
//
// height(nodes) = 2
// height(edges) = 1
//
// because:
// only one edge exists between 1 and 2
//
int findHeight(Node* root){

    // Empty tree has height 0
    if(!root) return 0;

    // Height of current node =
    //
    // 1 (current node itself)
    // +
    // maximum height among left and right subtree
    //
    // We use max() because height means:
    // longest downward path
    //
    return 1 + max(findHeight(root->left), findHeight(root->right));
}


// This function does TWO IMPORTANT JOBS simultaneously:
//
// ------------------------------------------------------
// JOB 1:
// Find the start node in the tree
//
// JOB 2:
// While recursion BACKTRACKS upward,
// calculate how much time infection needs
// to spread to all other parts of the tree
//
// ------------------------------------------------------
//
// RETURN VALUE MEANING:
//
// If start node is NOT found:
// return -1
//
// Else:
// return distance(current node -> start node)
//
// ------------------------------------------------------
//
// totalTime stores FINAL ANSWER
//
// It keeps track of:
// maximum time needed to infect farthest node
//
int amountOfTime(Node* root, int startNode, int &totalTime){

    // Base Case:
    // If subtree ends,
    // start node not found here
    if(!root) return -1;

    // If current node itself is start node
    if(root->data == startNode){

        // Infection spreads DOWNWARD inside this subtree
        //
        // Example:
        //
        //         5
        //        / \
        //       6   2
        //          / \
        //         7   4
        //
        // Deepest node from 5 is:
        // 7 or 4
        //
        // height(5) returns:
        // 3 nodes
        //
        // But infection time is measured in EDGES/MINUTES:
        //
        // 5 -> 2 -> 7
        //
        // which is:
        // 2 edges
        //
        // Therefore:
        //
        // infection time =
        // height - 1
        //
        totalTime = max(totalTime, findHeight(root) - 1);

        // distance(startNode,startNode)=0
        //
        // This value is returned upward
        // to parent nodes during backtracking
        //
        return 0;
    }

    // Search start node inside LEFT subtree
    int left = amountOfTime(root->left, startNode, totalTime);

    // If start node exists in LEFT subtree
    if(left != -1){

        // IMPORTANT:
        // -------------------------
        // left means:
        //
        // distance(left child -> start node)
        //
        // Example:
        //
        //          3
        //         /
        //        5
        //       /
        //      6
        //
        // Suppose start node = 6
        //
        // At node 5:
        // left = 0
        //
        // At node 3:
        // left = 1
        //
        // because:
        // distance(5 -> 6)=1 edge
        //
        // -----------------------------------
        //
        // Now infection spreads to RIGHT subtree
        // through current root
        //
        // Example:
        //
        //          3
        //        /   \
        //       5     1
        //      /
        //     6
        //
        // Infection path:
        //
        // 6 -> 5 -> 3 -> 1
        //
        // Time calculation:
        //
        // left
        // = distance(left child -> start node)
        //
        // +1
        // = edge from left child -> current root
        //
        // +findHeight(root->right)
        // = time needed to burn deepest node
        //   inside RIGHT subtree
        //
        // WHY ARE WE ADDING HEIGHT DIRECTLY?
        // -----------------------------------
        //
        // Suppose:
        //
        //       1
        //      /
        //     8
        //
        // height = 2
        //
        // But infection enters subtree from parent:
        //
        // currentRoot -> 1 -> 8
        //
        // which indeed takes 2 edges/minutes
        //
        // So adding full height works correctly
        //
        totalTime = max(totalTime, left + 1 + findHeight(root->right));

        // Return:
        // distance(current root -> start node)
        //
        // WHY +1 ?
        //
        // Because current root is exactly
        // one edge above left child
        //
        // Example:
        //
        // root
        //  |
        // left child
        //  |
        // target
        //
        // distance(root,target)
        // = distance(left child,target)+1
        //
        return left + 1;
    }

    // Search start node inside RIGHT subtree
    int right = amountOfTime(root->right, startNode, totalTime);

    // If start node exists in RIGHT subtree
    if(right != -1){

        // Same exact logic as LEFT case
        //
        // Infection spreads:
        //
        // target -> ... -> current root -> LEFT subtree
        //
        // right
        // = distance(right child -> target)
        //
        // +1
        // = edge from right child -> current root
        //
        // +height(left subtree)
        // = time needed to burn deepest node
        //   in LEFT subtree
        //
        totalTime = max(totalTime, right + 1 + findHeight(root->left));

        // Return:
        // distance(current root -> target)
        //
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
    cout<<"Enter the start node to infect : ";
    cin>>K;
    int totalTime = -1;
    amountOfTime(root, K, totalTime);
    if(totalTime < 0){
        cout<<"Start node does not exist in the tree!\n";
        return 0;
    }
    cout<<"Amount of time taken to infect entire binary tree from "<<K<<" node is : "<<totalTime<<endl;

    cout<<"\n";
    return 0;
}