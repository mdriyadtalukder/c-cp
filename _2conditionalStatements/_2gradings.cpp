#include <iostream>
using namespace std;
int main(){
    int n=19;
    if(n>=33 && n<=40){
        cout<<"D";
    }
    else if(n>=41 && n<=50){
        cout<<"C";

    }
    else if(n>=51 && n<=60){
        cout<<"B";

    }
    else if(n>=61 && n<=69){
        cout<<"A-";

    }
    else if(n>=70 && n<=79){
        cout<<"A";

    }
    else if(n>=80 && n<=97){
        cout<<"A+";

    }
    else if(n>=98&& n<=100){
        cout<<"Golder A+";

    }
    else{
        cout<<"Fail!";
    }
}