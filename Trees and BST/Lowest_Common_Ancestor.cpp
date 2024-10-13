/*
To find the lowest common ancestor (LCA) of two nodes in a binary tree, we need to find the deepest node that is an ancestor of both nodes. The LCA of two nodes p and q is defined as the lowest node in the tree that has both p and q as descendants.

Approach:
We can solve this problem using a recursive approach:
Base Case: If the current node is nullptr or matches either p or q, return the current node.
Recursive Case:
  - Recursively search the left and right subtrees for p and q.
  - If both subtrees return a non-null node, then the current node is the LCA because p and q are found in different subtrees.
  - If only one subtree returns a non-null node, return that node as the ancestor.
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the lowest common ancestor (LCA)
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    // Recursively search for LCA in the left and right subtrees
    TreeNode* leftLCA = findLCA(root->left, p, q);
    TreeNode* rightLCA = findLCA(root->right, p, q);

    // If both left and right return non-null values, the current node is the LCA
    if (leftLCA != nullptr && rightLCA != nullptr) {
        return root;
    }

    // If only one subtree has found the LCA, return that subtree's result
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
    // Create a sample binary tree:
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Find LCA of nodes 5 and 1
    TreeNode* lca = findLCA(root, root->left, root->right); // LCA of 5 and 1 is 3
    cout << "LCA of 5 and 1 is: " << lca->data << endl;

    // Find LCA of nodes 5 and 4
    lca = findLCA(root, root->left, root->left->right->right); // LCA of 5 and 4 is 5
    cout << "LCA of 5 and 4 is: " << lca->data << endl;

    return 0;
}
