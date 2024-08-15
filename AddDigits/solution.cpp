class Solution {
public:
    int addDigits(int num) {

        int sum = 0;
        while (num != 0)
        {
            sum += num % 10;

            // loop through to next digit
            num /= 10;
        }

        if (sum >= 10)
        {
            sum = addDigits(sum);
        }

        return sum;
    }
};

/* My solution without recusrion

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        do
        {
            sum = 0;

            while (num != 0)
            {
                sum += num % 10;

                // loop through to next digit
                num /= 10;
            }

            num = sum;
        } while (sum >= 10);

        return sum;
    }
};
*/
