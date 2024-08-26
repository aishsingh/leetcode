#include <unordered_map>

class Solution {
public:
    int romanToInt(string s) 
    {
        // Create hash map for quick roman to value conversions
        unordered_map<char, int> map = 
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int sum = 0;

        // Iterate over each roman numeral converting to decimal values and adding to the sum
        for (int i=0; i<s.size(); i++)
        {
            bool    isLastCharInStr = (i == s.size()-1);

            // if last char in string there is no next value so set equal to current value to skip to the usual use case 
            int     currentValue    = map.at(s.at(i));
            int     nextValue       = (!isLastCharInStr) ? map.at(s.at(i+1)) : currentValue;   

            if (currentValue < nextValue)
            {
                // One of the six instances where subtraction is needed for roman to value conversion
                sum -= currentValue;
            }
            else
            {
                // Usual use case where roman numerals are written largest to smallest
                sum += currentValue;
            }
        }
        
        return sum;
    }
};
