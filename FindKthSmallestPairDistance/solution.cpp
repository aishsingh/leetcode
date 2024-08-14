#include <algorithm>

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> distancePairs;
      
        // Find all distance pairs 
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                int distance = abs(nums.at(i) - nums.at(j));

                distancePairs.push_back(distance);
            }
        }

        // Sort pairs
        if (distancePairs.size() > 1)
           sort(distancePairs.begin(), distancePairs.end());

        // Find k^th smallest distance pair
        return distancePairs.at(k-1);
    }
};
