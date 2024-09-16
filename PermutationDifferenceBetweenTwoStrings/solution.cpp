class Solution {
public:
    int findPermutationDifference(string s, string t) 
    {
        int sum = 0;

        // compare each char in both strings
        for (int i=0; i<s.size(); i++)
        {
            for (int j=0; j<t.size(); j++)
            {
                if (s.at(i) == t.at(j))
                {
                    // chars match, calc the abs diff between indexes and add to sum
                    sum += abs(i - j);
                }
            }
        }

        return sum;
    }
};
