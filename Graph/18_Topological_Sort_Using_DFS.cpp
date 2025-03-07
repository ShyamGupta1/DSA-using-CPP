#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
class Solution
{
public:
    void DFS(int sNode, vector<vector<int>> &graph, vector<int> &visited)
    {
        visited[sNode] = 1;
        for (auto nbr : graph[sNode])
            if (!visited[nbr])
                DFS(nbr, graph, visited);

        dq.push_front(sNode);
    }
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> ans;
        vector<int> visited(n);

        for (int i = 0; i < n; i++)
            if (!visited[i])
                DFS(i, adj, visited);

        while (!dq.empty())
        {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};