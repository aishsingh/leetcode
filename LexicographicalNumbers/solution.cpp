class Solution {
public: 

    vector<int> lexicalOrder(int n) 
    {
        vector<int> lexicalNums;
        
        int num = 1;
        for (int i=0; i<n; i++)
        {
            lexicalNums.push_back(num);

            if (num * 10 <= n)
            {
                // move on to next digit/level in lexicographical order
                num *= 10;
            }
            else
            {
                // go back to parent node if num exceeds n
                if (num >= n)
                    num /= 10;

                // increment to next num
                num++;

                // remove trailing zeros
                while (num % 10 == 0)
                   num /= 10;
            }
        }

        return lexicalNums;
    }
};
