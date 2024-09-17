#include <unordered_map>

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        // Fill map with all words
        unordered_map<string, int> wordCountMap;
        fillMapWithWords(wordCountMap, s1);
        fillMapWithWords(wordCountMap, s2);       

        // Fill vector with uncommon words
        vector<string> uncommonWords;
        for (auto& [word, count] : wordCountMap)
        {
            if (count == 1)
            {
                // word is uncommon as it only appeared once in both sentences
                uncommonWords.push_back(word);
            }
        }

        return uncommonWords;
    }

    void fillMapWithWords(unordered_map<string, int>& wordCountMap, string sentence)
    {
        string word;
        for (int i=0; i<sentence.length(); i++)
        {
            bool lastLetter = (i == sentence.length()-1);
            
            if (sentence.at(i) == ' ' || lastLetter)
            {
                // reached end of word/sentence
                if (lastLetter)
                {
                    word.push_back(sentence.at(i));
                }

                // add word to map
                wordCountMap[word]++;
                word.clear();
            }
            else
            {
                // continue building next word
                word.push_back(sentence.at(i));
            }
        }
    }
};
