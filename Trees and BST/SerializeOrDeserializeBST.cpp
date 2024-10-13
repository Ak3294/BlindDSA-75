/*
To serialize a binary tree means to convert it into a string representation, and to deserialize means to reconstruct the binary tree from the string representation. This can be useful for storing or transmitting the tree structure.

Serialization and Deserialization of a Binary Tree:
Serialization: Convert the tree into a string format (usually in preorder traversal) where we include placeholders for null nodes.
Deserialization: Convert the string back into a binary tree by reconstructing the nodes using the same traversal technique.

APPROACH:
Serialization:
 - Use preorder traversal (root, left, right).
 - For each node, append its value to the string. If a node is nullptr, append a placeholder (e.g., #).
 - The result is a string of node values separated by commas.
Deserialization:
 - Use the same preorder traversal approach to rebuild the tree.
 - Read the serialized string and recursively reconstruct the tree.
 - If a placeholder (e.g., #) is encountered, it represents a nullptr.

*/

#include <iostream>
#include <sstream>
#include <string>
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

// Helper function to serialize the tree
void serializeHelper(TreeNode *root, ostringstream &out)
{
    if (root == nullptr)
    {
        out << "# "; // Use '#' to represent null nodes
        return;
    }
    // Preorder traversal: root -> left -> right
    out << root->data << " ";
    serializeHelper(root->left, out);
    serializeHelper(root->right, out);
}

// Function to serialize the tree
string serialize(TreeNode *root)
{
    ostringstream out;
    serializeHelper(root, out);
    return out.str();
}

// Helper function to deserialize the tree
TreeNode *deserializeHelper(istringstream &in)
{
    string val;
    in >> val;

    if (val == "#")
    {
        return nullptr; // Null node found
    }

    // Create a new node with the current value
    TreeNode *node = new TreeNode(stoi(val));

    // Recursively construct the left and right subtrees
    node->left = deserializeHelper(in);
    node->right = deserializeHelper(in);

    return node;
}

// Function to deserialize the tree from a string
TreeNode *deserialize(const string &data)
{
    istringstream in(data);
    return deserializeHelper(in);
}

int main()
{
    // Create a sample binary tree:
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serializedTree = serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserialize the tree
    TreeNode *deserializedRoot = deserialize(serializedTree);
    cout << "Deserialized Tree Root Value: " << deserializedRoot->data << endl;

    return 0;
}
