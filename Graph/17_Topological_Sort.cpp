#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        // Your code
        int n = adj.size();
        vector<int> ans;
        vector<int> indegree(n);

        // Count Indegree of each node
        for (auto x : adj)
            for (int y : x)
                indegree[y]++;

        queue<int> qt;
        // Push all the nodes with indegree zero in to queue as the have no prerequisites
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                qt.push(i);

        // Apply BFS
        while (!qt.empty())
        {
            int node = qt.front();
            ans.push_back(node);
            qt.pop();
            for (auto x : adj[node])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                    qt.push(x);
            }
        }
        return ans;
    }
};
