/*
In question 1, define a method to find an element in the array. Return index if the
element found, otherwise return -1.
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
    Array(const Array &);
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
    {
        cout << "\nArray is full or Overflow";
        return;
    }
    else
        ptr[++lastIndex] = value;
}
void Array::insert(int index, int value)
{
    if (index > lastIndex + 1 || index < 0)
        cout << "Not a valid index";
    else if (isFull())
        cout << "\nOverflow";
    else
    {
        for (int i = lastIndex + 1; i > index; i--)
            ptr[i] = ptr[i - 1];
        ptr[index] = value;
        lastIndex++;
    }
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
        cout << "\nInvalid Index";
    else
    {
        for (int i = index; i < lastIndex; i++)
            ptr[i] = ptr[i + 1];
        lastIndex--;
    }
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

// Copy Constructor

Array::Array(const Array &arr)
{
    this->capacity = arr.capacity;
    this->lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for (int i = 0; i <= arr.lastIndex; i++)
        ptr[i] = arr.ptr[i];
}

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
}

int main()
{
    Array arr(8);
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(10);
    cout << endl;
    Array arr2 = arr;
    arr.display();
    cout << endl;
    arr2.display();
    return 0;
}
