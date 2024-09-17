class Solution {
public:
    int myAtoi(string s) 
    {
        long long converted = 0;
        int index = 0;
        bool negative = false;

        // handle edge case where string empty
        if (s.empty()) return 0;

        // 1. Ignore whitespaces
        for (auto c : s)
        {
            if (c == ' ')
                index++;
            else
                break;
        }

        // handle edge case where there is nothing after spaces
        if (index >= s.size()) return 0;

        // 2. Determine pos/neg sign
        if (s.at(index) == '-')
        {
            negative = true;
            index++;
        }
        else if (s.at(index) == '+')
        {
            negative = false;
            index++;
        }

        // 3. Integer conversion + 4. Rounding
        long long MAX = pow(2, 31)-1;
        for (int i=index; i<s.length(); i++)
        {
            // Check if not a digit char
            if (s.at(i) < '0' || s.at(i) > '9')
                break;

            // Parse digit and add to conversion int
            int digit = s.at(i) - '0';
            if (digit != string::npos)
            {
                if ((converted *10) + digit <= MAX)
                {
                    converted *= 10;
                    converted += digit;
                }
                else
                {
                    if (negative)
                        converted = MAX+1;
                    else
                        converted = MAX;
                }
            }
        }

        return (negative) ? -converted : converted;
    }
};
