// Last updated: 7/25/2026, 11:34:18 PM
// Extract each digit of n using modulo and division (% 10 and /= 10), keeping track of the two highest digits found (max1 and max2). Return their product.Complexity:Time Complexity: $\mathcal{O}(\log_{10} n)$ — processes each digit once.Space Complexity: $\mathcal{O}(1)$ — uses only a few variables.
1impl Solution {
2    pub fn max_product(mut n: i32) -> i32 {
3        let mut max1 = 0;
4        let mut max2 = 0;
5
6        while n > 0 {
7            let digit = n % 10;
8            n /= 10;
9
10            if digit > max1 {
11                max2 = max1;
12                max1 = digit;
13            } else if digit > max2 {
14                max2 = digit;
15            }
16        }
17
18        max1 * max2
19    }
20}