class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix;

        // Sort vector of strings
        sort(strs.begin(), strs.end());

        // Compare first and last strings in the sorted vector
        string startStr = strs.front();
        string endStr   = strs.back();

        for (int i=0; i < startStr.size() && i < endStr.size(); i++)
        {
            if (startStr.at(i) == endStr.at(i))
            {
                prefix.append(1, startStr.at(i));
            }
            else
            {
                // chars do not match anymore to be a prefex end comparisons
                break;
            }
        }

        return prefix;
    }
};
