class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=0; j<nums.size(); j++)
            {
                // Cannot use same element twice 
                if (i == j)
                {
                    continue;
                }

                // Check sum
                if (nums.at(i) + nums.at(j) == target)
                {
                    return {i, j};
                }
            }   
        }

        // Should never reach here because one solution is guaranteed
        return {0, 0};
    }
};
