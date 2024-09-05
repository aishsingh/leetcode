class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        vector<int> missingRolls;

        int currentSum  = accumulate(rolls.begin(), rolls.end(), 0);
        int targetSum   = mean * (rolls.size() + n);
        
        // Check if requested mean is possible with n missing rolls
        if (currentSum + (1*n) > targetSum)
        {
            // not possible, the intial sum is too large
            // even using the min roll achievable in n rolls
            return {};
        }
        else if (currentSum + (6*n) < targetSum)
        {
            // not possible, the intial sum is too low
            // even using the max roll achievable in n rolls
            return {};
        }

        int neededSum = targetSum - currentSum;

        // Calc each roll seperatly
        while (currentSum < targetSum)
        {
            int remainingN = n-missingRolls.size();
            int roll = 0;

            if (neededSum >= 6 && neededSum-6 >= remainingN-1)    // more then 6 needed and we have enough missing rolls to max out this roll 
            {
                roll = 6;
                missingRolls.push_back(roll);
            }
            else if (remainingN == 1)                       // last n, needed should be < 6 so set it must be the last roll 
            {
                roll = neededSum;
                missingRolls.push_back(roll);
            }
            else                                            // there are enough roll still missing and we are not at the last roll so this roll can be set to 1
            {
                roll = 1;
                missingRolls.push_back(roll);
            }
            
            currentSum += roll;
            targetSum   = mean * (rolls.size() + n);
            neededSum   = targetSum - currentSum;
        }

        return missingRolls;
    }
};
