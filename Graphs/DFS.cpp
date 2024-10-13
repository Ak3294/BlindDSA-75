#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS starting from a given node
void DFSRecursive(int node, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[node] = true;
    cout << node << " "; // Print the current node

    // Recursively visit all the adjacent vertices that have not been visited yet
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFSRecursive(neighbor, visited, adj);
        }
    }
}

int main() {
    // Number of vertices
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[0] = {1, 2};    // Node 0 is connected to 1 and 2
    adj[1] = {0, 3};    // Node 1 is connected to 0 and 3
    adj[2] = {0, 4};    // Node 2 is connected to 0 and 4
    adj[3] = {1, 5};    // Node 3 is connected to 1 and 5
    adj[4] = {2};       // Node 4 is connected to 2
    adj[5] = {3};       // Node 5 is connected to 3

    // Array to keep track of visited nodes
    vector<bool> visited(V, false);

    // Perform DFS starting from node 0
    cout << "DFS traversal starting from node 0:" << endl;
    DFSRecursive(0, visited, adj);

    return 0;
}
