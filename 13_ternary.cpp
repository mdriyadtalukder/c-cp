#include <iostream>
#include <cstring>
using namespace std;
main()
{
    int a = 40;
    int b = 20;
    // (a > b) ? cout << "ABig" : cout << "BBig";
    // string ab = (a > b) ? "abig":"bbig";
    //char ab[5] = (a > b) ? "abig" : "bbig"; it got error
    
    char ab[5]; 
    (a > b) ? strcpy(ab, "abig") : strcpy(ab, "bbig");
    cout << ab;
}