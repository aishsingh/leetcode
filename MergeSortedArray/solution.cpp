#include <bits/stdc++.h> // needed for vector insert

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;

        for (int i=0; i<n; i++)
        {
            // Check if nums2(j) should be inserted at current position or later
            if (nums2.at(i) < nums1.at(j))
            {
                // nums2(j) should be inserted now
                nums1.insert(nums1.begin() + j, nums2.at(i));
                j++;
            }
            else if (nums2.at(i) >= nums1.at(j))
            {
                // nums2(j) should be inserted later, find where
                for (; j<n+m; j++)
                {
                    if (nums2.at(i) < nums1.at(j) || nums1.at(j) == 0)
                    {
                        nums1.insert(nums1.begin() + j, nums2.at(i));
                        j++;
                        break;
                    }
                }
            }
        }

        nums1.resize(n+m);
    }
};
