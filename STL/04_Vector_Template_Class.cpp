#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 3, 5, 6, 4, 6};
    vector<string> s1 = {"Who", "is", "a", "good", "boy?"};

    // How to access vector element
    // 1. []
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    // 2. at() method
    for (int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << " ";
    cout << endl;

    // 3. Implicit Iterator
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // 4. Explicit Iterator

    vector<string>::iterator it;

    for (it = s1.begin(); it != s1.end(); it++)
        cout << *it << " "; // Dereference the iterator to access the element
    cout << endl;

    // Const Iterator
    vector<string>::const_iterator iter;
    for (iter = s1.begin(); iter != s1.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << vec.back() << endl;
    cout << s1.front() << endl;
    cout << "Vector s1 is empty - ";
    cout << s1.empty() << endl;
    cout << s1.size() << endl;

    vector<int> vec2 = {12, 66, 22, 1, 4};
    vec.swap(vec2);
    cout << "Vec1 - ";
    for (auto x : vec)
        cout << x << " ";
    cout << endl;
    cout << "Vec2 - ";
    for (auto x : vec2)
        cout << x << " ";
    cout << endl;

    vec.clear();
    cout << "Size of Vec 1 is - " << vec.size() << endl; // Tells  Total Number of elements

    cout << "Capacity: " << vec.capacity() << endl; // Tells the space or capacity

    // Ways to insert data in vector
    // 1. push_back()
    vec.push_back(50);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // 2. insert()
    vec.insert(vec.begin() + 1, {12, 45, 67});
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // 3. emplace_back();
    vec.emplace_back(100);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // 4. Emplace()
    vec.emplace(vec.begin() + 2, 200);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    *(vec.begin() + 2) = 150;
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    vec.shrink_to_fit();
    cout << "Capacity: " << vec.capacity() << endl;

    // 2nd Variation of insert()
    vec.insert(vec.begin() + 1, 4, 7);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // 3rd Variaton of insert()
    cout << "Vec 2: ";
    for (auto x : vec2)
        cout << x << " ";
    cout << endl;

    vec.insert(vec.begin() + 1, vec2.begin() + 1, vec2.begin() + 4);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    vec.insert(vec.end() - 1, vec2.begin() + 1, vec2.begin() + 4);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // How to delete elements only works with the position through iterator, can not pass value directly
    // 1. erase()
    vec.erase(vec.begin() + 9);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // 2. erase()  Can delete range of elements
    vec.erase(vec.begin() + 4, vec.begin() + 9);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // 3. pop_back()
    vec.pop_back();
    for (auto x : vec)
        cout << x << " ";
    cout << endl;
    return 0;
}