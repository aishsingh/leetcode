#include <unordered_map>

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) 
    {
        // use hashmap to efficiently keep count of each word in both lists
        unordered_map<string, int> hashmap;
        for (const auto& word : message)
        {
            hashmap[word]++;
        }

        // keep banned words in a set so there are no duplicates
        set<string> bannedSet;
        for (const auto& word : bannedWords)
            bannedSet.insert(word);

        // check the count of the hashmap words against the banned words
        int totalBannedWordsFound = 0;
        for (const auto& word : bannedSet)
        {
            int bannedWordCount = hashmap[word];
            if (bannedWordCount > 0)
            {
                totalBannedWordsFound += bannedWordCount;

                if (totalBannedWordsFound >= 2)
                {
                    // the message meets the critera to be considered spam
                    return true;
                }
            }
        }
        
        // if we reached here then then there were not enough baned words to be considered spam
        return false;
    }
};
