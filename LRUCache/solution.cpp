#include <map>

struct CacheData
{
    int     weight  = 0;
    int     value   = 0;
};

class LRUCache {
private:
    unordered_map<int, CacheData> m_cache;
    int                 m_capacity   = 0;
    int                 m_maxWeight  = 0;

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (m_cache.contains(key))
        {
            m_cache[key].weight = ++m_maxWeight;
            return m_cache[key].value;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (m_cache.contains(key))
        {
            m_cache[key].weight = ++m_maxWeight;
            m_cache[key].value = value;
        }
        else if (m_cache.size() < m_capacity)
        {
            CacheData c;
            c.weight = ++m_maxWeight;
            c.value = value;

            m_cache[key] = c;
        }
        else
        {
            // Out of space, need to evict a key
            int lowestWeight = INT_MAX;
            int KeyWithlowestWeight = 0;
            for (auto const& i : m_cache)
            {
                if (i.second.weight < lowestWeight)
                {
                    lowestWeight = i.second.weight;
                    KeyWithlowestWeight = i.first;
                }
            }
            m_cache.erase(KeyWithlowestWeight);
            
            // Create new key overwriting old data
            CacheData c;
            c.weight = ++m_maxWeight;
            c.value  = value;

            m_cache[key] = c;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
