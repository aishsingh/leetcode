class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        unordered_map<int, int> billsCollectedCount;

        const int lemonadePrice = 5;

        for (const auto& billGiven : bills)
        {
            // calc change
            int changeNeeded = billGiven - lemonadePrice;

            switch (changeNeeded)
            {
                case 15:
                {
                    // check if a $5 and $10 bill is available
                    if (billsCollectedCount[10] >= 1 &&
                        billsCollectedCount[5] >= 1 )
                    {
                        billsCollectedCount[10]--;
                        billsCollectedCount[5]--;
                        changeNeeded -= 15;
                    }
                    // check if a 3 $5 bills are available
                    else if (billsCollectedCount[5] >= 3)
                    {
                        billsCollectedCount[5] -= 3;
                        changeNeeded -= 5*3;
                    }

                    break;
                }

                case 10:
                {
                    // check if a $10 bill is available
                    if (billsCollectedCount[10] >= 1)
                    {
                        billsCollectedCount[10]--;
                        changeNeeded -= 10;
                    }
                    // check if 2 $5 bills are available
                    else if (billsCollectedCount[5] >= 2)
                    {
                        billsCollectedCount[5] -= 2;
                        changeNeeded -= 5*2;
                    }

                    break;
                }

                case 5:
                {
                    if (billsCollectedCount[5] >= 1)
                    {
                        billsCollectedCount[5]--;
                        changeNeeded -= 5;
                    }
                    break;
                }

            }

            // Check if change was found
            if (changeNeeded > 0)
            {
                return false;
            }

            // collect bill
            billsCollectedCount[billGiven]++;
        }

        // if we readched here then the correct amount of bills needed for all of the customers change was found
        return true;
    }
};
