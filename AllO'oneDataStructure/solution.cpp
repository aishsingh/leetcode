class AllOne {
    private:
    unordered_map<string, int> strCountMap;
public:
    AllOne() 
    {
        
    }
    
    void inc(string key) 
    {
        strCountMap[key]++;
    }
    
    void dec(string key) 
    {
        if (--strCountMap[key] <= 0)
            strCountMap.erase(key);
    }
    
    string getMaxKey() 
    {
        int maxCount        = 0;
        string maxCountKey  = "";
        for (const auto& [key, count] : strCountMap)
        {
            if (count > maxCount)
            {
                maxCount = count;
                maxCountKey = key;
            }
        }

        return maxCountKey;
    }
    
    string getMinKey() 
    {
        int minCount        = INT_MAX;
        string minCountKey  = "";
        for (const auto& [key, count] : strCountMap)
        {
            if (count < minCount)
            {
                minCount = count;
                minCountKey = key;
            }
        }

        return minCountKey;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
