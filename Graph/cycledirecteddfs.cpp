#include<iostream>

using namespace std;

bool cycledetected(int node, int V, vector<vector<int> > &adjMat, vector<int> &visited, vector<int> &dfsvisited)
{
    visited[node] = 1;
    dfsvisited[node] = 1;

    for(int i=0; i<V; i++)
    {
        if(adjMat[node][i] == 1)
        {
            if(!visited[i])
                if(cycledetected(i, V, adjMat, visited, dfsvisited))
                    return true;
            else if(dfsvisited[i])
                return true;
        }
    }

    dfsvisited[node] = 0;
    return false;
}

int main()
{
    int V;
    cout<<"Enter number of vertices-> "<<endl;
    cin>>V;

    vector<vector<int> > adjMat(V, vector<int>(V,0));
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cin>> adjMat[i][j];
        }
    }

    vector<int> visited(V, 0);
    vector<int> dfsvisited(V,0);


    bool iscycle = false;
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            if(cycledetected(i, V, adjMat, visited, dfsvisited)){
                iscycle = true;
                break;
            }
    }
    if(iscycle)
        cout<<"Cycle present"<<endl;
    else
        cout<<"Cycle not present"<<endl;
    
    return 0;

}
// #include <iostream>
// #include <vector>
// using namespace std;

// bool cycledetected(int node, int V, vector<vector<int> >& adjMat, vector<int>& visited, vector<int>& dfsvisited) {
//     visited[node] = 1;
//     dfsvisited[node] = 1;

//     for (int i = 0; i < V; i++) {
//         if (adjMat[node][i] == 1) {
//             if (!visited[i]) {
//                 if (cycledetected(i, V, adjMat, visited, dfsvisited)) {
//                     return true;
//                 }
//             } else if (dfsvisited[i]) {
//                 return true;
//             }
//         }
//     }

//     dfsvisited[node] = 0;
//     return false;
// }

// int main() {
//     int V;
//     cout << "Enter number of vertices: ";
//     cin >> V;

//     vector<vector<int> > adjMat(V, vector<int>(V, 0));
//     cout << "Enter the adjacency matrix:\n";
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             cin >> adjMat[i][j];
//         }
//     }

//     vector<int> visited(V, 0);
//     vector<int> dfsvisited(V, 0);

//     bool iscycle = false;
//     for (int i = 0; i < V; i++) {
//         if (!visited[i]) {
//             if (cycledetected(i, V, adjMat, visited, dfsvisited)) {
//                 iscycle = true;
//                 break;
//             }
//         }
//     }

//     if (iscycle) {
//         cout << "Cycle present" << endl;
//     } else {
//         cout << "Cycle not present" << endl;
//     }

//     return 0;
// }
