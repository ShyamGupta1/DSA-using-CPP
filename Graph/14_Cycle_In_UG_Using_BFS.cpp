#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph
    bool BFS(int sNode, vector<int> &visited, vector<vector<int>> &graph, vector<int> &parent)
    {
        queue<int> qt;
        qt.push(sNode);
        visited[sNode] = 1;
        while (!qt.empty())
        {
            int node = qt.front();
            qt.pop();
            for (int nbr : graph[node])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = 1;
                    qt.push(nbr);
                    parent[nbr] = node;
                }
                // visited[nbr]==1;
                else if (parent[node] != nbr) // Check if the current-node parent is not equalits neighbours
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(vector<vector<int>> &adj)  // Here Graph is given nodes -> index, neighbours -> array at each index;
    {
        // Code here
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> parent(n, -1);
        for (int i = 0; i < n; i++)
        {
            // Check For each Component of graph
            if (!visited[i])
            {
                bool ans = BFS(i, visited, adj, parent);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};