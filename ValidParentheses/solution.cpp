#include <map>

class Solution {
public:
    bool isValid(string s) {

        map<char, char> brackets = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        vector<char> openBrackets;
        for (auto i : s)
        {
            bool openBracketFound = brackets.contains(i);

            // handle end of string null char
            if (i == '/') break;

            if (openBrackets.size() == 0)
            {
                // Find open bracket
                if (openBracketFound)
                {
                    openBrackets.push_back(i);
                }
                else
                {
                    // Open bracket expected but not found
                    return false;
                }
            }
            else
            {
                // Find close bracket
                char expectedCloseBracket = brackets[openBrackets.back()];
                if (expectedCloseBracket != i)
                {
                    if (openBracketFound)
                    {
                        openBrackets.push_back(i);
                    }
                    else
                    {
                        // Unexpected char instead of expected close bracket or a supported open backet
                        return false;
                    }
                }
                else
                {
                    // found correct closing bracket
                    openBrackets.pop_back();
                }
            }
        }

        // return true only if all open brackets were closed
        return (openBrackets.size() == 0);;
    }
};
