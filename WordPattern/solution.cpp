class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;

        // iterate over chars in string
        string parsingWord;
        for (int i=0; i<=s.length(); i++)
        {
            if (i == s.length() || s.at(i) == ' ')
            {
                // word finished
                words.push_back(parsingWord);

                // clear for building next word
                if (i != s.length())
                    parsingWord.clear();
            }
            else
            {
                // build word
                parsingWord.push_back(s.at(i));
            }
        }

        // edge case check
        if (words.size() != pattern.length())
            return false;


        // Use set to keep track of the words which have been assigned at pattern already
        set<string> wordSet;
        // Use unordered map to track which pattern char is assigned to each word
        unordered_map<char, string> patternMap;

        for (int i=0; i<pattern.size(); i++)
        {
            string &word = words.at(i);
            char &pat = pattern.at(i);

            // Pattern already exists already
            if (patternMap.count(pat) != 0)
            {
                // check if word is the same for this pattern as it was last time
                if (patternMap[pat] != word)
                {
                    // Not the expected word for this pattern
                    return false;
                }
            }
            else
            {
                // New pattern
                // it is expected that the word should be new too
                if (wordSet.find(word) != wordSet.end())
                {
                    // value was assigned before so that means it must be assigned for another pattern
                    return false;
                }

                // map new word to new pattern
                patternMap[pat] = word;

                // add word to wordSet to track it as assigned
                wordSet.insert(word);
            }
        }   

        return true; 
    }
};
