class Solution {
public:
    int fib(int n) {
        
        // return straight away if n is the known inital fib numbers
        if (n == 0 || n == 1)
            return n;
        else
        {
            // Calc fib
            return fib(n-1) + fib(n-2);
        }
    }
};
