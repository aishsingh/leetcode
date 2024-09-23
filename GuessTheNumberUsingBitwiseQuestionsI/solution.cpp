/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int result = 0;

        // Iterate over each bit in a 30bit int (1 <= n <= 2^30 - 1)
        for (int i=0; i<30; i++)
        {
            int num = (1 << i);

            if (commonSetBits(num))
            {
                // if bit is set in num then it must be set in the number we are finding too
                // So set it in the result
                result |= num;
            }
        }

        return result;
    }
};
