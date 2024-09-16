class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> shuffled(n*2);

        for (int i=0; i<nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                // x
                shuffled.at(i) = nums.at(i/2);
            }
            else
            {
                // y
                shuffled.at(i) = nums.at((i/2)+n);
            }
        }

        return shuffled;
    }
};
