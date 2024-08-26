#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the parent of a vertex (used for cycle detection in Kruskal's algorithm)
int findParent(int v, vector<int>& parent) {
    if (parent[v] == v)
        return v;
    
    return findParent(parent[v], parent);
}

// Function to perform Kruskal's algorithm
int kruskal(vector<vector<int> >& graph) {
    int V = graph.size();
    
    // Create a vector to store the parent of each vertex (used for cycle detection)
    vector<int> parent(V);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    
    int minCost = 0;
    int edgeCount = 0;
    
    // Create a vector of edges
    vector<pair<int, pair<int, int> > > edges;
    
    // Traverse the upper triangular matrix of the graph to get all the edges
    for (int u = 0; u < V; u++) {
        for (int v = u + 1; v < V; v++) {
            int weight = graph[u][v];
            
            // Check if there is an edge between u and v
            if (weight != 0) {
                edges.push_back(make_pair(weight, make_pair(u, v)));
            }
        }
    }
    
    // Sort the edges in ascending order based on their weights
    sort(edges.begin(), edges.end());
    
    // Perform Kruskal's algorithm
    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;
        
        // Check if including this edge forms a cycle in the current minimum spanning tree
        int parentU = findParent(u, parent);
        int parentV = findParent(v, parent);
        
        if (parentU != parentV) {
            // Include this edge in the minimum spanning tree
            minCost += weight;
            edgeCount++;
            
            // Merge the two disjoint sets by updating the parent
            parent[parentU] = parentV;
            
            // If we have included V-1 edges, stop the algorithm
            if (edgeCount == V - 1)
                break;
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
    
    int minCost = kruskal(graph);
    
    cout << "Minimum spanning weight: " << minCost << endl;
    
    return 0;
}


// Kruskal algorithm using disjoint sets

// #include<algorithm>
// bool cmp(vector<int> &a, vector<int> &b)
// {
//   return a[2] < b[2];
// }

// void makeSet(vector<int> &parent, vector<int> &rank, int n)
// {
//   for(int i=0; i<n; i++)
//   {
//     parent[i] = i;
//     rank[i] = 0;
//   }
// }

// int findParent(vector<int> &parent, int node)
// {
//   if(parent[node] == node)
//   {
//     return node;
//   }
//   return parent[node] = findParent(parent, parent[node]);
// }

// void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
// {
//   u = findParent(parent, u);
//   v = findParent(parent, v);

//   if(rank[u] > rank[v])
//     parent[v] = u;
//   else if(rank[v] > rank[u])
//     parent[u] = v;
//   else{
//     parent[u] = v;
//     rank[u]++;
//   }
// }

// int minimumSpanningTree(vector<vector<int>>& edges, int n)
// {
//   sort(edges.begin(), edges.end(), cmp);
//   vector<int> parent(n);
//   vector<int> rank(n);
//   makeSet(parent, rank, n);

//   int minwt = 0;

//   for(int i=0; i<edges.size(); i++)
//   {
//     int u = findParent(parent, edges[i][0]);
//     int v = findParent(parent, edges[i][1]);
//     int wt = edges[i][2];

//     if(u != v)
//     {
//       minwt += wt;
//       unionSet(u, v, parent, rank);
//     }
//   }

//   return minwt;
// }