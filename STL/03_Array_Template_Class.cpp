#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 4> arr{1, 2, 4, 6};
    array<string, 5> s1 = {"Who", "is", "a", "good", "boy?"}; // It can also store Non - Primitive data type

    // How to Access array elements

    // 1. Using Subscript operator [] this is overloaded in class array

    for (int i = 0; i < 4; i++)
        cout << arr[i] << " ";
    cout << endl;

    // 2. Using at function at()

    try
    {
        for (int i = 0; i < 5; i++)
            cout << arr.at(i) << " ";
    }
    catch (std::out_of_range e)
    {
        cout << "\nIndex out of range";
    }
    cout << endl;

    // 3. Using implicit iterator | using range-for loop
    for (auto x : s1)
        cout << x << " ";
    cout << endl;

    // 4. Using Explicit iterators

    array<int, 4>::iterator i1; // Object of iterator class
    for (i1 = arr.begin(); i1 != arr.end(); i1++)
        cout << *i1 << " ";
    cout << endl;

    array<int, 4>::reverse_iterator i2; // Object of reverse iterator class
    for (i2 = arr.rbegin(); i2 != arr.rend(); i2++)
        cout << *i2 << " ";
    cout << endl;

    array<int, 4>::const_iterator i3;
    i3 = arr.cbegin();
    // *(i3 + 2) = 70; // Const Iterator so we can not change values we can only read
    *(arr.begin() + 2) = 70;
    cout << *(i3 + 2) << endl;

    cout << arr.back() << endl;
    cout << arr.front() << endl;
    cout << arr.size() << endl;

    return 0;
}