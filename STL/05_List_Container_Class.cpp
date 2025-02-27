#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l1 = {1, 2, 4, 5, 7};
    // How to access list elements
    // [] and at() are not there in list

    // 1. Using Implicit Iterator
    for (auto x : l1)
        cout << x << " ";
    cout << endl;

    // 2. Using Explicit Iterator
    list<int>::iterator it;
    for (it = l1.begin(); it != l1.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << l1.back() << endl;
    cout << l1.front() << endl;
    

    return 0;
}