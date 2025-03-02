/*
Define a class Graph to implement linked list representation of graph. Define
needful structure for node and class for AdjList.
*/

#include <iostream>
using namespace std;

class node
{
public:
    int weight;
    int vertex;
    node *next;
    node() : weight(0), next(NULL), vertex(-1) {}
};

class AdjList
{
private:
    node *start;
    int vertex;

public:
    AdjList() : start(NULL) {}
    AdjList(int vno) : vertex(vno), start(NULL) {}
    void setVertex(int);
    void addNode(int, int);
    void printList();
    void removeFirstNode();
    ~AdjList()
    {
        while (start)
            removeFirstNode();
    }
};
void AdjList::removeFirstNode()
{
    if (start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}
void AdjList::printList()
{
    node *temp = start;
    while (temp)
    {
        cout << " (" << temp->vertex << "," << temp->weight << ") ";
        temp = temp->next;
    }
}
void AdjList::addNode(int data, int vno)
{
    node *newNode = new node;
    newNode->weight = data;
    newNode->vertex = vno;
    newNode->next = start;
    start = newNode;
}
void AdjList::setVertex(int vno)
{
    vertex = vno;
}

class Graph
{
private:
    int v_count;
    AdjList *arr;

public:
    Graph();
    int getVCount();
    void createGraph(int);
    void printGraph();
};
Graph::Graph()
{
    v_count = 0;
    arr = NULL;
}
int Graph::getVCount()
{
    return v_count;
}
void Graph::createGraph(int vno)
{
    int n, v, data;
    v_count = vno;
    arr = new AdjList[vno];
    for (int i = 0; i < v_count; i++)
    {
        arr[i].setVertex(i);
        cout << "\nHow many adjacent nodes of V" << i << " : ";
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cout << "\nEnter adjacent node of V" << i << " : ";
            cin >> v;
            cout << "\nEnter Weight associated with that node: ";
            cin >> data;
            arr[i].addNode(data, v);
        }
    }
}
void Graph::printGraph()
{
    for (int i = 0; i < v_count; i++)
    {
        cout << "\nVertex " << i << ": ";
        arr[i].printList();
    }
}

int main()
{
    Graph g;
    g.createGraph(6);
    cout << endl;
    cout << g.getVCount() << endl;
    g.printGraph();
    return 0;
}