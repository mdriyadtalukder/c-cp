#include <iostream>
#include <conio.h>
#include <iomanip> //Used for output formatting (setw, setprecision, fixed, showpoint)
using namespace std;
main()
{
    int a=3;
    char names[6] = "Riyad"; // 1 ta besi dite hy ..jmn 6

    float n, n1;
    cout << "Enter 2 numbers: ";
    cin >> n >> n1;

    cout << showpoint;
    // cout << setprecision(10); //whole number will be displayed in 10 digit
    cout << fixed;
    cout << setprecision(3); // after decimal number will be displayed in 3 digit
    cout << setw(18) << "Addition: " << n + n1 << endl; //setw(18) takes width of 18 letters..it manages alignment of sentense..
    cout << setw(18) << "Subtraction: " << n - n1 << endl;

    cout << noshowpoint;
    cout << setw(18) << "multiplication: " << n * n1 << endl;
    cout << setw(18) << "Divition: " << n / n1 << endl;
    // cout << "Reminder: " << n % n1 << endl;



     cout << "My name is = " <<a <<" " << names << endl;
cout << "My name is = " << a << "\n" << names << endl;
cout << "My name is = " << a << endl << names << endl;
}

/*
2️⃣ fixed
What it does

👉 Shows numbers in fixed decimal format
👉 Works together with setprecision()

Example
float x = 3.141592;
cout << fixed << setprecision(2) << x;

Output
3.14


❌ Without fixed:

cout << setprecision(2) << x;


Output:
3.1

3️⃣ noshowpoint
What it does

👉 Turns OFF showpoint

Example
float x = 5;
cout << showpoint << x << endl;
cout << noshowpoint << x;

Output
5.00000
5

*/