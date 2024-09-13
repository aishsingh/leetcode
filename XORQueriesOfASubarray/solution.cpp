class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int> answer;

        // iterate over each query
        for (const auto& query : queries)
        {
            int leftIdx     = query[0];
            int rightIdx    = query[1];

            // calc xor result for the query
            int xorResult = 0; 
            for (int i=leftIdx; i<=rightIdx; i++)
            {
                xorResult ^= arr[i];
            }

            answer.push_back(xorResult);
        }

        return answer;
    }
};
