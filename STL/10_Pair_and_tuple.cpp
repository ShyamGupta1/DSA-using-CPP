#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
    vector<int> vec = {12, 45, 67, 32, 56, 78};
    string name = "Mohit";
    pair<string, vector<int>> p;
    p = make_pair(name, vec);
    cout << p.first << endl;
    for (auto x : p.second)
        cout << x << " ";
    cout << endl;

    pair<int, string> p1(1, "Agra");
    pair<int, int> p2(12, 56);
    pair<int, int> p3(9, 0);
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    p2.swap(p3);
    cout << p2.first << " " << p2.second << endl;
    cout << p3.first << " " << p3.second << endl;

    tuple<int, string, char> t;
    t = make_tuple(1, "Amit", 'C');
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    tuple<int, string, float> t1(1, "Raju", 1234.45);

    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

    return 0;
}