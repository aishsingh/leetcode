class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        // Duplicate array and sort
        vector<int> resultArr (arr);
        sort(resultArr.begin(), resultArr.end());

        // Keep hashmap of values to remove duplicates and keep rank
        unordered_map<int, int> hashmap;    // <value, rank>
        for (int i=0; i<resultArr.size(); i++)
        {
            int val = resultArr[i];

            // check if value already exists in hashmap
            hashmap[val] = (hashmap.count(val) != 0) ? 
                            hashmap.size() :    // exisiting val, no addition as the size will stay the same since hashmaps do not keep duplicated
                            hashmap.size()+1;   // new val, +1 to account for new size after insert
        }

        // transform sorted array to rank array to be returned
        for (int i=0; i<resultArr.size(); i++)
        {
            // use original array values to keep original order
            int val = arr[i];

            // hashmap is used to replaec value with rank
            resultArr[i] = hashmap[val];
        }

        return resultArr;
    }
};
