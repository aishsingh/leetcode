class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int result = 0;    
        
        for (auto& i : nums)
        {
            /** 
             * XOR each integer element in the array
             *   Since every element will appear twice these integer values will cancel each other out 
             *   except for the element which only appears once as it will be the only exclusive value.
             */
            result ^= i; 
        }

        return result;
    }
};
