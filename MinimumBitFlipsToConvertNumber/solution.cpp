class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        // XOR to find diff bits between goal and star nums
        int diffBits = (start ^ goal);

        // count how many high bits
        int highBitsInDiff = 0;
        while (diffBits > 0)
        {
            if (diffBits & 0x01)
            {
                highBitsInDiff++;
            }

            diffBits = diffBits >> 1;
        }

        return highBitsInDiff;
    }
};
