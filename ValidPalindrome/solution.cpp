class Solution {
public:
    bool isPalindrome(string s) 
    {
        // Comparing front and back chars and increment closer to the middle
        int start   = 0;
        int end     = s.size() - 1;
        while (start <= end)
        {
            char startChar  = s.at(start);
            char endChar    = s.at(end);

            // Skip non alpha-numeric chars
            if (!isalnum(startChar))
            {
                start++;
                continue;
            }
            if (!isalnum(endChar))
            {
                end--;
                continue;
            }

            if (tolower(startChar) != tolower(endChar))
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }

        return true;
    }
};
