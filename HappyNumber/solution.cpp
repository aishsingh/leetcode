class Solution {
public:
    bool isHappy(int n) {
        
        // Use unordered set to track which values have been checked already to break out of possible endless loop
        unordered_set<int> set;

        // This loop ends only if number results in 1 or if an endless loop is detected (n == prev used value)
        while (n != 1 && set.count(n) == 0)
        {
            set.insert(n);
            n = addPowerOfEachDigit(n);
        }

        return (n == 1);
    }

    int addPowerOfEachDigit(int n){
        int newNumber = 0;

        // This loop seperates each digit in n and adds the power of each as newNumber
        while(n != 0){
            int num = n % 10;
            newNumber += num*num;
            n = n / 10;
        }
        return newNumber;
    }
};
