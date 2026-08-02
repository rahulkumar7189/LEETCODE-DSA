// Last updated: 8/2/2026, 8:56:56 PM
class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        // dp[i] will store the maximum score difference the current player 
        // can achieve starting from index i to j.
        int[] dp = new int[n];
        
        // Base case: subarray of length 1. The score difference is just the number itself.
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }
        
        // Build the DP table for subarrays of length 2 up to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // Choose the left end (nums[i]) or the right end (nums[j])
                // We subtract the opponent's best possible score difference (dp[i+1] or dp[i])
                dp[i] = Math.max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }
        
        // If the score difference >= 0, Player 1 wins or ties (which still counts as a win)
        return dp[0] >= 0;
    }
}