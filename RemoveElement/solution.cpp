class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        // Traverse nums vector using iterator over index because index will change as elements of the vector are removed
        // find first occurence of val
        auto it = find(nums.begin(), nums.end(), val);
        while (it != nums.end())
        {
            nums.erase(it);

            // find next occurence of val
            it = find(nums.begin(), nums.end(), val);
        }

        // return the number of ints which are not equal to val (all ints in nums as others have been removed)
        return nums.size();
    }
};
