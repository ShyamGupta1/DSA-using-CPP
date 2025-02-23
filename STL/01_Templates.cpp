#include <iostream>
#include "Time_Class.cpp"
using namespace std;

template <typename X>
X big(X a, X b)
{
    return a < b ? b : a;
}

int main()
{
    cout << big(34, 56) << endl;
    cout << big(34.34, 13.45) << endl;
    Time T1, T2;
    T1.setTime(12, 34, 56);
    T2.setTime(4, 56, 32);
    cout << big(T1, T2);

    return 0;
}