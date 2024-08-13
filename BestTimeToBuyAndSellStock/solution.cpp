#include <optional>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        optional<int>   buyDay  = 0;
        optional<int>   sellDay = 0;

        int             profit  = 0;

        for (int i=0; i<prices.size(); i++)
        {
            // Check if a better buy day can be found
            if (!buyDay || prices.at(i) < prices.at(buyDay.value()))
            {
                buyDay = i;
                
                // Sell day cant occur on buy day so continue to next iteration
                continue;
            }

            // Check if greater profit is possible
            if (!sellDay || prices.at(i) - prices.at(buyDay.value()) >= profit) 
            {
                sellDay = i;
                profit = prices.at(sellDay.value()) - prices.at(buyDay.value());
            }
        }

        return profit;
    }
};
