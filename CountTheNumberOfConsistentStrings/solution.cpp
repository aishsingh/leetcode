#include <algorithm>    //std::count()

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int consistentWordsCount = 0;

        // iterate over each word in word list checking if it is consistent
        for (auto& word : words)
        {
            // Calc number of allowed chars in current word
            int allowedCharsInWord = 0;
            for (char& c : allowed)
            {
                allowedCharsInWord += count(word.begin(), word.end(), c);
            }

            if (allowedCharsInWord == word.size())
            {
                // word is consistent because the only chars in it are allowed
                consistentWordsCount++;
            }
        }    

        return consistentWordsCount;
    }
};
