impl Solution {
    pub fn or_array(nums: Vec<i32>) -> Vec<i32> 
    {
        // Declare answer vector with n-1 elements all initialised to 0
        let mut answer: Vec<i32> = vec![0; nums.len()-1];

        for i in 0..answer.len()
        {
            answer[i] = nums[i] | nums[i+1];
        }

        return answer;    
    }
}
