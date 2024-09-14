class Solution {
public:
    bool isPalindrome(int x) 
    {
        // Negative value are not palindromes
        if (x < 0) return false;

        // iterate over digits to form reversed num
        long long reversed = 0;
        int tmp = x;
        while (tmp > 0)
        {
            int digit = tmp % 10;

            reversed *= 10;
            reversed += digit;

            // bit shift to iterate to next digit
            tmp /= 10;
        }

        return (reversed == x);
    }
};
