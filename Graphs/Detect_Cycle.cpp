#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and check for cycles
bool DFS(int node, int parent, vector<bool> &visited, const vector<vector<int>> &adj)
{
    visited[node] = true; // Mark the current node as visited

    // Explore all adjacent nodes
    for (int neighbor : adj[node])
    {
        // If the neighbor hasn't been visited yet, do a DFS on it
        if (!visited[neighbor])
        {
            if (DFS(neighbor, node, visited, adj))
            {
                return true; // Cycle found
            }
        }
        // If the neighbor is visited and not the parent of the current node, a cycle exists
        else if (neighbor != parent)
        {
            return true; // Cycle found
        }
    }
    return false; // No cycle found
}

// Function to detect a cycle in the undirected graph
bool hasCycle(int V, const vector<vector<int>> &adj)
{
    vector<bool> visited(V, false); // Array to track visited nodes

    // Perform DFS for each component of the graph
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            // If a cycle is found, return true
            if (DFS(i, -1, visited, adj))
            {
                return true;
            }
        }
    }
    return false; // No cycle found
}

int main()
{
    // Number of vertices
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Adding edges to the graph (this will create a cycle)
    adj[0] = {1, 2};     // Node 0 is connected to 1 and 2
    adj[1] = {0, 3};     // Node 1 is connected to 0 and 3
    adj[2] = {0, 4};     // Node 2 is connected to 0 and 4
    adj[3] = {1, 5};     // Node 3 is connected to 1 and 5
    adj[4] = {2};        // Node 4 is connected to 2
    adj[5] = {3};        // Node 5 is connected to 3
    adj[3].push_back(2); // Adding an edge to create a cycle

    // Check for cycles in the graph
    if (hasCycle(V, adj))
    {
        cout << "Cycle detected in the undirected graph." << endl;
    }
    else
    {
        cout << "No cycle detected in the undirected graph." << endl;
    }

    return 0;
}
