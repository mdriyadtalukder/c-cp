#include <iostream>
#include <cmath>    // Required for math functions
using namespace std;

int main() {
    double num = 9.0;
    double neg = -9.0;
    double dec = 4.7;

    // 1. Square root
    cout << "sqrt(" << num << ") = " << sqrt(num) << endl;  // 3

    // 2. Power
    cout << "pow(2, 3) = " << pow(2, 3) << endl;  // 8 = 2^3

    // 3. Absolute value
    cout << "abs(" << neg << ") = " << abs(neg) << endl;  // 9

    // 4. Round
    cout << "round(" << dec << ") = " << round(dec) << endl;  // 5

    // 5. Floor (largest integer <= number)
    cout << "floor(" << dec << ") = " << floor(dec) << endl;  // 4

    // 6. Ceil (smallest integer >= number)
    cout << "ceil(" << dec << ") = " << ceil(dec) << endl;  // 5

    // 7. Trigonometric functions (input in radians)
    double angle = 3.14159265 / 2; // 90 degrees
    cout << "sin(90°) = " << sin(angle) << endl;  // 1
    cout << "cos(90°) = " << cos(angle) << endl;  // ~0
    cout << "tan(45°) = " << tan(3.14159265 / 4) << endl;  // 1

    // 8. Logarithmic functions
    cout << "log(2.71828) = " << log(2.71828) << endl; // natural log ln(x)
    cout << "log10(100) = " << log10(100) << endl;      // log base 10

    // 9. Exponential
    cout << "exp(1) = " << exp(1) << endl;  // e^1

    // 10. Truncate
    cout << "trunc(" << dec << ") = " << trunc(dec) << endl; // 4

    // 11. fmod (remainder)
    cout << "fmod(10, 3) = " << fmod(10, 3) << endl; // 1

    // 12. Hypotenuse
    double a = 3, b = 4;
    cout << "hypot(" << a << ", " << b << ") = " << hypot(a, b) << endl; // 5

    return 0;
}
