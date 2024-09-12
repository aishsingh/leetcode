class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        // If an element repeats more then n/2 times then the element at index n/2 is 
        // guaranteed to be equal to this value when the nums list is sorted
        sort(nums.begin(), nums.end());

        int majElement = nums.at(nums.size()/2);
        return majElement;    
    }
};
