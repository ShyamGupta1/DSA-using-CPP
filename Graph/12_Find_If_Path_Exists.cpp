#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(int sNode, unordered_map<int, vector<int>> &graph, vector<int> &visited)
    {
        visited[sNode] = 1;
        for (int x : graph[sNode])
        {
            if (visited[x] == 0)
                DFS(x, graph, visited);
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        // Create Graph
        unordered_map<int, vector<int>> graph;
        for (auto x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        // Create a vector to track the if the node is visited or not
        vector<int> visited(n, 0);

        DFS(source, graph, visited);

        return visited[destination] == 1 ? true : false;
    }
};

class Solution
{
public:
    void BFS(int sNode, vector<vector<int>> &graph, vector<int> &visited)
    {
        queue<int> qt;
        qt.push(sNode);
        visited[sNode] = 1;
        while (!qt.empty())
        {
            for (int x : graph[qt.front()])
            {
                if (visited[x] == 0)
                {
                    qt.push(x);
                    visited[x] = 1;
                }
            }
            qt.pop();
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        // Create Graph
        vector<int> visited(n);
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        // Create a vector to track the if the node is visited or not
        BFS(source, graph, visited);
        return visited[destination];
    }
};