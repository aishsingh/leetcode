class Solution {
public:
    int findLucky(vector<int>& arr) {
        int largestLuckyNum = -1;

        // Sort array to make traversing easier
        sort(arr.begin(), arr.end());

        // Starting from decending order find the frequency of each number
        for (int i=arr.size()-1; i>=0; i--)
        {
            int numFreq = 1;
            for (int j=i-1; j>=0; j--)
            {
                if (arr.at(i) == arr.at(j))
                {
                    // same number, increase frequency and continue calculating freq
                    numFreq++;
                }
                else
                {
                    // different number, freq has been calculated
                    break;
                }
            }

            // Check if lucky number found
            if (numFreq == arr.at(i))
            {
                largestLuckyNum = numFreq;
                break;
            }
            else
            {
                // not lucky number, start again lower in the array skipping current numbers
                i = (i-numFreq)+1;
            }
        }

        return largestLuckyNum;
    }
};
