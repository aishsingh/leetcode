#include <unordered_map>

class Solution {
public:

    /**
     *  Possible palindrome edge cases:
     *    1. aba
     *    2. aaa
     *    3. a
     *    4. abccba
     *    5. ababa
     *  In each of these cases a pallindrom is possible of all letters occur an even number of times or if only one odd number count letter is present
     *  We will use this rule to determine if a palindrome is possible
     */
    bool canPermutePalindrome(string s) 
    {
        // Use hashmap tp keep count of letter frequency in s
        unordered_map<char, int> hashMap;
        for (const auto& letter : s)
        {
            hashMap[letter]++;
        }

        bool oddNumberFound = false;
        for (const auto& [letter, count] : hashMap)
        {
            if (count % 2 != 0)
            {
                if (!oddNumberFound)
                {
                    oddNumberFound = true;
                }
                else
                {
                    // More then one odd number of letters
                    // This means a palindrome is NOT possible
                    return false;
                }   
            }
        }

        // An even count of letters or only one letter with an odd number count was found
        // This means a palindrome is possible
        return true;    
    }
};
