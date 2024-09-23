class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for (int i=0; i<nums.size(); i++)
        {
            int curNum      = nums.at(i);
            int neededNum   = target - curNum;

            // check if needed value exists already in the hashmap
            // return the indices of both value if it does
            if (hashmap.count(neededNum) != 0)
                return {i, hashmap[neededNum]};

            // add current value mapped to current index to hashmap sp it can be queried later
            hashmap[curNum] = i;
        }

        // Should never reach here because one solution is guaranteed
        return {0, 0};
    }
};
