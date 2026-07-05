// Last updated: 7/5/2026, 11:02:54 PM
class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int maxFactor = 0;
        for (int[] item : items) {
            maxFactor = Math.max(maxFactor, item[0]);
        }
        
        // Step 1: Precompute the frequencies of each factor in the items array
        int[] freq = new int[maxFactor + 1];
        for (int[] item : items) {
            freq[item[0]]++;
        }
        
        // Step 2: Compute how many items have a factor divisible by 'f'
        int[] count = new int[maxFactor + 1];
        for (int f = 1; f <= maxFactor; f++) {
            if (freq[f] == 0) continue;
            for (int mult = f; mult <= maxFactor; mult += f) {
                count[f] += freq[mult];
            }
        }
        
        // Step 3: DP array where dp[w] is the max items we can get spending 'w'
        int[] dp = new int[budget + 1];
        
        for (int[] item : items) {
            int factor = item[0];
            int price = item[1];
            int bonus = count[factor]; // 1 purchased copy + (count[factor] - 1) free copies
            
            // 3a. Buy the FIRST copy: 0-1 Knapsack (iterate backwards)
            for (int w = budget; w >= price; w--) {
                dp[w] = Math.max(dp[w], dp[w - price] + bonus);
            }
            
            // 3b. Buy ADDITIONAL copies: Unbounded Knapsack (iterate forwards)
            for (int w = price; w <= budget; w++) {
                dp[w] = Math.max(dp[w], dp[w - price] + 1);
            }
        }
        
        // Find the maximum items we can get within the budget limit
        int maxItems = 0;
        for (int w = 0; w <= budget; w++) {
            maxItems = Math.max(maxItems, dp[w]);
        }
        
        return maxItems;
    }
}