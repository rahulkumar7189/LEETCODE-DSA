// Last updated: 8/25/2026, 3:05:53 PM
class Solution {
    public long findKthSmallest(int[] coins, int k) {
        int n = coins.length;
        int totalSubsets = 1 << n;
        long[] lcmValues = new long[totalSubsets];
        
        // Precompute the LCM for every possible subset of coins
        for (int mask = 1; mask < totalSubsets; mask++) {
            long currentLcm = 1;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    currentLcm = lcm(currentLcm, coins[i]);
                }
            }
            lcmValues[mask] = currentLcm;
        }

        long left = 1;
        long right = (long) k * 25; // max possible value since max coin value is 25
        long ans = right;

        // Binary Search
        while (left <= right) {
            long mid = left + (right - left) / 2;
            
            if (count(mid, lcmValues, n) >= k) {
                ans = mid;        // Potential answer, try to find a smaller one
                right = mid - 1;
            } else {
                left = mid + 1;   // Need a larger amount to reach k elements
            }
        }

        return ans;
    }

    // Principle of Inclusion-Exclusion (PIE) to count valid amounts <= x
    private long count(long x, long[] lcmValues, int n) {
        long total = 0;
        int totalSubsets = 1 << n;
        
        for (int mask = 1; mask < totalSubsets; mask++) {
            // Count how many coins are in the current subset
            int setBits = Integer.bitCount(mask);
            
            if (setBits % 2 == 1) {
                total += x / lcmValues[mask]; // Add for odd size subsets
            } else {
                total -= x / lcmValues[mask]; // Subtract for even size subsets
            }
        }
        return total;
    }

    // Helper method to find Greatest Common Divisor
    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper method to find Least Common Multiple
    private long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }
}