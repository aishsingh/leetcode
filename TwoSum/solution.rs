use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> 
    {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();

        for i in 0..nums.len()
        {
            let curNum      = nums[i];
            let neededNum   = target - curNum;

            // check if needed value exists already in the hashmap
            // return the indices of both value if it does
            if (hashmap.contains_key(&neededNum))
            {
                return [i as i32, *hashmap.get(&neededNum).unwrap()].to_vec();
            }

            // add current value mapped to current index to hashmap sp it can be queried later
            hashmap.insert(curNum, i as i32);
        }

        // Should never reach here because one solution is guaranteed
        return [].to_vec();
    }
}
