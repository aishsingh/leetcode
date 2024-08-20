class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // Use set to list to the unique types
        unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());
        
        // calc max candies Alice can eat
        const size_t docCandyLimit = candyType.size() / 2;
        
        return min(uniqueCandies.size(), docCandyLimit);
    }
};
