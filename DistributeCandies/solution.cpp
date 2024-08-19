#include <algorithm>    // std::min

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueCandies;
        
        // loop through all candies list to find unique types
        for (int i=0; i<candyType.size(); i++)
        {
            if (uniqueCandies.count(candyType.at(i)) == 0)
            {
                // New candy type found
                uniqueCandies.insert(candyType.at(i));
            }
        }
        
        // calc max candies Alice can eat
        const size_t docCandyLimit = candyType.size() / 2;
        
        return min(uniqueCandies.size(), docCandyLimit);
    }
};
