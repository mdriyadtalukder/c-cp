#include <iostream>
using namespace std;
main()
{
    int y;
    cout << "Write a year: ";
    cin >> y;
    if ((y % 4 == 0 && y % 100 != 0)||y%400==0){
        cout<<"Leap year";
    }
    else{
        cout<<"Not leap year";

    }
}