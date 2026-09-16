#include <iostream>
#include <sstream>
using namespace std;
// binary to hexa
int main()
{
    string binary = "10101111";

    int decimal = stoi(binary, nullptr, 2);

    stringstream ss;
    ss << uppercase << hex << decimal;

    cout << ss.str();

    return 0;
}