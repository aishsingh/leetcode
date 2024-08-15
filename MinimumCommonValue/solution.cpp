class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int i=0; i<nums1.size(); i++)
        {
            for (int j=0; j<nums2.size(); j++)
            {
                if (nums1.at(i) == nums2.at(j))
                {
                    return nums1.at(i);
                }
            }
        }

        // no common number found
        return -1;
    }
};
