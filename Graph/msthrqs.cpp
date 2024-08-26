// #include<iostream>
// using namespace std;

// int findparent(vector<int> &parent, int v)
// {
//     if(parent[v] == -1)
//         return v;
    
//     return findparent(parent, parent[v]);
// }

// void unionset(vector<int> &parent, int psrc, int pdes)
// {
//     int x = findparent(parent, psrc);
//     int y = findparent(parent, pdes);
//     parent[psrc] = pdes;
// }

// int pathdestroy(vector<pair<int, int> > &edges, int V ,int E)
// {
//     vector<int> parent(V, -1);   

//     int nc = V;

//     for(int i=0; i<E; i++)
//     {
//         int psrc = findparent(parent, edges[i].first);
//         int pdes = findparent(parent, edges[i].second);

//         if(psrc != pdes)
//         {
//             unionset(parent, psrc, pdes);
//             nc--;
//         }
//     } 
//     return nc-1;
// }

// int main()
// {
//     vector<pair<int, int> > edges;
//     int v,e;
//     cin>>v>>e;

//     for(int i=0; i<e; i++)
//     {
//         int x, y;
//         cin>>x>>y;

//         edges.push_back(make_pair(x, y));
//     }

//     cout<<pathdestroy(edges, v, e)<<endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

int getNumberOfRoadsToDestroy(int V, const vector<pair<int, int> >& edges) {
    vector<int> parent(V, -1);
    int numberOfComponents = V;
    int numRoads = 0;

    for (const auto& edge : edges) {
        int srcParent = find(parent, edge.first);
        int destParent = find(parent, edge.second);

        if (srcParent != destParent) {
            unionSets(parent, srcParent, destParent);
            numberOfComponents--;
        }else
            numRoads++;
    }

    return numRoads;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<pair<int, int> > edges;
        for (int i = 0; i < p; i++) {
            int u1, u2;
            cin >> u1 >> u2;
            edges.push_back(make_pair(u1, u2));
        }

        int numberOfRoadsToDestroy = getNumberOfRoadsToDestroy(n, edges);
        cout <<endl<< numberOfRoadsToDestroy << endl;
    }

    return 0;
}
