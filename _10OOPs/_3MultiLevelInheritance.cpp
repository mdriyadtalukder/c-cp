#include <bits/stdc++.h>
using namespace std;
class Person
{
public:
    string name;
    int age;
};
class Student : public Person
{
public:
    int rollno;
};
class GradStudent : public Student
{
public:
    string researchArea;
    void info()
    {
        cout << name << endl;
        cout << age << endl;
        cout << rollno << endl;
        cout << researchArea << endl;
    }
};
int main()
{
    GradStudent g;
    g.name="tony";
    g.age=27;
    g.rollno=1235;
    g.researchArea="Deep learning";
    g.info();
}