#include <numeric>

class Solution {
public:
    int getLucky(string s, int k) 
    {
        vector<int> digits;

        // Convert
        for (int i=0; i<s.size(); i++)
        {
            int pos = posOfAlphabet(s.at(i));
            if (pos < 9)
            {
                digits.push_back(pos);
            }
            else
            {
                // Position can be between 1-26 so the digits need to be seperated
                int digit1 = pos % 10;
                int digit2 = pos / 10;

                digits.push_back(digit1);
                digits.push_back(digit2);
            }
        }

        // Transform k times
        int sum = accumulate(digits.begin(), digits.end(), 0);
        for (int i=1; i<k; i++)
            sum = sumDigits(sum);

        return sum;
    }

    int posOfAlphabet(char alphabet)
    {
        // calc pos based on ascii
        int pos = alphabet - ('a' - 1); // -1 as letters start with a=1

        return pos;
    }

    int sumDigits(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            int digit = num % 10;
            sum += digit;
            num /=10;
        }

        return sum;
    }
};
