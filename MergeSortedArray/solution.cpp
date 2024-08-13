#include <bits/stdc++.h>  // needed for vector insert

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        int nums1ModifiedSize = m;

        for (int i=0; i<n; i++)
        {
            // Check if nums2(j) should be inserted at current position or later
            if (nums2.at(i) < nums1.at(j))
            {
                // nums2(j) should be inserted now
                nums1.insert(nums1.begin() + j, nums2.at(i));
                j++;
                nums1ModifiedSize++;
            }
            else if (nums2.at(i) >= nums1.at(j))
            {
                // nums2(j) should be inserted later, find where
                for (; j<n+m; j++)
                {
                    if (nums2.at(i) < nums1.at(j) ||                // insert now as the next num is higher
                       (nums1.at(j) == 0 && j>=nums1ModifiedSize))  // insert now if at the end of nums1
                    {
                        nums1.insert(nums1.begin() + j, nums2.at(i));
                        j++;
                        nums1ModifiedSize++;
                        break;
                    }
                }
            }
        }

        nums1.resize(nums1ModifiedSize);
    }
};
