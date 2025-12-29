#include <iostream>
using namespace std;
int main(){
    char l='I';
    if(l>='a' && l<='z'){
        cout<<"Small";
    }
    else if(l>='A' && l<='Z'){
        cout<<"Capital";

    }
    else{
        cout<<"Invalid!";
    }
}