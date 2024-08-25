class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if (numRows == 1)
            return {{1}};

        vector<vector<int>> result = {{1}, {1, 1}};

        // Iterate rows
        for (int row=3; row<=numRows; row++)
        {
            vector<int> nums;
            nums.push_back(1);  // add initial row 1

            for (int col=1; col<row-1; col++)
            {
                int prevRowLeftNum = result.at(row-2).at(col-1);
                int prevRowRightNum = result.at(row-2).at(col);

                int newNum = prevRowLeftNum + prevRowRightNum;
                nums.push_back(newNum);
            }

            nums.push_back(1);  // add ending row 1

            result.push_back(nums);
        }

        return result;
    }
};
