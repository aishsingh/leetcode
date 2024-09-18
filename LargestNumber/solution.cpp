class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        string largestNum;

        // use the exisiting sort algorithm with the modified condition fn below
        sort(nums.begin(), nums.end(), [ ](const int& num1, const int& num2)
        {
            // return true if combo1 with num1 is "greater"

            string combo1 = to_string(num1) + to_string(num2);
            string combo2 = to_string(num2) + to_string(num1);

            return (combo1 > combo2);
        });

        // if 0 is considered the greatest num out of any potential other nums return 0 so no other chars are returned
        if (nums.front() == 0)
            return "0";

        // form result string
        for (const auto& num : nums)
        {
            largestNum.append(to_string(num));
        }

        return largestNum;
    }
};
