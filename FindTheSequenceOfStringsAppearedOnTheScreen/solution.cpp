class Solution {
public:
    vector<string> stringSequence(string target) 
    {
        vector<string> screenHistory;
        string screen;

        while (screen != target)
        {
            int letterIdx = screen.length()-1;

            // Add an 'a' letter if empty screen or if letters match
            if (screen.empty() || screen.back() == target.at(letterIdx))
            {
                // Key 1
                screen.append("a");
            }

            // Letters we are comparing do not match, increment to letter
            else if (screen.back() != target.at(letterIdx))
            {
                // Key 2
                screen.back()++;
            }


            // add change to history vector
            screenHistory.push_back(screen);
        }

        return screenHistory;
    }
};
