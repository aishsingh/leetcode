class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int student = 0;

        // Handle edge case where there is only one student present
        if (chalk.size() <= 1)
            return student;

        // Handle edge case where there is a large k value
        // Only running the accumulate fn when the vector size isnt too big to ensure there is no integer overflow
        if (chalk.size() <= 1000)
        {
            // chalk used for a full iteration cycle of the vector
            int chalkUsedPerCycle   = accumulate(chalk.begin(), chalk.end(), 0);
            int cyclesNeeded        = k/chalkUsedPerCycle;

            if (cyclesNeeded > 0)
            {
                k -= chalkUsedPerCycle * cyclesNeeded;
            }
        }

        for (;;)
        {
            // use available chalk
            if (chalk.at(student) <= k)
            {
                k -= chalk.at(student);
            }
            else
            {
                // student needs to replace chalk
                return student;
            }

            // restart loop
            student = (student < chalk.size()-1) ? student+1 : 0;
        }

        // should never reach here
        return student;
    }
};
