#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printGraphList(unordered_map<int, vector<int>> &graph)
{
    for (auto x : graph)
    {
        cout << "Vertex: " << x.first << ", Adjacent Nodes: ";
        for (int i = 0; i < x.second.size(); i++)
            cout << x.second[i] << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};

    unordered_map<int, vector<int>> graphList;
    for (int i = 0; i < edgeList.size(); i++)
    {
        // un-directed graph
        int first = edgeList[i][0];
        int second = edgeList[i][1];
        graphList[first].push_back(second);
        graphList[second].push_back(first);
    }
    printGraphList(graphList);

    return 0;
}