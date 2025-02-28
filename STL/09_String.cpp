#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "Dilip";
    string s2;
    cout << s1 << endl;

    for (int i = 0; i < s1.size(); i++)
        cout << s1[i] << " ";
    cout << endl;

    for (int i = 0; i < s1.size(); i++)
        cout << s1.at(i) << " ";
    cout << endl;

    string::iterator it = s1.begin();

    for (; it != s1.end(); it++)
        cout << *it << " "; // Random access iterator
    cout << endl;

    for (auto x : s1)
        cout << x << " ";

    cout << s1.front() << endl;
    cout << s1.back() << endl;
    s1.append(" Kumar");
    cout << s1;
    cout << endl;

    s1.insert(5, " Singhania");
    s1.replace(6, 9, "Singh");
    cout << s1.substr(6, 5) << endl;
    s1 = s1 + " is a good boy";
    cout << s1;
    return 0;
}