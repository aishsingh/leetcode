class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;

        // Loop through all digits from back to front
        for (int i = digits.size()-1; i >= 0 || carry; i--)
        {
            bool firstDigit = (i == digits.size()-1);
            bool loopingOnlyToCarry = (i < 0);

            // We have lopoed through all digits but are continuing because a carry is remaining before finishing
            if (loopingOnlyToCarry)
            {
                // add final carry
                digits.insert(digits.begin(), 1);
                break;
            }

            // Only add 1 on first digit or when carry is enabled
            if (firstDigit || carry)
            {
                carry = false;

                if (digits.at(i) < 9)
                {
                    // add 1
                    digits.at(i)++;
                }
                else
                {
                    // reset to 0 and enable carry
                    digits.at(i) = 0;
                    carry = true;
                }
            }
        }

        return digits;
    }
};
