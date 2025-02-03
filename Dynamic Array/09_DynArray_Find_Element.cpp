/*
Define a destructor to deallocate the memory of array.
Define a method to find an element in the array. Return index if the element found, otherwise return -1 .
*/

#include <iostream>

using namespace std;

class DynArray
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

protected:
    void doubleArray();
    void halfArray();

public:
    DynArray(int);
    bool isFull();
    bool isEmpty();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    int getElement(int);
    int count();
    int find(int);
    ~DynArray();
    void display();
};

DynArray::DynArray(int size) : capacity(size)
{
    if (size <= 0)
        ptr = NULL;
    else
    {
        lastIndex = -1;
        ptr = new int[capacity];
    }
}

void DynArray::halfArray()
{
    int *temp, i;
    capacity /= 2;
    temp = new int[capacity];
    for (i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
}

void DynArray::doubleArray()
{
    int *temp, i;
    capacity *= 2;
    temp = new int[capacity];
    for (i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
}

bool DynArray::isFull()
{
    return capacity == lastIndex + 1;
}

bool DynArray::isEmpty()
{
    return lastIndex == -1;
}
void DynArray::append(int data)
{
    if (isFull())
        doubleArray();
    ptr[++lastIndex] = data;
}

void DynArray::insert(int index, int data)
{
    int i;
    if (index < 0 || index > lastIndex + 1)
    {
        cout << "Invalid Index";
        return;
    }
    if (isFull())
        doubleArray();
    for (i = lastIndex; i >= index; i--)
        ptr[i + 1] = ptr[i];
    ptr[index] = data;
    lastIndex++;
}

void DynArray::edit(int index, int data)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "\nInvalid Index";
        return;
    }
    ptr[index] = data;
}

int DynArray::getElement(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "\nInvalid Index";
        throw new exception();
    }
    else
    {
        return ptr[index];
    }
}

int DynArray::count()
{
    return lastIndex + 1;
}

int DynArray::find(int data)
{
    for (int i = 0; i <= lastIndex; i++)
        if (ptr[i] == data)
            return i;
    return -1;
}

DynArray::~DynArray()
{
    delete[] ptr;
}
void DynArray::display()
{
    if (isEmpty())
        cout << "\nArray is Empty";
    else
        for (int i = 0; i <= lastIndex; i++)
            cout << ptr[i] << " ";
}
int main()
{
    DynArray arr(8);
    cout << arr.getElement(1);
    return 0;
}
