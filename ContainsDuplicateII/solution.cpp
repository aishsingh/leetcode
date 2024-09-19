#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        // Store indices with the keys are their values
        unordered_map<int, int> hashmap;

        for (int i=0; i<nums.size(); i++)
        {
            // Check if the current value was added before
            if (hashmap.count(nums.at(i)))
            {
                // The current value is a duplicate
                // Check if the current index and past index are within k appart
                if (i - hashmap[nums.at(i)] <= k)
                {
                    return true;
                }
            }

            // Add new index and value to hashmap
            hashmap[nums.at(i)] = i;
        }   

        // No duplicates were within k if we reached here
        return false; 
    }
};
