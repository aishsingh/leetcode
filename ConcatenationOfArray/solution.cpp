class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        // Initialise ans vector so `ans[i] == nums[i]`
        vector<int> ans(nums.begin(), nums.end());

        // Insert nums again so `ans[i + n] == nums[i]`
        ans.insert(ans.end(), nums.begin(), nums.end());

        return ans;
    }
};
