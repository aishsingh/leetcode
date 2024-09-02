class Solution {
public:
    string addBinary(string a, string b) {
        string sum;

        int carry = 0;
        int i=0;
        while (i < a.size() || i < b.size() || carry > 0)
        {
            int num1 = (int(a.size())-1-i >= 0) ? a.at(a.size()-1-i) - '0' : 0;
            int num2 = (int(b.size())-1-i >= 0) ? b.at(b.size()-1-i) - '0' : 0;

            int binSum = num1 + num2 + carry;
            
            sum.insert(0, to_string(binSum & 0b01));

            carry = (binSum & 0b10) >> 1;
            i++;
        }

        return sum;
    }
};
