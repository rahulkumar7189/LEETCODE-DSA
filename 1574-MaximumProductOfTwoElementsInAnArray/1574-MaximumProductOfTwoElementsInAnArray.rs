// Last updated: 7/29/2026, 11:39:44 AM
impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut first_max = 0;
        let mut second_max = 0;

        for &num in &nums {
            if num > first_max {
                second_max = first_max;
                first_max = num;
            } else if num > second_max {
                second_max = num;
            }
        }

        (first_max - 1) * (second_max - 1)
    }
}