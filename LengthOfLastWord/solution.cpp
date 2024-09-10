class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int length = 0;

        // traverse string from the back
        bool foundEndOfWord = false;
        int endOfWordPos = -1;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (!foundEndOfWord && s.at(i) != ' ')
            {
                foundEndOfWord = true;
                endOfWordPos = i;
            }

            if (foundEndOfWord && (s.at(i) == ' ' || i == 0))
            {
                // found last word
                int startOfWordPos = (s.at(i) == ' ') ? i : i-1;    // this check ensures the start of the word pos is before the first char to ensure the length is correct

                length = endOfWordPos - startOfWordPos;
                break;
            }
        }

        return length;
    }
};
