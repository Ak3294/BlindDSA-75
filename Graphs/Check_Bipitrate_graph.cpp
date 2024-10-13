#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check if the graph is bipartite
bool isBipartite(int V, const vector<vector<int>> &adj)
{
    vector<int> color(V, -1); // Array to store colors of the vertices

    // Check for each component of the graph
    for (int start = 0; start < V; ++start)
    {
        if (color[start] == -1)
        { // Not visited yet
            queue<int> q;
            q.push(start);
            color[start] = 0; // Assign first color

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                // Explore all adjacent nodes
                for (int neighbor : adj[node])
                {
                    // If the neighbor has not been colored yet
                    if (color[neighbor] == -1)
                    {
                        // Assign alternate color to the neighbor
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    // If the neighbor has the same color, then the graph is not bipartite
                    else if (color[neighbor] == color[node])
                    {
                        return false; // Not bipartite
                    }
                }
            }
        }
    }
    return true; // The graph is bipartite
}

int main()
{
    // Number of vertices
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Adding edges to the graph (this creates a bipartite graph)
    adj[0] = {1, 3}; // Node 0 is connected to 1 and 3
    adj[1] = {0, 2}; // Node 1 is connected to 0 and 2
    adj[2] = {1, 4}; // Node 2 is connected to 1 and 4
    adj[3] = {0, 5}; // Node 3 is connected to 0 and 5
    adj[4] = {2};    // Node 4 is connected to 2
    adj[5] = {3};    // Node 5 is connected to 3

    // Check if the graph is bipartite
    if (isBipartite(V, adj))
    {
        cout << "The graph is bipartite." << endl;
    }
    else
    {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
