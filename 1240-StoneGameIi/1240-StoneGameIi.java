// Last updated: 8/16/2026, 6:21:40 PM
class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        if (n == 0) return 0;
        
        // memo[i][m] stores the maximum stones a player can get starting at index i with given M
        int[][] memo = new int[n][n + 1];
        
        // suffixSum[i] stores the sum of stones from pile i to the end
        int[] suffixSum = new int[n];
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        return dfs(0, 1, piles, suffixSum, memo);
    }
    
    private int dfs(int i, int m, int[] piles, int[] suffixSum, int[][] memo) {
        // If all piles are taken
        if (i == piles.length) {
            return 0;
        }
        
        // If the current player can take all the remaining piles
        if (i + 2 * m >= piles.length) {
            return suffixSum[i];
        }
        
        // Return precalculated result if it exists
        if (memo[i][m] != 0) {
            return memo[i][m];
        }
        
        int maxStones = 0;
        
        // Try all possible moves: take X piles where 1 <= X <= 2M
        for (int x = 1; x <= 2 * m; x++) {
            // Stones current player gets = Total remaining stones - Max stones opponent can get
            int currentStones = suffixSum[i] - dfs(i + x, Math.max(m, x), piles, suffixSum, memo);
            maxStones = Math.max(maxStones, currentStones);
        }
        
        // Store the result in memoization table and return
        memo[i][m] = maxStones;
        return maxStones;
    }
}