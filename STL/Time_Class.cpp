#include <iostream>
using namespace std;

class Time
{
private:
    int hr, min, sec;

public:
    Time(int hr = 0, int min = 0, int sec = 0) : hr(hr), min(min), sec(sec) {}
    void setTime(int hr, int min, int sec)
    {
        this->hr = hr;
        this->min = min;
        this->sec = sec;
    }
    void showTime()
    {
        cout << hr << "hr " << min << "min " << sec << "sec";
    }
    friend bool operator<(Time, Time);
    friend ostream &operator<<(ostream &, Time);
    friend istream &operator>>(istream &, Time &);
};
ostream &operator<<(ostream &dout, Time T)
{
    dout << T.hr << " : " << T.min << " : " << T.sec;
    return dout;
}
istream &operator>>(istream &din, Time &T)
{
    din >> T.hr >> T.min >> T.sec;
    return din;
}
bool operator<(Time T1, Time T2)
{
    if (T1.hr < T2.hr)
        return true;
    else if (T1.hr > T2.hr)
        return false;
    else if (T1.min < T2.min)
        return true;
    else if (T1.min > T2.min)
        return false;
    else if (T1.sec < T2.sec)
        return true;
    else
        return false;
}

Time *createArray(int size)
{
    Time *ptr = new Time[size];
    return ptr;
    // return new Time[size];
}
void sortTimeArray(Time T[], int size)
{
    Time temp;
    for (int round = 1; round < 6; round++)
        for (int i = 0; i < 6 - round; i++)
            if (T[i] < T[i + 1])
            {
                temp = T[i];
                T[i] = T[i + 1];
                T[i + 1] = temp;
            }
}
/* int main()
{
    Time *T = createArray(6);
    for (int i = 0; i < 6; i++)
    {
        cout << "Enter Time " << i + 1 << "(hr min sec): ";
        cin >> T[i];
    }
    sortTimeArray(T, 6);
    cout << "Sorted Times:  \n";
    for (int i = 0; i < 6; i++)
        cout << T[i] << "\n";

    return 0;
} */