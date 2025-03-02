#include <iostream>
#include <vector>
using namespace std;

void printGraph(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "\nVertex: " << i + 1 << ", Adjacent Nodes: ";
        for (int j = 0; j < graph[0].size(); j++)
            if (graph[i][j] == 1)
                cout << j + 1 << " ";
    }
}

int main()
{
    vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}}; // Total 4 Vertices

    int n = 4; // Total vertices

    vector<vector<int>> graphMatrix(4, vector<int>(4, 0));
    for (int i = 0; i < edgeList.size(); i++)
    {
        int first = edgeList[i][0];
        int second = edgeList[i][1];
        graphMatrix[first - 1][second - 1] = 1;
        graphMatrix[second - 1][first - 1] = 1;
    }
    printGraph(graphMatrix);
    return 0;
}