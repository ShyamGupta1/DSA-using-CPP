// In question 1, define a method to print all the adjacent nodes of a given node.

#include <iostream>
using namespace std;

class GraphMatrix
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    GraphMatrix() : v_count(0), e_count(0), adj(NULL) {}
    void createGraph(int, int);
    void printMatrix();
    void printAdjacentNodes();
};

void GraphMatrix::printMatrix()
{
    if (adj)
    {
        for (int i = 0; i < v_count; i++)
        {
            for (int j = 0; j < v_count; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
}

void GraphMatrix::printAdjacentNodes()
{
    if (adj)
    {
        for (int i = 0; i < v_count; i++)
        {
            cout << "Node: " << i + 1 << " ,Adjacent Nodes: ";
            for (int j = 0; j < v_count; j++)
                if (adj[i][j] == 1)
                    cout << j + 1 << " ";
            cout << endl;
        }
    }
}

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
    GraphMatrix graph;
    graph.createGraph(5, 7);
    graph.printAdjacentNodes();

    return 0;
}
