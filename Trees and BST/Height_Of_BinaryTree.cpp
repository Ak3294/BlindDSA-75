#include <iostream>
using namespace std;

// Define a structure for a tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a node
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the height of a binary tree
int findHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        // Base case: If the tree is empty, return -1 (or 0 depending on definition)
        return -1;
    }

    // Recursively find the height of the left and right subtrees
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // The height of the tree is the maximum of the two heights plus 1
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    // Create a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Height of the binary tree: " << findHeight(root) << endl; // Output: 2

    return 0;
}
