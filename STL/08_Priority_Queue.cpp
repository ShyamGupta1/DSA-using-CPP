#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

class Employee
{
private:
    int empid;
    string name;
    float salary;

public:
    Employee(int i, string n, float s) : empid(i), name(n), salary(s) {};
    float getSalary()
    {
        return salary;
    }
    string getName()
    {
        return name;
    }
    void showEmployee()
    {
        cout << empid << " " << name << " " << salary << endl;
    }
};

// Functor
class CompareSalary
{
public:
    bool operator()(Employee &e1, Employee &e2)
    {
        return e1.getSalary() < e2.getSalary();
    }
};

class CompareName
{
public:
    bool operator()(Employee &e1, Employee &e2)
    {
        return e1.getName() < e2.getName();
    }
};

int main()
{
    priority_queue<int> pq; // vector
    priority_queue<string, deque<string>> pq1;
    pq.push(2);
    pq.push(67);
    pq.push(53);
    pq.push(21);
    pq.push(63);
    pq.push(83);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    pq1.push("Suresh");
    pq1.push("Amit");
    pq1.push("Ranjan");
    pq1.push("Mukesh");
    cout << pq1.top() << endl;

    priority_queue<Employee, deque<Employee>, CompareName> pq2;
    pq2.push(*(new Employee(1, "Srijan", 10000)));
    pq2.push(*(new Employee(2, "Arjun", 65000)));
    pq2.push(*(new Employee(3, "Mukesh", 80000)));
    Employee E = pq2.top();

    E.showEmployee();

    return 0;
}