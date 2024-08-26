#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to perform Prim's algorithm
int prim(vector<vector<int> >& graph) {
    int V = graph.size();
    
    // Create a priority queue to store edges with the minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    // Create a vector to store the visited status of each vertex
    vector<bool> visited(V, false);
    
    // Start the algorithm from the first vertex
    pq.push(make_pair(0, 0));
    
    int minCost = 0;
    
    while (!pq.empty()) {
        // Get the edge with the minimum weight from the priority queue
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        
        // Skip if the vertex is already visited
        if (visited[u])
            continue;
        
        // Mark the vertex as visited
        visited[u] = true;
        
        // Add the weight of the edge to the minimum cost
        minCost += weight;
        
        // Traverse all the neighbors of the current vertex
        for (int v = 0; v < V; v++) {
            // Push the neighbor into the priority queue if it is not visited and there is an edge
            if (!visited[v] && graph[u][v] != 0)
                pq.push(make_pair(graph[u][v], v));
        }
    }
    
    return minCost;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    // Create a graph represented as an adjacency matrix
    vector<vector<int> > graph(V, vector<int>(V));
    
    // Take input for the graph
    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    
    int minCost = prim(graph);
    
    cout << "Minimum cost required to connect the cities: " << minCost << endl;
    
    return 0;
}