class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;

        for (int i=0; i<s.size()-1; i++)
        {
            int letter1Ascii = int(s.at(i));
            int letter2Ascii = int(s.at(i+1));

            sum += abs(letter1Ascii - letter2Ascii);
        }

        return sum;
    }
};
