/** 
 * This Leetcode editorial was really helpful in coming up with a viable solution
 * https://leetcode.com/problems/group-anagrams/editorial
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // Use an unordered map to store anagrams as they can be referenced by the key easily
        unordered_map<string, vector<string>> anagrams;
        for (auto& str : strs)
        {
            // sort each string as all anagrams will have the same sorted string
            // this sorted string can be used as a key to group the anagrams
            string key = str;
            sort(key.begin(), key.end());

            // add current str to its anagram group
            anagrams[key].push_back(str);
        }

        // Add anagrams to resulting vector
        vector<vector<string>> result;
        for (const auto& [key, strs] : anagrams)
        {
            result.push_back(strs);
        }

        return result;
    }
};
