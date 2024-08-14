class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Expected sum can be calculated based on the size of nums vector
        int expectedSum = 0;
        for (int i=1; i<=nums.size(); i++)
        {
            expectedSum += i;
        }

        int actualSum = accumulate(nums.begin(), nums.end(), 0);

        return expectedSum - actualSum;
    }
};
