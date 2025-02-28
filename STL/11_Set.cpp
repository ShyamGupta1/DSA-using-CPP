#include <iostream>
#include <set>
using namespace std;
class Book
{
private:
    int bookID;
    string name;
    float price;

public:
    Book(int id, string title, float p) : bookID(id), name(title), price(p) {}
    void showBook() const
    {
        cout << bookID << " " << name << " " << price << endl;
    }
    string getTitle() const
    {
        return name;
    }
    float getPrice() const
    {
        return price;
    }
    int getID() const
    {
        return bookID;
    }
};

class compareTitle
{
public:
    bool operator()(const Book b1, const Book b2) const
    {
        return b1.getTitle() < b2.getTitle();
    }
};

class compareID
{
public:
    bool operator()(const Book b1, const Book b2) const
    {
        return b1.getID() < b2.getID();
    }
};

class comparePrice
{
public:
    bool operator()(const Book &b1, const Book &b2) const
    {
        return b1.getPrice() < b2.getPrice();
    }
};

class desc
{
public:
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};
int main()
{
    set<int, desc> s1 = {12, 45, 67, 84, 7, 8, 3, 3, 12, 67};
    for (auto x : s1) // Always Sorted Order with unique values
        cout << x << " ";
    cout << endl;
    cout << endl;

    set<Book, compareID> s2;
    s2 =
        {

            *(new Book(1, "Atomic Habits", 120.30f)),
            *(new Book(2, "Java", 600.50f)),
            *(new Book(3, "CPP", 800.50f)),
            *(new Book(4, "Art of not overthinking", 1000.10f)),
            *(new Book(5, "Cloud Technologies", 700.90f)),
            *(new Book(6, "Data Structures", 650.00f))};

    s2.insert(*(new Book(1, "Crack Interview", 1200.00f))); // Duplicate Id will be discarded

    // Implicit Iterator
    for (auto x : s2)
    {
        x.showBook();
    }
    cout << endl;

    // Explicit Iterator
    set<Book, compareID>::iterator it;
    for (it = s2.begin(); it != s2.end(); it++)
        it->showBook(); // or (*it).showBook();
    cout << endl;

    cout << s2.empty() << endl;
    cout << s1.count(12) << endl; // Output is either 0 or 1
    s1.emplace(50);

    for (auto x : s1)
        cout << x << " ";
    cout << endl;

    s1.erase(++ ++s1.begin(), -- --s1.end()); // (Included, Excluded)

    for (auto x : s1)
        cout << x << " ";
    cout << endl;

    return 0;
}