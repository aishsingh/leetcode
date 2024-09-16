#include <unordered_map>

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
        vector<int> sneakyNums;

        // Use unordered map to keep count of nums
        unordered_map<int, int> countMap;
        for (auto num : nums)
        {
            countMap[num]++;

            // find sneaky nums based on count > 2
            if (countMap[num] > 1)
                sneakyNums.push_back(num);

            // Check if all sneaky nums found
            if (sneakyNums.size() >= 2)
                break;
        }

        return sneakyNums;
    }
};
