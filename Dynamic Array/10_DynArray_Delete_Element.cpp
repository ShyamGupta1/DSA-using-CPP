// In question 1, define a method to delete an element at specified index.

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
    int count();
    bool isFull();
    bool isEmpty();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
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

void DynArray::del(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "\nInvalid Index";
        return;
    }
    for (int i = index; i < lastIndex; i++)
        ptr[i] = ptr[i + 1];
    lastIndex--;
    if (2 * (lastIndex + 1) <= capacity && capacity > 1)
        halfArray();
}
int DynArray::count()
{
    return lastIndex + 1;
}
void DynArray::display()
{
    for (int i = 0; i <= lastIndex; i++)
        cout << ptr[i] << " ";
    cout << endl;
    cout << capacity << " " << lastIndex;
}
int main()
{
    DynArray arr(7);
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    cout << endl;
    arr.display();
    arr.del(0);
    cout << endl;
    arr.display();
    return 0;
}
