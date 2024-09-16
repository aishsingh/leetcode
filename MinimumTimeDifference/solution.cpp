class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
        // sort time points so we dont need to check each element by element
        sort(timePoints.begin(), timePoints.end());

        // calc diff between time elements in a sequence since the vector is sorted
        int minDiff = INT_MAX;
        for (int i=0; i<timePoints.size()-1; i++)
        {
            int diff = findMinDifference(timePoints.at(i), timePoints.at(i+1));

            minDiff = min(minDiff, diff);
        }

        // check diff between first and last time elements because time is circular
        int diff = findMinDifference(timePoints.front(), timePoints.back());
        minDiff = min(minDiff, diff);

        return minDiff;
    }

    int findMinDifference(string time1, string time2)
    {
        const int minsIn1Hour   = 60;
        const int maxHours      = 24;
        const int maxMinutes    = maxHours*minsIn1Hour;

        int diff = abs(parseTimeToMins(time1) - parseTimeToMins(time2));

        return min(diff, (maxMinutes - diff) % maxMinutes);
    }

    int parseTimeToMins(string time)
    {
        int hours   = stoi(time.substr(0, 2));  // HH
        int mins    = stoi(time.substr(3, 2));  // MM

        int totalMins = (hours * 60) + mins;

        return totalMins;
    }
};
