// Last updated: 8/3/2026, 11:25:50 PM
class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;
        int[] dp = new int[n + 1];

        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            int maxDiff = Integer.MIN_VALUE;
            int currentTakeSum = 0;

            // Try taking 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                currentTakeSum += stoneValue[i + k - 1];
                maxDiff = Math.max(maxDiff, currentTakeSum - dp[i + k]);
            }

            dp[i] = maxDiff;
        }

        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
}