// Last updated: 8/21/2026, 11:23:46 PM
1class Solution {
2    public long findKthSmallest(int[] coins, int k) {
3        int n = coins.length;
4        int totalSubsets = 1 << n;
5        long[] lcmValues = new long[totalSubsets];
6        
7        // Precompute the LCM for every possible subset of coins
8        for (int mask = 1; mask < totalSubsets; mask++) {
9            long currentLcm = 1;
10            for (int i = 0; i < n; i++) {
11                if ((mask & (1 << i)) != 0) {
12                    currentLcm = lcm(currentLcm, coins[i]);
13                }
14            }
15            lcmValues[mask] = currentLcm;
16        }
17
18        long left = 1;
19        long right = (long) k * 25; // max possible value since max coin value is 25
20        long ans = right;
21
22        // Binary Search
23        while (left <= right) {
24            long mid = left + (right - left) / 2;
25            
26            if (count(mid, lcmValues, n) >= k) {
27                ans = mid;        // Potential answer, try to find a smaller one
28                right = mid - 1;
29            } else {
30                left = mid + 1;   // Need a larger amount to reach k elements
31            }
32        }
33
34        return ans;
35    }
36
37    // Principle of Inclusion-Exclusion (PIE) to count valid amounts <= x
38    private long count(long x, long[] lcmValues, int n) {
39        long total = 0;
40        int totalSubsets = 1 << n;
41        
42        for (int mask = 1; mask < totalSubsets; mask++) {
43            // Count how many coins are in the current subset
44            int setBits = Integer.bitCount(mask);
45            
46            if (setBits % 2 == 1) {
47                total += x / lcmValues[mask]; // Add for odd size subsets
48            } else {
49                total -= x / lcmValues[mask]; // Subtract for even size subsets
50            }
51        }
52        return total;
53    }
54
55    // Helper method to find Greatest Common Divisor
56    private long gcd(long a, long b) {
57        while (b != 0) {
58            long temp = b;
59            b = a % b;
60            a = temp;
61        }
62        return a;
63    }
64
65    // Helper method to find Least Common Multiple
66    private long lcm(long a, long b) {
67        return (a / gcd(a, b)) * b;
68    }
69}