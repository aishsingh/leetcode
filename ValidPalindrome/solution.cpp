class Solution {
public:
    bool isPalindrome(string s) 
    {

        for (int i=0; i<s.size(); i++)
        {
            if (isalnum(s.at(i)))
            {
                // convert letters to lowercase
                s.at(i) = tolower(s.at(i));
            }
            else
            {
                // remove non alpha-numeric char
                s.erase(s.begin() + i);
                i--;
            }
        }

        // Comparing front and back chars and increment closer to the middle
        for (int i=0; i<s.size()/2; i++)
        {
            char front  = *(s.begin()+i);
            char back   = *(s.end()-1-i);   // extra -1 to skip ending string null char

            if (front != back)
            {
                return false;
            }
        }

        return true;
    }
};
