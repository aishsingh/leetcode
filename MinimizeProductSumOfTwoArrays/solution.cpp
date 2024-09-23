class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) 
    {
        // sort both vectors in differing orders so the biggest values dont multiply with each other
        sort(nums1.begin(), nums1.end());   // sort accending order
        sort(nums2.rbegin(), nums2.rend()); // sort descending order

        // Calc dot product sum
        int sum = 0;
        for (int i=0; i<nums1.size(); i++)
        {
            sum += nums1[i] * nums2[i];
        }

        return sum;
    }
};
