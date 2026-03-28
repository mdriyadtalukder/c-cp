#include <bits/stdc++.h>
using namespace std;

class Person // abstract class
{

    virtual void info() = 0; // eta pure virtual function..jar vitor pure virtual function thke seitai abstract class
};
class Student : public Person
{
public:
    int rollno;
    void info()
    {
        cout << "Hello Child" << endl;
    }
};

int main()
{
    Student g;
    g.info();
}