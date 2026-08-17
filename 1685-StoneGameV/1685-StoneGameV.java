// Last updated: 8/17/2026, 2:55:11 PM
class Solution {
    int[][] memo;
    int[] prefix;

    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;
        memo = new int[n][n];
        prefix = new int[n + 1];
        
        // Build prefix sum array for O(1) subarray sum queries
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        return dp(stoneValue, 0, n - 1);
    }
    
    private int dp(int[] stoneValue, int i, int j) {
        if (i == j) return 0; // Base case: only one stone left, game ends.
        if (memo[i][j] != 0) return memo[i][j]; // Return cached result
        
        int maxScore = 0;
        
        // Try all possible split points k
        for (int k = i; k < j; k++) {
            int leftSum = prefix[k + 1] - prefix[i];
            int rightSum = prefix[j + 1] - prefix[k + 1];
            
            if (leftSum < rightSum) {
                maxScore = Math.max(maxScore, leftSum + dp(stoneValue, i, k));
            } else if (leftSum > rightSum) {
                maxScore = Math.max(maxScore, rightSum + dp(stoneValue, k + 1, j));
            } else {
                // If equal, Alice chooses the path that gives the maximum subsequent score
                maxScore = Math.max(maxScore, leftSum + Math.max(dp(stoneValue, i, k), dp(stoneValue, k + 1, j)));
            }
        }
        
        memo[i][j] = maxScore;
        return maxScore;
    }
}