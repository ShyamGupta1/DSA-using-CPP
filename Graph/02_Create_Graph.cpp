/*
In Question 1, define a method createGraph() to create and store adjacent node
information.
*/

#include <iostream>
using namespace std;

class GraphMatrix
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    void createGraph(int, int);
};

void GraphMatrix::createGraph(int vno, int eno)
{
    int u, v;
    v_count = vno;
    e_count = eno;
    adj = new int *[v_count];
    for (int i = 0; i < v_count; i++)
        adj[i] = new int[v_count];

    for (int i = 0; i < v_count; i++)
        for (int j = 0; j < v_count; j++)
            adj[i][j] = 0;

    for (int k = 1; k <= e_count; k++)
    {
        cout << "Enter node numbers connecting edge " << k << ": ";
        cin >> u >> v;
        adj[u - 1][v - 1] = 1;
        adj[v - 1][u - 1] = 1;
    }
}

int main()
{
    return 0;
}