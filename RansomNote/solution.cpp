#include <unordered_map>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // Count letters in ransom note
        unordered_map<char, int> noteMap;
        for (auto letter : ransomNote)
            noteMap[letter]++;

        // Count letters in magazine
        unordered_map<char, int> magazineMap;
        for (auto letter : magazine)
            magazineMap[letter]++;

        // Check if letters in the ransom note are avilable in the magazine
        for (const auto& [letter, count] : noteMap)
        {
            if (noteMap[letter] > magazineMap[letter])
            {
                // There are more letters used in the ransom note then what is available in the magazine
                // This note cannot be made from this magazine
                return false;
            }
        }

        // If we reached here then all letters in the ransom note could be used from the magazine
        return true;
    }
};
