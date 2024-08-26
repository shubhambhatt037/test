#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
// void prepareAdjList(unordered_map<int, list<int> > &adjList, vector<vector<int> > edges)
// {
//     for(int i=0 ; i<edges.size(); i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
// }

// void dfs(unordered_map<int, list<int> > adjList, vector<int> &component, vector<bool> &visited, int node)
// {
//     component.push_back(node);
//     visited[node] = 1;

//     for(auto i: adjList[node])
//     {
//         if(!visited[i])
//             dfs(adjList, component, visited, i);
//     }
// }

// int main()
// {
//     int V;
//     cout<<"Enter number of vertices->"<<endl;
//     cin>>V;    
//     vector<vector<int> > edges(V);
//     for(int i=0; i<V; i++)
//     {
//         int v;
//         cout<<"Enter vertex-> "<<endl;
//         cin>>v;
//         cout<<"Enter number of connected nodes-> "<<endl;
//         int n;
//         cin>>n;
//         while(n>0)
//         {
//             int u;
//             cin>>u;
//             edges[v].push_back(u);
//             n--;
//         }
//     }

//     unordered_map<int, list<int> > adjList;
//     vector<vector<int> > ans;
//     vector<bool> visited(V, false);

//     prepareAdjList(adjList, edges);

//     for(int i=0; i<V; i++)
//     {
//         if(!visited[i])
//         {
//             vector<int> component;
//             dfs(adjList, component, visited, i);
//             ans.push_back(component);
//         }
//     }

//     cout<<endl;
//     for(const auto& i: ans)
//         for(int j: i)
//             cout<<j<<" ";

//     return 0;
// }

void dfs(int node, vector<vector<int> > &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout<<node<<" ";

    for(int i=0; i<graph.size(); i++)
    {
        if(!visited[i] && graph[node][i] != 0)
            dfs(i, graph, visited);
    }
}

int main()
{
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

    vector<bool> visited(V, false);

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            dfs(i, graph, visited);
    }

    cout<<endl;
    

    return 0;
}
