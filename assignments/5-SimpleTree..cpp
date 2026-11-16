/*
    Lab Assignment - Simple Binary Tree

    This program demonstrates a basic binary tree structure and uses
    preorder traversal to print the node data. It is implemented in
    C++ instead of Java.
    *** IDE -> Visual Studio 2026 ***

    Key features:
    - Defines a Node class containing a name and two child pointers
    - Manually constructs a small binary tree
    - Uses recursive preorder traversal
    - Visits each node in the order: root, left subtree, right subtree
    - Displays every element stored in the tree

    Created by:
    - Adam Huynh
    - CS 236 Fall Semester, LAVC
    - 10/29/2026

    GitHub repository:
    - https://github.com/daTaHere/lavc-cs236--adv-data-structs
*/

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* left; 
    Node* right;

    Node(const string& nodeName) : name(nodeName), left(nullptr), right(nullptr) {}
};

// Prototypes
void printTree(Node* root);

int main() {
    // Create nodes
    Node alice("Alice");
    Node bob("Bob");
    Node carol("Carol");
    Node dan("Dan");
    Node eve("Eve");

    // Build the tree
    alice.left = &bob;
    alice.right = &carol;
    bob.left = &dan;
    bob.right = &eve;

    cout << "Tree (Preorder):" << endl;

    // Execute function
    printTree(&alice);

    return 0;
}

void printTree(Node* root) {
    // Base condition
    if (root == nullptr)
        return;

    // Print current node data
    cout << root->name << endl;

    // Recursive calls
    printTree(root->left);
    printTree(root->right);
}
