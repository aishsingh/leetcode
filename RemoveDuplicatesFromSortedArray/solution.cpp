class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int prevNum = 0;
        for (int i=0; i<nums.size(); i++)
        {
            int num = nums.at(i);

            if (i > 0 && num == prevNum)
            {
                // duplicate found
                nums.erase(nums.begin() + i);

                // adjust index to account for element decrease
                i--;
            }

            prevNum = num;
        }
        
        return nums.size();
    }
};
