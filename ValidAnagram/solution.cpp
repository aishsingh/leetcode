#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // Use hashmap to keep count of letters in both strings
        unordered_map<char, int> s1LetterCount;
        unordered_map<char, int> s2LetterCount;

        for (auto letter : s)
            s1LetterCount[letter]++;

        for (auto letter : t)
            s2LetterCount[letter]++;

        // The letter counts in each hashmap should match for the strings to be a valid anagram
        return (s1LetterCount == s2LetterCount);
    }
};
