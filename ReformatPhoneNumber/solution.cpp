class Solution {
public:
    string reformatNumber(string number) 
    {
        // remove spaces and dashes
        erase(number, ' ');
        erase(number, '-');

        // build groups of 3
        int i = 0;
        while ((int)number.size() - i > 4)
        {
            i += 3;
            number.insert(number.begin() + i, '-');
            i++;    // increment to account for new elements inserted to stay at the expected index
        }

        // build groups of 2+2 if 4 digits left
        if ((int)number.size() - i == 4)
        {
            i += 2;
            number.insert(number.begin() + i, '-');
            i++;    // increment to account for new elements inserted to stay at the expected index
        }      

        return number;
    }
};
