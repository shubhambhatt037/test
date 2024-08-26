#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
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

// void bfs(int node, unordered_map<int, list<int> > adjList, vector<int> &ans, unordered_map<int, bool> &visited)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = 1;
//     while (!q.empty())
//     {
//         int front = q.front();
//         q.pop();

//         ans.push_back(front);

//         for(auto i: adjList[front])
//         {
//             if(!visited[i]){
//                 q.push(i);
//                 visited[i] = 1;
//             }
//         }
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
//     vector<int> ans;
//     unordered_map<int, bool> visited;
//     prepareAdjList(adjList, edges);
//     for(int i=0; i<V; i++)
//     {
//         if(!visited[i])
//             bfs(i, adjList, ans, visited);
//     }

//     cout<<endl;
//     for(auto i: ans)
//         cout<<i<<" ";

//     return 0;
// }

void bfs(int node, vector<vector<int> > &graph, vector<bool> &visited, vector<int> &ans)
{
    queue<int> q;
    visited[node] = true;
    q.push(node);

    int V = graph.size();

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        for(int i=0; i<V; i++)
        {
            if(!visited[i] && graph[front][i] != 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
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

    vector<int> ans;
    vector<bool> visited(V, false);

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            bfs(i, graph, visited, ans);
    }

    cout<<endl;
    for(auto i: ans)
        cout<<i<<" ";

    return 0;
}
