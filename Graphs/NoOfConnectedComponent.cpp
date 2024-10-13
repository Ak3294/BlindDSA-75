#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and mark all reachable vertices
void DFS(int node, vector<bool> &visited, const vector<vector<int>> &adj)
{
    visited[node] = true; // Mark the current node as visited

    // Explore all adjacent nodes
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {                                // If the neighbor hasn't been visited
            DFS(neighbor, visited, adj); // Recursively call DFS on it
        }
    }
}

// Function to count the number of connected components
int countConnectedComponents(int V, const vector<vector<int>> &adj)
{
    vector<bool> visited(V, false); // Array to track visited nodes
    int count = 0;                  // Count of connected components

    // Check for each vertex
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {                         // If the vertex hasn't been visited
            DFS(i, visited, adj); // Perform DFS
            count++;              // Increment the count for a new connected component
        }
    }
    return count; // Return the total number of connected components
}

int main()
{
    // Number of vertices
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[0] = {1};    // Node 0 is connected to 1
    adj[1] = {0, 2}; // Node 1 is connected to 0 and 2
    adj[2] = {1};    // Node 2 is connected to 1
    adj[3] = {4};    // Node 3 is connected to 4
    adj[4] = {3, 5}; // Node 4 is connected to 3 and 5
    adj[5] = {4};    // Node 5 is connected to 4

    // Count connected components in the graph
    int components = countConnectedComponents(V, adj);
    cout << "Number of connected components: " << components << endl;

    return 0;
}
