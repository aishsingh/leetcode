class Solution {
public:
    vector<int> orArray(vector<int>& nums) 
    {
        vector<int> answer(nums.size()-1);

        for (int i=0; i<nums.size()-1; i++)
        {
            int bitwiseOr = nums.at(i) | nums.at(i+1);
            answer.at(i) = bitwiseOr;
        }

        return answer;
    }
};
