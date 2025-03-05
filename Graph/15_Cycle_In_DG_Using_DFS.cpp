#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool DFS(int sNode, vector<vector<int>> &graph, vector<int> &visited, vector<int> &currentPath)
    {
        visited[sNode] = 1;
        currentPath[sNode] = 1;
        for (auto nbr : graph[sNode])
        {
            if (!visited[nbr])
            {
                bool ans = DFS(nbr, graph, visited, currentPath);
                if (ans)
                    return true;
            }
            else if (currentPath[nbr] == 1)
                return true;
        }
        currentPath[sNode] = 0;
        return false;
    }

    bool isCyclic(vector<vector<int>> &adj)
    {

        int n = adj.size();
        vector<int> visited(n), currentPath(n);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bool ans = DFS(i, adj, visited, currentPath);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};
