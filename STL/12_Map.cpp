#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
    map<int, string> m1 = {
        {1, "Indore"},
        {2, "Ujjain"},
        {3, "Agra"},
        {4, "Gwalior"},
        {5, "Lucknow"}};

    for (auto element : m1)
    {
        cout << element.first << " " << element.second << endl;
    }
    cout << endl;
    // Explicit Iterator
    map<int, string>::iterator it;
    for (it = m1.begin(); it != m1.end(); it++)
        cout << it->first << " " << it->second << endl;

    cout << m1.at(3) << endl;    // Can access any data if we know the associated key,
    cout << m1.count(3) << endl; // Only 0 or 1

    m1.emplace(make_pair(6, "Rajkot"));
    for (auto element : m1)
    {
        cout << element.first << " " << element.second << endl;
    }

    m1.erase(4);
    cout << endl;

    for (auto element : m1)
    {
        cout << element.first << " " << element.second << endl;
    }

    return 0;
}
