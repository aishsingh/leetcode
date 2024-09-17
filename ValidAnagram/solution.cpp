#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // Use hashmap to keep count of letters in both strings
        unordered_map<char, int> letterCount;

        for (auto letter : s)
            letterCount[letter]++;

        for (auto letter : t)
            letterCount[letter]--;

        // To be a valid anagram the letter counts in the hashmap should be all zeros if the count was the same in both strings
        for (const auto& [letter, count]: letterCount)
        {
            if (count != 0)
                return false;
        }

        return true;
    }
};
