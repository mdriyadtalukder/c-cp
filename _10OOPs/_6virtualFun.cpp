#include <bits/stdc++.h>
using namespace std;
class Person
{
public:
    string name;
    int age;
    virtual void info()
    {
        cout << "Hello P" << endl;
    }
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
    g.name = "tony";
    g.age = 27;
    g.info();
}