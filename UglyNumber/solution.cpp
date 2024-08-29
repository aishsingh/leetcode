class Solution {
public:
    bool isUgly(int n) 
    {
        if (n <= 0)
        {
            // ugly numbers cant be negative
            return false;
        }

        // when a prime factor of 2 n will be reduced to 1
        while (n % 2 == 0)
        {
            n /= 2;
        }

        // when a prime factor of 2 n will be reduced to 3
        while (n % 3 == 0)
        {
            n /= 3;
        }

        // when a prime factor of 2 n will be reduced to 5
        while (n % 5 == 0)
        {
            n /= 5;
        }

        if (n == 1)
        {
            // n was divisable by 2, 3 or 5 with no remainders so it is an ugly number
            return true;
        }

        return false;
    }
};
