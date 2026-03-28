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
class Teacher : public Person
{
public:
    string subject;
};
int main()
{
    Teacher g;
    g.name = "tony";
    g.age = 27;
    g.subject = "CSE421";
}