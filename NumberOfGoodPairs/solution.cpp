class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int goodPairsCount = 0;

        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i; j<nums.size(); j++)
            {
                if (nums.at(i) == nums.at(j) && i < j)
                {
                    goodPairsCount++;
                }
            }
        }

        return goodPairsCount;
    }
};
