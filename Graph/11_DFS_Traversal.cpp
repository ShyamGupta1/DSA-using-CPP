#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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

void BFS(unordered_map<int, vector<int>> &graph, int sNode)
{
    queue<int> qt;
    qt.push(sNode);
    unordered_map<int, int> isVisited;
    for (auto x : graph)
        isVisited[x.first] = 0;
    isVisited[sNode] = 1;
    while (!qt.empty())
    {
        cout << qt.front() << " ";
        for (int it : graph[qt.front()])
        {
            if (isVisited[it] == 0)
            {
                qt.push(it);
                isVisited[it] = 1;
            }
        }
        qt.pop();
    }
}

void DFS(int sNode, unordered_map<int, vector<int>> &graph, unordered_map<int, int> &visited)
{
    cout << sNode << " ";
    visited[sNode] = 1;
    for (int x : graph[sNode])
    {
        if (visited[x] == 0)
            DFS(x, graph, visited);
    }
}

int main()
{
    vector<vector<int>> edgeList = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};

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
    unordered_map<int, int> isVisited;
    for (auto x : graphList)
        isVisited[x.first] = 0;
    DFS(0, graphList, isVisited);
    return 0;
}
