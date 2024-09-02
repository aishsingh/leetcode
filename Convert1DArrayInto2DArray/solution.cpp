class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        
        if ((m*n == original.size()))   // Check if there are enough original ints to be represented in the requested 2d array
        {
            result.resize(m, vector<int>(n));

            for (int row=0; row<m; row++)
            {
                for (int col=0; col<n; col++)
                {
                    result[row][col] = original.at((row*n) + col);
                }
            }
        }

        return result;
    }
};
