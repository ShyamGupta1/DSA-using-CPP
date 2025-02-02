/*
Define a class DynArray to implement dynamic array data structure with member
variables to store capacity of array, last index of the last filled block of the array and
a pointer to hold the address of the first block of the dynamically created array.
Define a parameterised constructor to create an array of specified
size.
*/

#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int);
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int getElement(int);
    int count();
    int find(int);
    ~Array();
    void setValues();
    void display();
    void dynArray()
    {
        int *temp, i;
        capacity *= 2;
        temp = new int[capacity];
        for (i = 0; i <= lastIndex; i++)
            temp[i] = ptr[i];
        delete[] ptr;
        ptr = temp;
    }
    void halfArray()
    {
        int *temp, i;
        capacity /= 2;
        temp = new int[capacity];
        for (i = 0; i <= lastIndex; i++)
            temp[i] = ptr[i];
        delete[] ptr;
        ptr = temp;
    }
};

bool Array::isEmpty()
{
    return lastIndex == -1;
}
bool Array::isFull()
{
    return lastIndex == capacity - 1;
}
void Array::append(int value)
{
    if (isFull())
        dynArray();
    ptr[++lastIndex] = value;
}
void Array::insert(int index, int value)
{
    if (index > lastIndex + 1 || index < 0)
    {
        cout << "\nInvalid index";
        return;
    }
    if (isFull())
        dynArray();
    for (int i = lastIndex + 1; i > index; i--)
        ptr[i] = ptr[i - 1];
    ptr[index] = value;
    lastIndex++;
}
void Array::edit(int index, int value)
{
    if (index < 0 || index > lastIndex)
        cout << "\nInvalid Index";
    else
        ptr[index] = value;
}
void Array::del(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "\nInvalid Index";
        return;
    }

    for (int i = index; i < lastIndex; i++)
        ptr[i] = ptr[i + 1];
    lastIndex--;
    if (2 * count() == capacity)
        halfArray();
}
int Array::getElement(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid Index or empty array";
        throw new exception();
    }
    return ptr[index];
}
int Array::count()
{
    return lastIndex + 1;
}
int Array::find(int value)
{
    for (int i = 0; i <= lastIndex; i++)
        if (ptr[i] == value)
            return i;
    return -1;
}
Array::Array(int size) : capacity(size)
{
    if (size <= 0)
        ptr = nullptr;
    else
    {
        lastIndex = -1;
        ptr = new int[capacity];
    }
}
Array::~Array() { delete[] ptr; }

void Array::setValues()
{
    cout << "Enter " << capacity << " Elements: ";
    for (int i = 0; i < capacity; i++)
    {
        cin >> ptr[i];
        lastIndex++;
    }
}

void Array::display()
{
    if (isEmpty())
        cout << "\nArray is Empty";
    else
        for (int i = 0; i <= lastIndex; i++)
            cout << ptr[i] << " ";
    cout << "\n"
         << capacity << " " << lastIndex << " ";
}

int main()
{
    Array arr(4);
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(5);
    arr.del(5);
    cout << endl;
    arr.display();
    return 0;
}
