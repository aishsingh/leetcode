class Solution {
public:
    int calculateTime(string keyboard, string word) 
    {
        // Map keys to their indexes
        unordered_map<char, int> keyIndexMap;
        for (int i=0; i<keyboard.length(); i++)
        {
            int key = keyboard.at(i);
            keyIndexMap[key] = i;
        }

        // Calc moves needed to form word
        int moveCount = 0;
        int prevKeyIndex = 0;
        for (auto key : word)
        {
            int currKeyIndex = keyIndexMap[key];

            // add moves to sum
            int moves = abs(prevKeyIndex - currKeyIndex);
            moveCount += moves;

            prevKeyIndex = currKeyIndex;
        }

        return moveCount;    
    }
};
