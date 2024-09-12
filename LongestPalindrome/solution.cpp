#include <unordered_map>

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hashMap;

        // find frequency of letters in string
        for (char& letter : s)
        {
            hashMap[letter]++;
        }

        // calc max number of letter which can be used in a palindrome
        int     maxPalindromeLength = 0;
        bool    middleLetterFound   = false;
        for (const auto& [letter, letterCount] : hashMap)
        {
            // for a palindrome letters must be in pairs so only use the even count of the same letter
            bool isLetterCountEven  = (letterCount % 2 == 0);
            maxPalindromeLength     += (isLetterCountEven) ? letterCount : letterCount-1;

            // if an single odd letter is avilable is can be used even for the middle of the palindrome
            if (!middleLetterFound && !isLetterCountEven)
            {
                middleLetterFound = true;
                maxPalindromeLength++;
            }
        }

        return maxPalindromeLength;
    }
};
