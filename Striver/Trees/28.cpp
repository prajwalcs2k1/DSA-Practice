// Write a C++ program to code Morris Traversal for the given binary tree

/*
            1
           / \
          2   3
         / \
        4   5
             \
              6 
*/

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

/*
    Mental model for Morris Traversal:

    Normally inorder traversal uses:
        recursion stack OR
        explicit stack
    Morris Traversal avoids extra space by:
        temporarily connecting predecessor → current node
        this temporary connection is called a thread


    Flow:
        Go left as much as possible
        Create thread to return back later
        After left subtree is done:
            remove thread
            process current node
            move right

    Think of it as:
        “If I don’t have a stack, I’ll leave a temporary return path.”
*/

void morrisTraversalForInorder(Node* root){

    // Start traversal from root
    Node* curr = root;

    // Continue until all nodes are processed
    while(curr){

        // CASE 1:
        // Current node has NO left subtree
        // So we can directly print it
        // and move to right subtree
        if(!curr->left){

            cout << curr->data << " ";

            // Move to right child
            curr = curr->right;
        }

        // CASE 2:
        // Current node HAS a left subtree
        else{

            // Find the inorder predecessor of curr
            // (rightmost node in left subtree)
            Node* next = curr->left;

            // Move as right as possible
            // Stop if:
            // 1. right becomes NULL
            // 2. thread already points back to curr
            while(next->right && (next->right != curr))
                next = next->right;

            // SUBCASE A:
            // Thread does NOT exist yet
            if(!next->right) {

                // Create temporary thread
                // so we can come back to curr later
                next->right = curr;

                // Move left to continue traversal
                curr = curr->left;
            }

            // SUBCASE B:
            // Thread already exists
            // Means left subtree is fully processed
            else{

                // Remove temporary thread
                // Restore original tree structure
                next->right = nullptr;

                // Now visit current node
                cout << curr->data << " ";

                // Move to right subtree
                curr = curr->right;
            }
        }
    }

    return;
}

void morrisTraversalForPreorder(Node* root){

    // Start traversal from root
    Node* curr = root;

    // Continue until all nodes are processed
    while(curr){

        // CASE 1:
        // No left subtree exists
        // In preorder, process node immediately
        // then move right
        if(!curr->left){

            cout << curr->data << " ";

            // Move to right child
            curr = curr->right;
        }

        // CASE 2:
        // Left subtree exists
        else{

            // Find inorder predecessor
            // (rightmost node in left subtree)
            Node* next = curr->left;

            // Move to the rightmost node
            // Stop if:
            // 1. right becomes NULL
            // 2. thread already points back to curr
            while(next->right && (next->right != curr))
                next = next->right;

            // SUBCASE A:
            // Thread not created yet
            if(!next->right){

                // PREORDER DIFFERENCE:
                // Process current node BEFORE going left
                cout << curr->data << " ";

                // Create temporary thread
                // so we can return to curr later
                next->right = curr;

                // Move to left subtree
                curr = curr->left;
            }

            // SUBCASE B:
            // Thread already exists
            // Means left subtree is fully processed
            else{

                // Remove temporary thread
                // Restore original tree structure
                next->right = nullptr;

                // Move to right subtree
                curr = curr->right;
            }
        }
    }

    return;
}


int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    cout<<"Inorder sequence (using Morris Traversal): ";
    morrisTraversalForInorder(root);
    cout<<"\n";

    cout<<"Preorder sequence (using Morris Traversal): ";
    morrisTraversalForPreorder(root);
    cout<<"\n";

    // Morris traversal is impossible without stack/recursion hence ignoring it here for postorder.
    // Hack :- get the preorder using morris algo and then reverse it to get the postorder :)

    return 0;
}