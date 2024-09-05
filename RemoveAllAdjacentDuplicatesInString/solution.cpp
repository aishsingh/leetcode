class Solution {
public:
    string removeDuplicates(string s) 
    {
        string result;

        // loop through each char in string
        for (int i=0; i<s.size(); i++)
        {
            // Use result string as a stack to compare adjacent chars, adding it a char when it does not match the last char in the stack 
            // and then removing the char when it does match. This was only the chars which are not adjacently duplicates remain in the string.
            if (result.empty() || s.at(i) != result.back())
            {
                result.push_back(s.at(i));
            }
            else
            {
                result.pop_back();
            }
        }

        return result;
    }
};
