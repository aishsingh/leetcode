class Solution {
public:
    int sumOfDigits(vector<int>& nums) 
    {
        int min = *min_element(nums.begin(), nums.end());

        // iterate over digits adding to sum
        int digitSum = 0;
        while (min > 0)
        {
            int digit = min % 10;
            digitSum += digit;

            // iterate to next digit
            min /= 10;
        }

        return (digitSum % 2 == 0);
    }
};
