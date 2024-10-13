#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS starting from a given node
void BFS(int startNode, const vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true; // Mark the starting node as visited

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " "; // Process the current node

        // Explore all the adjacent nodes of the current node
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);         // Enqueue the neighbor
                visited[neighbor] = true; // Mark it as visited
            }
        }
    }
}

int main()
{
    // Number of vertices
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[0] = {1, 2}; // Node 0 is connected to 1 and 2
    adj[1] = {0, 3}; // Node 1 is connected to 0 and 3
    adj[2] = {0, 4}; // Node 2 is connected to 0 and 4
    adj[3] = {1, 5}; // Node 3 is connected to 1 and 5
    adj[4] = {2};    // Node 4 is connected to 2
    adj[5] = {3};    // Node 5 is connected to 3

    // Array to keep track of visited nodes
    vector<bool> visited(V, false);

    // Perform BFS starting from node 0
    cout << "BFS traversal starting from node 0:" << endl;
    BFS(0, adj, visited);

    return 0;
}
