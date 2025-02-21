#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    int capacity;
    int highest_priority;
    int **ptr;
    int *front;
    int *rear;

public:
    PriorityQueue(int, int);
    bool isFull(int);
    bool isEmpty(int);
    void insert(int, int);
    void deleteElement();
    void printHighestPriorityElements();
    int countHighestPriorityElements();
};

int PriorityQueue::countHighestPriorityElements()
{
    for (int i = highest_priority; i >= 0; i--)
    {
        if (!isEmpty(i))
        {
            if (front[i] <= rear[i])
                return rear[i] - front[i] + 1;
            else // (rear[i] > front[i])
                return capacity + rear[i] - front[i] + 1;
        }
    }
    return 0;
}

void PriorityQueue::printHighestPriorityElements()
{
    for (int i = highest_priority; i >= 0; i--)
    {
        if (!isEmpty(i))
        {
            // Single Element
            if (front[i] == rear[i])
                cout << ptr[i][front[i]];

            // When front < rear
            else if (front[i] < rear[i])
                for (int j = front[i]; j <= rear[i]; j++)
                    cout << ptr[i][j] << " ";
            // Circular Case When rear < front
            else
            {
                for (int j = front[i]; j < capacity; j++)
                    cout << ptr[i][j] << " ";
                for (int j = 0; j <= rear[i]; j++)
                    cout << ptr[i][j] << " ";
            }
            return;
        }
    }
    cout << "\nPriority Queue is Empty";
    return;
}

void PriorityQueue::deleteElement()
{
    for (int i = highest_priority; i >= 0; i--)
    {
        if (!isEmpty(i))
        {
            // Single Element
            if (front[i] == rear[i])
                front[i] = rear[i] = -1;

            // Special Case when Front is at the end of the array
            else if (front[i] == capacity - 1)
                front[i] = 0;
            // Normal Case
            else
                front[i]++;
            return;
        }
    }
    cout << "\nPriority Queue is Empty";
    return;
}

void PriorityQueue::insert(int data, int pno)
{
    if (pno < 0 || pno > highest_priority)
    {
        cout << "\nInvalid priority number";
        return;
    }
    else if (isFull(pno))
    {
        cout << "\nPriority " << pno << " Queue is full";
        return;
    }

    // Empty Case
    else if (isEmpty(pno))
    {
        front[pno] = rear[pno] = 0;
        ptr[pno][front[pno]] = data;
    }

    // Special Case: Rear is at the end of the array
    else if (rear[pno] == capacity - 1)
    {
        rear[pno] = 0;
        ptr[pno][rear[pno]] = data;
    }

    // Normal case
    else
    {
        rear[pno]++;
        ptr[pno][rear[pno]] = data;
    }
}

bool PriorityQueue::isEmpty(int pno)
{
    if (front[pno] == -1 && rear[pno] == -1)
        return true;
    return false;
}

bool PriorityQueue::isFull(int pno)
{
    if (front[pno] == 0 && rear[pno] + 1 == capacity || rear[pno] + 1 == front[pno])
        return true;
    return false;
}

PriorityQueue::PriorityQueue(int cap, int hp) : capacity(cap), highest_priority(hp)
{

    if (capacity <= 0)
        capacity = 1;

    ptr = new int *[highest_priority + 1];
    for (int i = 0; i <= highest_priority; ++i)
        ptr[i] = new int[capacity];

    front = new int[highest_priority + 1];
    rear = new int[highest_priority + 1];

    for (int i = 0; i <= highest_priority; ++i)
    {
        front[i] = -1;
        rear[i] = -1;
    }
}

int main()
{
    return 0;
}