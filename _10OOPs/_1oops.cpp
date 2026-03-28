#include <bits/stdc++.h>
using namespace std;
class Teacher
{
    // properties/attributes
private:
    double salary;

public:
    string name;
    string dept;
    string subject;
    // double salary;

    // non parameterized constructor
    Teacher()
    {
        dept = "Computer Science";
    }
    // parameterized constructor
    Teacher(string name, string dept, string subject, double salary)
    {
        this->name = name; // this->name means object er name ta r sudu name ta holo parameter..
        (*this).dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // copy constructor
    Teacher(Teacher &org0bj) // na banaleo automatically baniye nibe c++;
    {
        this->name = org0bj.name;
        this->dept = org0bj.dept;
        this->subject = org0bj.subject;
        this->salary = org0bj.salary;
    }
    // Student(Student &obj) ///deep kbe..heap e holeo problem hbe na..but shallaw copy te hy..
    // {
    //     this->name = obj.name;
    //     cgpaPtr = new double; //for double *cgpaPtr;
    //     *cgpaPtr = *obj.cgpaPtr; //cout<<*cgpaPtr// /cout<<*obj.cgpaPtr
    // }

    // destructor for dynamic allowcation
    // ~Student()
    // {
    //     cout << "Hi, I delete everything\n";
    //     delete cgpaptr;
    // }

    // methods/member functions
    void changeDept(string newDept)
    {
        dept = newDept;
    }
    // setter
    void setSalary(double s)
    { // private property er value change kora
        salary = s;
    }
    // getter
    double getSalary()
    { // private property er value paoya..
        return salary;
    }
};
int main()
{

    Teacher t1; // call constructor
    // Teacher t2;
    // Teacher t3;
    // Teacher t1("Riyad", "ComputerScience", "C++", 25000);
    // Teacher t9(t1);//copy constructor..
    t1.name = "Riyad";
    t1.subject = "C++";
    // t1.dept = "Computer Science";
    //  t1.salary = 25000;
    t1.setSalary(30000);
    cout << t1.dept << endl;
    cout << t1.getSalary() << endl;
    return 0;
}