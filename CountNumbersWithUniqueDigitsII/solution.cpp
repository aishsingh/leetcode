class Solution {
public:
    int numberCount(int a, int b) 
    {
        int uniqueDigitCount = 0;

        // Iterate over the requested range [a, b]
        for (int i=a; i<=b; i++)
        {
            // convert num to string to make it easier to traverse digits
            const string digits = to_string(i);
            
            // Check if all digits in the num were unique
            // Since a set will only keep unique digit we can use this behaviour for our check
            unordered_set<int> digitsSet (digits.begin(), digits.end());
            if (digitsSet.size() == digits.size())
            {
                // The size of the num and set is the same, this means all digits are unique
                uniqueDigitCount++;
            }
        }

        return uniqueDigitCount;
    }
};
