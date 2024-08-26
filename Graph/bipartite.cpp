#include<iostream>
#include<queue>

using namespace std;

bool bipartite(vector<vector<int> > adjMat, int start, int V)
{
    queue<int> q;
    q.push(start);

    vector<int> color(V, -1);
    color[start] = 0;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(int i=0; i<V; i++)
        {
            if(adjMat[front][i] == 1 && color[i] == -1)
            {
                color[i] = 1-color[front];
                q.push(i);
            }else if(adjMat[front][i] == 1 && color[i] == color[front])
                return false;
        }
    }

    return true;
}

int main()
{
    int V;
    cout<<"Enter number of vertices->"<<endl;
    cin>>V;  
    cout<<"Enter adjacency matrix-> "<<endl;
    vector<vector<int> > adjMat(V, vector<int>(V,0));
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cin>> adjMat[i][j];
        }
    }

    if(bipartite(adjMat, 0, V))
        cout<<"Yes barpartite"<<endl;
    else
        cout<<"Not barpartite"<<endl;
    
    return 0;

}