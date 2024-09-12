#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        // Generate hashmap with counts of each num
        unordered_map<int, int> hashMap;
        for (int i : nums)
        {
            hashMap[i]++;
        }

        // Find num with biggest count
        int maxOccuringNum      = 0;
        int maxOccuringCount    = 0;
        for (auto [num, count] : hashMap)
        {
            if (count >= maxOccuringCount)
            {
                maxOccuringCount = count;
                maxOccuringNum = num;
            }
        }

        return maxOccuringNum;    
    }
};
