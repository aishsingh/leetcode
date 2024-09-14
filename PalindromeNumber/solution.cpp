#include <unordered_map>

class Solution {
public:
    bool isPalindrome(int x) 
    {
        // convert int to string so it can be traversed easier
        string num = to_string(x);

        for (int i=0; i<num.length(); i++)
        {
            auto frontPtr   = num.begin() + i;
            auto backPtr    = num.end() -1 - i;

            if (*frontPtr != *backPtr)
            {
                return false;
            }
        }

        return true;
    }
};
