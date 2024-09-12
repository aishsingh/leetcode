class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
            return 1;

        // perform binary search to find sqrt
        int low = 0;
        int high = x;

        while (low <= high)
        {
            long mid = low + ((high - low) / 2);

            if (mid * mid == x)
            {
                return mid;
            }  

            if (mid * mid < x)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return high;
    }
};
