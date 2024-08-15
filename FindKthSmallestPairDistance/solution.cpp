// Inspired by https://leetcode.com/problems/find-k-th-smallest-pair-distance/solutions/5632765/o-n-log-n-n-log-w-binary-search-sliding-window-java-c-python-go-rust-javascript

#include <algorithm>

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int minDistance = 0;
        int maxDistance = nums.back() - nums.front();

        while (minDistance < maxDistance) {
            int midDistance = minDistance + (maxDistance - minDistance) / 2;
            if (countPairsWithinDistance(nums, midDistance) < k) {
                minDistance = midDistance + 1;
            } else {
                maxDistance = midDistance;
            }
        }
        
        return minDistance;
    }

    int countPairsWithinDistance(const std::vector<int>& numbers, int targetDistance) {
        int count = 0, left = 0;
        for (int right = 1; right < numbers.size(); ++right) {
            while (numbers[right] - numbers[left] > targetDistance) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};
