// Last updated: 8/16/2026, 6:21:21 PM
class Solution {
    public boolean winnerSquareGame(int n) {
        // dp[i] represents if the current player can win with i stones remaining
        boolean[] dp = new boolean[n + 1];
        
        // Build the DP table from 1 to n
        for (int i = 1; i <= n; i++) {
            // Try removing all possible non-zero square numbers
            for (int k = 1; k * k <= i; k++) {
                // If removing k*k stones puts the opponent in a losing state
                if (!dp[i - k * k]) {
                    dp[i] = true; // Current player wins
                    break; // No need to check other moves, we already found a winning strategy
                }
            }
        }
        
        return dp[n];
    }
}