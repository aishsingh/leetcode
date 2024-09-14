#include <algorithm>

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int     maxNum                  = *max_element(nums.begin(), nums.end());
        int     maxNumCount             = 0;

        // These vars are used to track of subarrays which have not yet reached a higher count then maxNumCount
        bool    maxNumStillContinious   = true;
        int     possibleMaxNumCount     = 0;

        // Iterate over nums keeping track of the count of continious nums which are of the max val
        for (const auto num : nums)
        {
            if (num == maxNum)
            {
                if (maxNumStillContinious)
                {
                    maxNumCount++;
                }
                else
                {
                    possibleMaxNumCount++;

                    if (possibleMaxNumCount > maxNumCount)
                    {
                        // current subarray has a higher count of max val nums then the prev sub array so set current subarray as max
                        maxNumCount = possibleMaxNumCount;
                        maxNumStillContinious = true;
                        possibleMaxNumCount = 0;
                    }
                }
            }
            else if (num < maxNum)
            {
                maxNumStillContinious = false;
                possibleMaxNumCount = 0;
            }
        }

        return maxNumCount;
    }
};
