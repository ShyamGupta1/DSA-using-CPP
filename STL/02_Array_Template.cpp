#include <iostream>
using namespace std;

template <class X>

class Array
{
private:
    int capacity;
    int lastIndex;
    X *ptr;

public:
    Array();
    Array(int);
    Array(const Array<X> &);
    Array &operator=(const Array<X> &);
    bool isEmpty();
    bool isFull();
    void append(X);
    void insert(int, X);
    void edit(int, X);
    void del(int);
    X getElement(int);
    int count();
    int find(X);
    ~Array();
    void setValues();
    void display();
};

template <class X>
bool Array<X>::isEmpty()
{
    return lastIndex == -1;
}

template <class X>
bool Array<X>::isFull()
{
    return lastIndex == capacity - 1;
}

template <class X>
void Array<X>::append(X value)
{
    if (isFull())
    {
        cout << "\nArray is full or Overflow";
        return;
    }
    else
        ptr[++lastIndex] = value;
}

template <class X>
void Array<X>::insert(int index, X value)
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

template <class X>
void Array<X>::edit(int index, X value)
{
    if (index < 0 || index > lastIndex)
        cout << "\nInvalid Index";
    else
        ptr[index] = value;
}

template <class X>
void Array<X>::del(int index)
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

template <class X>
X Array<X>::getElement(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid Index or empty array";
        throw new exception();
    }
    return ptr[index];
}

template <class X>
int Array<X>::count()
{
    return lastIndex + 1;
}

template <class X>
int Array<X>::find(X value)
{
    for (int i = 0; i <= lastIndex; i++)
        if (ptr[i] == value)
            return i;
    return -1;
}

template <class X>
Array<X>::Array(int size) : capacity(size)
{
    if (size <= 0)
        ptr = nullptr;
    else
    {
        lastIndex = -1;
        ptr = new X[capacity];
    }
}

template <class X>
Array<X>::~Array() { delete[] ptr; }

// Default Constructor
template <class X>
Array<X>::Array() : capacity(0), lastIndex(-1), ptr(nullptr) {}

// Copy Constructor
template <class X>
Array<X>::Array(const Array<X> &arr)
{
    this->capacity = arr.capacity;
    this->lastIndex = arr.lastIndex;
    ptr = new X[capacity];
    for (int i = 0; i <= arr.lastIndex; i++)
        ptr[i] = arr.ptr[i];
}

template <class X>
Array<X> &Array<X>::operator=(const Array<X> &arr)
{
    if (this != &arr) // shouldn't be the same array
    {
        if (ptr != nullptr) // release previous memory location
            delete[] ptr;
        this->capacity = arr.capacity;
        this->lastIndex = arr.lastIndex;
        ptr = new X[capacity];
        for (int i = 0; i <= arr.lastIndex; i++)
            ptr[i] = arr.ptr[i];
    }
    return *this;
}

template <class X>
void Array<X>::setValues()
{
    cout << "Enter " << capacity << " Elements: ";
    for (int i = 0; i < capacity; i++)
    {
        cin >> ptr[i];
        lastIndex++;
    }
}

template <class X>
void Array<X>::display()
{
    if (isEmpty())
        cout << "\nArray is Empty";
    else
        for (int i = 0; i <= lastIndex; i++)
            cout << ptr[i] << " ";
}

int main()
{
    Array<string> arr(8);
    arr.append("you");
    arr.append("are");
    arr.append("an");
    arr.append("amazing");
    arr.append("person.");
    cout << endl;
    Array<string> arr2, arr3;
    arr3 = arr2 = arr;
    arr.display();
    cout << endl;
    arr2.display();
    cout << endl;
    arr3.display();
    return 0;
}
