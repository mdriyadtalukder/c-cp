#include <bits/stdc++.h>
using namespace std;
class Person
{
public:
    string name;
    int age;
    Person(string name, int age)
    {
        this->name = name;

        this->age = age;
    }
    Person()
    {
        cout << "Parent" << endl;
    }
};
class Student : public Person // age and name inherent hyse..private lekhle student er vitor eshe name and age private hoto.
{
public:
    int roll;
    Student(string name, int age, int roll) : Person(name, age) // parameter constructor eivbe hy..age parent call hbe then eita..
    {
        this->roll = roll;
    }
    Student()
    {
        cout << "Student" << endl; // age parent constructor call hbe then  child ta.and destructor call hy age child te then parent.
    }
    void getInfo()
    {
        cout << name << endl;
        cout << age << endl;
        cout << roll << endl;
    }
    // name, age, rollno
};
int main()
{
    Student s1;
    s1.age = 15;
    s1.name = "Riyad";
    s1.roll = 1234;
    s1.getInfo();
}