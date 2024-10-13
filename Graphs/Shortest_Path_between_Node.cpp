#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Function to find the shortest path between two nodes in an unweighted graph
vector<int> shortestPath(int startNode, int endNode, const vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V, false); // Array to track visited nodes
    vector<int> parent(V, -1);      // Array to track the parent of each node in the path

    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // If the destination node is found, stop the search
        if (node == endNode)
        {
            break;
        }

        // Explore all adjacent nodes
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = node; // Track the parent node to reconstruct the path later
                q.push(neighbor);
            }
        }
    }

    // Reconstruct the shortest path from startNode to endNode
    vector<int> path;
    if (!visited[endNode])
    {
        return path; // No path found
    }

    // Backtrack from the endNode to startNode using the parent array
    for (int v = endNode; v != -1; v = parent[v])
    {
        path.push_back(v);
    }

    // Reverse the path since we backtracked from endNode to startNode
    reverse(path.begin(), path.end());

    return path;
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

    // Define start and end nodes
    int startNode = 0;
    int endNode = 5;

    // Find the shortest path from startNode to endNode
    vector<int> path = shortestPath(startNode, endNode, adj, V);

    // Print the result
    if (path.empty())
    {
        cout << "No path exists between node " << startNode << " and node " << endNode << "." << endl;
    }
    else
    {
        cout << "Shortest path between node " << startNode << " and node " << endNode << ": ";
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
