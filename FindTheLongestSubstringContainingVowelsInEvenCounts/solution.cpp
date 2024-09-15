#include <unordered_map>

class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        int longestSubstring = 0;

        unordered_map<char, int> vowelMap = { 
            {'a', 1 << 0},
            {'e', 1 << 1},
            {'i', 1 << 2},
            {'o', 1 << 3},
            {'u', 1 << 4}
        };
                                              
        int xorPrefix = 0;
        const int maxXorPrefix = pow(2, vowelMap.size());

        // Store index of previously calculated xorPrefix value
        vector<int> xorPrefixIndex(maxXorPrefix, -1);

        for (int i=0; i<s.size(); i++)
        {
            // If the current character is a vowel, find it's prefix XOR and add it in the vector.
            xorPrefix ^= vowelMap[s.at(i)];
            if (xorPrefixIndex.at(xorPrefix) == -1 && xorPrefix != 0)
            {
                xorPrefixIndex.at(xorPrefix) = i;
            }

            // If the value of prefixXOR exists in the vector, find the longest subarray
            longestSubstring = max(longestSubstring, i - xorPrefixIndex.at(xorPrefix));
        }

        return longestSubstring;
    }
};
