#include <unordered_map>

class Solution {
public:

    /**
    * Plan:
    *     *
    */

    string numberToWords(int num) 
    {
        string words;

        unordered_map<int, string> digitsMap =
        {
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
        };

        unordered_map<int, string> unitsMap =
        {
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},

            {20, "Twenty"},
            {30, "Thirty"},
            {50, "Fifty"},

            {100, "Hundred"},
            {1000, "Thousand"},
            {1000000, "Million"},
        };

        // Iterate over number one unit at a time
        int units = 1;
        while (num > 0)
        {
            string word;
            int digit = num % 10;

            if (units < 10)
            {
                word = digitsMap[digit];
            }
            else if (units >= 10)
            {
                if ((units == 100 || units == 1000))
                {
                    word.append(digitsMap[digit] + " ");
                }

                int i = digit*units;
                if (unitsMap.count(i) > 0)
                {
                    word.append(unitsMap[i]);
                }
                else
                {
                    // Not in units list so it must be a constructable units word
                    word.append(digitsMap[digit] + "ty ");
                }
                    
                //else if (unitsMap[digit*units])
                    //word = digitsMap[digit];
                    
            }

            // Add spaces between words
            if (word.size() > 0 && units > 1)
                word.append(" ");

            words.insert(0, word);

            num /= 10;
            units *=10;
        }

        return words;
    }
};
