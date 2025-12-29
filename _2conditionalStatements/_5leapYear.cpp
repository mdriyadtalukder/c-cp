#include <iostream>
using namespace std;
int main(){
    int y=2016;
    if(y%400==0 || (y%4==0 && y%100!=0)){
        cout<<"Leap Year";
    }
    else{
        cout<<"Not leap year";
    }
}