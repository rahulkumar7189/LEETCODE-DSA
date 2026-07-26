// Last updated: 7/26/2026, 9:50:51 AM
1impl Solution {
2    pub fn maximum_product(nums: Vec<i32>) -> i32 {
3        let mut min1 = i32::MAX;
4        let mut min2 = i32::MAX;
5        let mut max1 = i32::MIN;
6        let mut max2 = i32::MIN;
7        let mut max3 = i32::MIN;
8
9        for x in nums {
10            if x <= min1 {
11                min2 = min1;
12                min1 = x;
13            } else if x < min2 {
14                min2 = x;
15            }
16
17            if x >= max1 {
18                max3 = max2;
19                max2 = max1;
20                max1 = x;
21            } else if x > max2 {
22                max3 = max2;
23                max2 = x;
24            } else if x > max3 {
25                max3 = x;
26            }
27        }
28
29        (max1 * max2 * max3).max(min1 * min2 * max1)
30    }
31}