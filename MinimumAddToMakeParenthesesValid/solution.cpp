class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int openBracketsNeeded = 0;
        int closeBracketsNeeded = 0;

        for (const auto& letter : s)
        {
            if (letter == '(')
            {
                closeBracketsNeeded++;
            }
            else if (letter == ')')
            {
                // if this close bracket was needed then decrement the close bracket count, 
                // if this close bracket was not needed then an extra open bracket is now needed to make up for it
                if (closeBracketsNeeded > 0)
                    closeBracketsNeeded--;
                else
                    openBracketsNeeded++;
            }
        }

        return closeBracketsNeeded + openBracketsNeeded;
    }
};
