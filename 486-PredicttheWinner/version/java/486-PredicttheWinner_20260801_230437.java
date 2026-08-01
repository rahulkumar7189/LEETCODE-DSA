// Last updated: 8/1/2026, 11:04:37 PM
/*
 * Solved using Dynamic Programming (Minimax). Instead of tracking both players' scores, the DP tracks the maximum score difference between the current player and the opponent. Space is optimized by using a 1D DP array instead of a 2D table, updating it iteratively for subarray lengths from 2 to n. If the final score difference (dp[0]) is >= 0, Player 1 wins.
 * 
 * Complexity:
 * 
 * Time Complexity: O(n^2) because we evaluate every possible subarray.
 * 
 * Space Complexity: O(n) for the 1D DP array used to optimize space.
*/

1class Solution {
2    public boolean predictTheWinner(int[] nums) {
3        int n = nums.length;
4        // dp[i] will store the maximum score difference the current player 
5        // can achieve starting from index i to j.
6        int[] dp = new int[n];
7        
8        // Base case: subarray of length 1. The score difference is just the number itself.
9        for (int i = 0; i < n; i++) {
10            dp[i] = nums[i];
11        }
12        
13        // Build the DP table for subarrays of length 2 up to n
14        for (int len = 2; len <= n; len++) {
15            for (int i = 0; i <= n - len; i++) {
16                int j = i + len - 1;
17                // Choose the left end (nums[i]) or the right end (nums[j])
18                // We subtract the opponent's best possible score difference (dp[i+1] or dp[i])
19                dp[i] = Math.max(nums[i] - dp[i + 1], nums[j] - dp[i]);
20            }
21        }
22        
23        // If the score difference >= 0, Player 1 wins or ties (which still counts as a win)
24        return dp[0] >= 0;
25    }
26}