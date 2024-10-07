class Solution {
public:
    int minLength(string s) 
    {
        auto ABPos = s.find("AB");
        auto CDPos = s.find("CD");

        while (ABPos != string::npos || CDPos != string::npos)
        {
            // erase either substrings one at a time
            if (ABPos != string::npos)
            {
                s.erase(ABPos, 2);
            }
            else if (CDPos != string::npos)
            {
                s.erase(CDPos, 2);
            }

            // update positions
            ABPos = s.find("AB");
            CDPos = s.find("CD");
        }

        return s.length();
    }
};
