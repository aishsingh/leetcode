#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        // This vector will contain the letter pattern which needs to be 
        // common between both strings s and t for them to be isomorphic
        vector<int> letterPattern;

        // Use hashmap to map letters in string s to unique letterIds
        // Iterate over letters in string s building the letter pattern
        unordered_map<char, int> hashmapS;
        int maxLetterId = 0;
        for (int i=0; i<s.length(); i++)
        {
            char letter = s.at(i);

            // check if new letter
            if (hashmapS.count(letter) == 0)
                hashmapS[letter] = ++maxLetterId;

            letterPattern.push_back(hashmapS[letter]);
        }

        // Perform a similar loop as before but now iterating over string t
        // Use a seperate hashmap for string t to map letters to letterIds
        unordered_map<char, int> hashmapT;
        maxLetterId = 0;
        for (int i=0; i<t.length(); i++)
        {
            char letter = t.at(i);

            // check if new letter
            if (hashmapT.count(letter) == 0)
                hashmapT[letter] = ++maxLetterId;

            // Here we compare the letterId we got for the current position in string t and string s before
            if (hashmapT[letter] != letterPattern.at(i))
            {
                // The letterIds are not the same so the letter pattern is different 
                // Strings s and t are not isomorphic
                return false;
            }
        }

        // If we reached here then the letter pattern generated for both string match meansing they are isomorphic
        return true;
    }
};
