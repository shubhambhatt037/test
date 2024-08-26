#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

void dfs(vector<vector<int> > adjMat, vector<int> &component, vector<bool> &visited, int node)
{
    component.push_back(node);
    visited[node] = 1;

    for(int i=0; i<adjMat[node].size(); i++)
    {
        if(adjMat[node][i] == 1 && !visited[i])
            dfs(adjMat, component, visited, i);
    }
}

int main()
{
    int V;
    cout<<"Enter number of vertices->"<<endl;
    cin>>V;    
    int E;
    cout<<"Enter number of edges->"<<endl;
    cin>>E; 

    vector<vector<int> > adjMat(V, vector<int>(V, 0));
    vector<vector<int> > ans;
    vector<bool> visited(V, false);

    cout<<"Enter adj matrix-> "<<endl;
    for(int i=0; i<V; i++)
    {
        // int v1 ,v2;
        // cout<<"Enter vertex and its connection"<<endl;
        // cin>>v1>>v2;

        // adjMat[v1][v2] = 1;
        // adjMat[v2][v1] = 1;
        for(int j=0; j<V; j++)
        {
            cin>>adjMat[i][j];
        }
    }

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(adjMat, component, visited, i);
            ans.push_back(component);
        }
    }

    cout<<endl;
    for(const auto& i: ans)
        for(int j: i)
            cout<<j<<" ";

    return 0;
}
