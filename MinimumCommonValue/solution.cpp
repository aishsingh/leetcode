class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        // two pointer approach to avoid nested for loop
        int i=0;
        int j=0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1.at(i) > nums2.at(j))
            {
                j++;
            }
            else if (nums1.at(i) < nums2.at(j))
            {
                i++;
            }
            else
            {
                // nums1[i] and nums2[j] are common
                return nums1.at(i);
            }
        }


        /* inefficient code:

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
        */

        // no common number found
        return -1;
    }
};
