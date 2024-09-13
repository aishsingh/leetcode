class Solution {
public:
    int hammingWeight(int n) 
    {
        int setBits = 0;

        // iterate bit by bit on n 
        while (n > 0)
        {
            // check if LSB is set
            if (n & 0x01)
                setBits++;

            // shift value down to next bit
            n = n >> 1;
        }

        return setBits;
    }
};
