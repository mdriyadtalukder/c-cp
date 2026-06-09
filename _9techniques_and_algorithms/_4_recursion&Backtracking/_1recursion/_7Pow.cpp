class Solution
{
public:
    double myPow(double x, int n)
    {
        long power = n;
        if (power < 0) // manage negative value
        {
            x = 1 / x;
            power = -power;
        }
        return helper(x, power);
    }
    double helper(double x, long n)
    {
        if (n == 0)
            return 1.0; //2^0=1
        double half = helper(x, n / 2); // use recursion find x^(n/2) then squre(value of n/2)--For 2^8:Find 2^4.Then square it → 2^8.This avoids repeated multiplication.
        if (n % 2 == 0)                 // for even
        {
            return half * half; // 2^8=(2^4)^2
        }
        else // for odd
        {
            return half * half * x; // 2^8=(2^4)^2*2
        }
    }
};