#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // Use hashmap to keep count of letters in both strings
        unordered_map<char, int> letterCount;

        if (s.length() != t.length())
            return false;

        for (int i=0; i<s.length(); i++)
        {
            letterCount[s.at(i)]++;
            letterCount[t.at(i)]--;
        }           

        // To be a valid anagram the letter counts in the hashmap should be all zeros if the count was the same in both strings
        for (const auto& [letter, count]: letterCount)
        {
            if (count != 0)
                return false;
        }

        return true;
    }
};
