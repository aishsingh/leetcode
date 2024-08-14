class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int streak = 0;
        int maxStreak = 0;
        for (auto& i : nums)
        {
            if (i == 1)
            {
                streak++;

                if (streak > maxStreak)
                    maxStreak = streak;
            }
            else
            {
                streak = 0;
            }
        }

        return maxStreak;
    }
};
