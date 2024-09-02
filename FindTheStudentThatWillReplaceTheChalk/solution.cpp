class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int student = 0;

        if (chalk.size() <= 1)
            return student;


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
