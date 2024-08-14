class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;

        for (int i=0; i<word1.size()+word2.size(); i++)
        {
            if (i < word1.size())
            {
                result.push_back(word1.at(i));
            }
            if (i < word2.size())
            {
                result.push_back(word2.at(i));
            }
        }

        return result;
    }
};
