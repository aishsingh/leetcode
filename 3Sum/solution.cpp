class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        bool zeroTripletFound = false;

        for (int i=0; i<nums.size(); i++)
        {
            for (int j=0; j<nums.size(); j++)
            {
                if (j == i)
                {
                    continue;
                }

                for (int k=0; k<nums.size(); k++)
                {
                    if (k == j || k == i)
                    {
                        continue;
                    }

                    if (nums.at(i) + nums.at(j) + nums.at(k) == 0)
                    {
                        // Triplet found
                        vector<int> triplet = {nums.at(i), nums.at(j), nums.at(k)};

                        // Check if distinct triplet
                        bool isTripletDistinct = true;
                        if (!zeroTripletFound &&
                            triplet.at(0) == 0 && 
                            triplet.at(1) == 0 && 
                            triplet.at(2) == 0)
                        {
                            // Zero triplet found
                            zeroTripletFound = true;
                            isTripletDistinct = true;
                        }
                        else
                        {
                            for (auto& r : result)
                            {
                                if (find(r.begin(), r.end(), triplet.at(0)) != r.end() &&
                                    find(r.begin(), r.end(), triplet.at(1)) != r.end() &&
                                    find(r.begin(), r.end(), triplet.at(2)) != r.end())
                                {
                                    // Not destinct!
                                    isTripletDistinct = false;
                                    break;
                                }
                            }
                        }



                        if (isTripletDistinct)
                        {
                            result.push_back(triplet);
                        }
                    }
                }
            }
        }

        return result;
    }
};
