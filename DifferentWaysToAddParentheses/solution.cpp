class Solution {
public:
    vector<int> diffWaysToCompute(string expression) 
    {
        vector<int> results;

        // Handle base cases
        if (expression.empty())
            return results;

        if (expression.length() == 1)
            return {expression.front() - '0'};

        if (expression.length() == 2)
        {
            int digit1 = expression.front() - '0';
            int digit2 = expression.back() - '0';
            int finalDigit = (digit1*10) + digit2;
            return { finalDigit };
        }

        // Handle main cases
        for (int i=0; i<expression.length(); i++)
        {
            int currentChar = expression.at(i);

            // Skip if digit
            if (isDigit(currentChar))
                continue;

            // Reached a operator char
            // Split the expression into left and right parts
            vector<int> leftResults     = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightResults    = diffWaysToCompute(expression.substr(i + 1));

            // Combine results from left and right parts
            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    int computedResult = 0;

                    // Perform the operation based on the current character
                    switch (currentChar) {
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }

                    results.push_back(computedResult);
                }
            }
        }

        return results;
    }

    bool isDigit(char c)
    {
        return (c >= '0' && c <= '9');
    }
};  
