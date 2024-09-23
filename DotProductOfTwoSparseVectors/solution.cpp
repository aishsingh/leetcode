class SparseVector {
public:
    vector<int> numbers;

    SparseVector(vector<int> &nums) : numbers(nums) 
    {

    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        int sum = 0;

        for (int i=0; i<numbers.size(); i++)
        {
            // multiply each ith element between both vectors together
            // adding the result to the total sum
            sum += numbers.at(i) * vec.numbers.at(i);
        }

        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
