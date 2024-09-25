class Logger {
private:
    unordered_map<string, int> msgMap;

public:

    Logger() 
    {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) 
    {
        int nextTimestamp = timestamp + 10;

        if (msgMap.count(message) == 0)
        {
            msgMap[message] = nextTimestamp;
            return true;
        }
        else
        {
            int prevTimestamp = msgMap[message];

            if (timestamp >= prevTimestamp)
            {
                msgMap[message] = nextTimestamp;
                return true;
            }
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */