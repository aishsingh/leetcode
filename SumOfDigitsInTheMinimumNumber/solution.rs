impl Solution {
    pub fn sum_of_digits(nums: Vec<i32>) -> i32 
    {
        let mut min = *nums.iter().min().unwrap();

        // iterate over digits adding to sum
        let mut digitSum = 0;
        while min > 0
        {
            let digit = min % 10;
            digitSum += digit;

            // iterate to next digit
            min /= 10;
        }

        return if digitSum % 2 == 0 { 1 } else { 0 };
    }
}
