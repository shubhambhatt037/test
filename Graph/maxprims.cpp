#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxBudget(const vector<vector<int> >& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    visited[0] = true;  // Start with the first vertex as visited
    int maxBudget = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        int maxWeight = INT_MIN;
        int maxVertex = -1;

        for (int i = 0; i < numVertices; ++i) {
            if (visited[i]) {
                for (int j = 0; j < numVertices; ++j) {
                    if (!visited[j] && graph[i][j] > maxWeight) {
                        maxWeight = graph[i][j];
                        maxVertex = j;
                    }
                }
            }
        }

        visited[maxVertex] = true;
        maxBudget += maxWeight;
    }

    return maxBudget;
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the adjacency matrix:\n";
    vector<std::vector<int> > graph(numVertices, std::vector<int>(numVertices));
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    int maxBudget = findMaxBudget(graph);
    cout << "Maximum budget required for the project: " << maxBudget << endl;

    return 0;
}
