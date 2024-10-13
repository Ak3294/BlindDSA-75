/*
To validate if a binary tree is a valid binary search tree (BST), each node must satisfy the BST property:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
To check if a tree is a valid BST, we need to ensure that for every node, all values in its left subtree are less than the node's value and all values in its right subtree are greater than the node's value. We can do this by passing down the allowed value ranges for each node as we recursively traverse the tree.

Approach:
We use a recursive function that:

 - Limits the range of values a node can take based on its parent.
 - Initially, the root node is allowed to take any value (between negative infinity and positive infinity).
 - For each left child, we update the upper bound (to the current node's value).
 - For each right child, we update the lower bound (to the current node's value).
*/

#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to validate the BST
bool isValidBST(TreeNode *root, long long minVal, long long maxVal)
{
    if (root == nullptr)
    {
        return true; // An empty tree is a valid BST
    }

    // If the current node's value is out of the allowed range, it's not a valid BST
    if (root->data <= minVal || root->data >= maxVal)
    {
        return false;
    }

    // Recursively check the left and right subtrees with updated ranges
    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
}

// Function to check if a binary tree is a valid BST
bool isValidBST(TreeNode *root)
{
    // Use long long limits to avoid overflow
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    // Create a sample binary tree:
    //        5
    //       / \
    //      3   7
    //     / \   \
    //    2   4   8
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    if (isValidBST(root))
    {
        cout << "The tree is a valid Binary Search Tree." << endl;
    }
    else
    {
        cout << "The tree is NOT a valid Binary Search Tree." << endl;
    }

    return 0;
}
