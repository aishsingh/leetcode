class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) 
    {
        // Use hashmap to keep track of the indices of num2 using their value as keys
        unordered_map<int, int> hashmap;
        for (int i=0; i<nums2.size(); i++)
            hashmap[nums2.at(i)] = i;

        // Use mapping vector to map num1 to num2
        vector<int> mapping(nums1.size());
        for (int i=0; i<nums1.size(); i++)
            mapping.at(i) = hashmap[nums1.at(i)];

        return mapping;
    }
};
