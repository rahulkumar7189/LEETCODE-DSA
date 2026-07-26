// Last updated: 7/26/2026, 9:22:48 AM
/*
 * Greedy approach: Build the maximum integer by placing the largest valid digit (min(9, remaining_sum)) at each position from left to right for n digits. 
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/

1impl Solution {
2    pub fn largest_integer(n: i32, s: i32) -> i32 {
3        if s > 9*n {
4            return -1;
5        }
6
7        let mut ans =0;
8        let mut sum=s;
9        let mut digits = n;
10        while digits>0{
11            let d =sum.min(9);
12            ans=ans*10+d;
13            sum-=d;
14            digits-=1;
15            
16        }
17        ans
18    }
19}