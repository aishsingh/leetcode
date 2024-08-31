class Solution {
public:
    string addBinary(string a, string b) {
        string sum;

        int carry = 0;
        int i=0;
        while (i < a.size()-1 || i < b.size()-1 || carry > 0)
        {
            int num1 = (i < a.size()) ? a.at(i) - '0' : 0;
            int num2 = (i < b.size()) ? b.at(i) - '0' : 0;

            int binSum = num1 + num2;
            if (binSum == 1)
            {
                binSum = 0;
                carry++;
                //carry--; keep the same as it should get incremented too


            }
            else if (binSum > 1)
            {
                  
            }

            sum.insert(0, to_string(binSum));
            i++;
        }

        return sum;
    }
};
