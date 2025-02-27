#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

int main()
{
    stack<int> st;              // deque    or    stack<int, deque<int>> s1;
    stack<int, vector<int>> s2; // vector
    stack<int, list<int>> s3;   // list

    st.push(3);
    st.push(6);
    st.push(8);
    st.push(2);
    st.push(7);
    st.push(8);

    st.pop();

    cout << st.top() << endl;
    cout << st.size() << endl;

    return 0;
}