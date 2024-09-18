class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        // convert nums to string ahead here once as they are needed as  later to compare later as strings and append
        // converting here saves time converting multiple times in the sorting fn
        vector<string> numsStr;
        for (int num : nums) {
            numsStr.push_back(to_string(num));
        }

        // use the exisiting sort algorithm with the modified condition fn below
        sort(numsStr.begin(), numsStr.end(), [ ](const auto& num1, const auto& num2)
        {
            // return true if num1 is "greater"
            return ((num1 + num2) > (num2 + num1));
        });

        // if 0 is considered the greatest num out of any potential other nums return 0 so no other chars are returned
        if (numsStr.front() == "0")
            return "0";

        // form result string
        string largestNum;
        for (const auto& num : numsStr)
        {
            largestNum.append(num);
        }

        return largestNum;
    }
};
