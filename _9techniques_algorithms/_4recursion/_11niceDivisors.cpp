#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7; // a large prime number.to handle big number

// Fast exponentiation: b^x % mod
long long power(long long b, long long x)
{
    if (x == 0)
        return 1;
    long long ans = power(b, x / 2);
    ans = (ans * ans) % mod;
    if (x % 2)
        ans = (ans * b) % mod;
    return ans;
}

int main()
{
    int n = 5;
    if (n == 1)
        return 1;

    long long ans;
    if (n % 3 == 0)
    {
        ans = power(3, n / 3); // All 3s
    }
    else if (n % 3 == 1)
    {
        ans = (4 * power(3, n / 3 - 1)) % mod; // One 4 + rest 3s
    }
    else
    {                                      // n % 3 == 2
        ans = (2 * power(3, n / 3)) % mod; // One 2 + rest 3s
    }
    cout << ans;
}

/*
n=7---[2,2,3]-.all prime numbers-so---2² × 3¹---base=2*1=2..so nice divisors=2;

Suppose the prime factorization of n is 2² × 3¹ (i.e., [2, 2, 3]).
Then the nice divisors are all numbers of the form 2^a * 3^b where:

1 ≤ a ≤ 2   (exponent of 2 in n)
1 ≤ b ≤ 1   (exponent of 3 in n)


Every such number automatically divides n, so n % (2^a * 3^b) == 0.

*/
/*
Case 1: n = 6 (n % 3 == 0)
Step 1: Choose exponents

n % 3 == 0 → all 3s

Split: 3 + 3 = 6

Product = 3^2 → call power(3, 2)

Step 2: Dry run power(3,2)
power(3,2):
x = 2
ans = power(3, 1)   // recursive call

  power(3,1):
  x = 1
  ans = power(3,0)  // recursive call

    power(3,0):
    x = 0 → return 1

  ans = 1
  ans = (1*1) % mod = 1
  x % 2 == 1 → ans = (1*3) % mod = 3
  return 3

ans = 3
ans = (3*3) % mod = 9
x % 2 == 0 → no extra multiply
return 9


✅ So power(3,2) = 9

Answer: 9 nice divisors.

Case 2: n = 7 (n % 3 == 1)
Step 1: Choose exponents

n % 3 == 1 → one 4 + rest 3s

Split: 4 + 3 = 7 → product = 4 × 3^1

Call power(3, 7/3 - 1) = power(3, 1)

Multiply by 4 → 4 * power(3,1)

Step 2: Dry run power(3,1)
power(3,1):
x = 1
ans = power(3,0) → return 1
ans = (1*1) % mod = 1
x % 2 == 1 → ans = (1*3) % mod = 3
return 3

Step 3: Multiply by 4
ans = (4 * 3) % mod = 12


✅ So maximum nice divisors = 12

Case 3: n = 5 (n % 3 == 2)
Step 1: Choose exponents

n % 3 == 2 → one 2 + rest 3s

Split: 2 + 3 = 5 → product = 2 × 3^1

Call power(3, n/3) = power(3, 1)

Multiply by 2 → 2 * power(3,1)

Step 2: Dry run power(3,1)
power(3,1):
x = 1
ans = power(3,0) → 1
ans = 1*1 % mod = 1
x % 2 == 1 → ans = 1*3 % mod = 3
return 3

Step 3: Multiply by 2
ans = 2 * 3 = 6


✅ So maximum nice divisors = 6

Summary Table
n	n%3	Exponent split	Power call	Multiply extra	Nice divisors
6	0	3 + 3	3^2 = 9	none	9
7	1	4 + 3	3^1 = 3	4 × 3	12
5	2	2 + 3	3^1 = 3	2 × 3	6
*/