class Solution {
public:
    string removeVowels(string s) 
    {
        string result;

        // construct result string using all chars from s which are not vowels
        for (auto letter : s)
        {
            if (letter != 'a' && 
                letter != 'e' &&
                letter != 'i' &&
                letter != 'o' &&
                letter != 'u')
            {
                result.push_back(letter);
            }
        }

        return result;
    }
};
