class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) 
    {
        vector<int> indicesWithX;

        for (int i=0; i<words.size(); i++)
        {
            if (words.at(i).find(x) != string::npos)
                indicesWithX.push_back(i);
        }

        return indicesWithX;
    }
};
