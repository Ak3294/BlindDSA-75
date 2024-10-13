#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
    Graph(int V);               // Constructor
    void addEdge(int u, int v); // Function to add an edge
    void findBridges();         // Function to find and print all bridges

private:
    int V;                                                                                   // Number of vertices
    vector<vector<int>> adj;                                                                 // Adjacency list
    void DFS(int u, int parent, vector<int> &disc, vector<int> &low, vector<bool> &visited); // DFS utility
};

// Constructor to initialize the graph
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

// Function to add an edge to the graph
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Since the graph is undirected
}

// Utility function to perform DFS and find bridges
void Graph::DFS(int u, int parent, vector<int> &disc, vector<int> &low, vector<bool> &visited)
{
    static int time = 0; // Initialize time

    visited[u] = true;         // Mark the current node as visited
    disc[u] = low[u] = ++time; // Initialize discovery time and low value

    // Explore all adjacent vertices
    for (int v : adj[u])
    {
        if (!visited[v])
        {                                  // If v is not visited
            DFS(v, u, disc, low, visited); // Recur for DFS
            low[u] = min(low[u], low[v]);  // Update low value

            // If the lowest vertex reachable from subtree under v is
            // below u in DFS tree, then u-v is a bridge
            if (low[v] > disc[u])
            {
                cout << "Bridge found: " << u << " - " << v << endl;
            }
        }
        // Update low value of u for parent function calls
        else if (v != parent)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

// Function to find and print all bridges
void Graph::findBridges()
{
    vector<int> disc(V, -1);        // Initialize discovery times
    vector<int> low(V, -1);         // Initialize low values
    vector<bool> visited(V, false); // Visited array

    // Call the recursive DFS helper function to find bridges
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            DFS(i, -1, disc, low, visited);
        }
    }
}

int main()
{
    // Create a graph given in the example
    Graph g(5); // Number of vertices

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Find and print bridges in the graph
    g.findBridges();

    return 0;
}
