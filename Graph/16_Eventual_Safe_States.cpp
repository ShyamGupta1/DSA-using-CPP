#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool DFS(int sNode, vector<vector<int>> &graph, vector<int> &visited, vector<int> &currentPath)
    {
        visited[sNode] = 1;
        currentPath[sNode] = 1;
        for (int nbr : graph[sNode])
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

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> visited(n), currentPath(n);
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                bool ans = DFS(i, graph, visited, currentPath);
        for (int i = 0; i < n; i++)
            if (currentPath[i] == 0)
                ans.push_back(i);
        return ans;
    }
};