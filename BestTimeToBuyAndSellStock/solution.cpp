class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuyDay      = 0;
        int bestSellDay     = 0;
        bool buyDayFound    = false;
        bool sellDayFound   = false;

        for (int i=0; i<prices.size(); i++)
        {
            if (!buyDayFound || prices.at(i) < prices.at(bestBuyDay))
            {
                bestBuyDay = i;
                buyDayFound = true;
                continue;
            }
            if (!sellDayFound || prices.at(i) > prices.at(bestSellDay)) 
            {
                bestSellDay = i;
                sellDayFound = true;
            }
        }

        if (buyDayFound && sellDayFound)
        {
            int profit = prices.at(bestSellDay) - prices.at(bestBuyDay);
            return profit;
        }
        else
        {
            // Profit cannot be achieved
            return 0;
        }
    }
};
