// Last updated: 7/5/2026, 11:02:53 PM
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int maxFactor = 0;
        int minPrice = Integer.MAX_VALUE;
        
        // Find the maximum factor and the absolute minimum price
        for (int[] item : items) {
            maxFactor = Math.max(maxFactor, item[0]);
            minPrice = Math.min(minPrice, item[1]);
        }
        
        // Count frequencies of each factor
        int[] freq = new int[maxFactor + 1];
        for (int[] item : items) {
            freq[item[0]]++;
        }
        
        // Precompute how many items are a multiple of factor 'f'
        int[] multiples = new int[maxFactor + 1];
        for (int f = 1; f <= maxFactor; f++) {
            if (freq[f] == 0) continue; // Optimization: only compute for existing factors
            for (int m = f; m <= maxFactor; m += f) {
                multiples[f] += freq[m];
            }
        }
        
        // Create a list of profitable value-2 opportunities: [price, amount_available]
        List<int[]> opps = new ArrayList<>();
        long limit = 2L * minPrice;
        
        for (int[] item : items) {
            int factor = item[0];
            int price = item[1];
            int gain = multiples[factor] - 1; // Subtract 1 (can't map to itself)
            
            // Only consider items that offer 2 copies and are cheaper than buying 2 minPrice items
            if (gain > 0 && price < limit) {
                opps.add(new int[]{price, gain});
            }
        }
        
        // Sort opportunities greedily by price (cheapest first)
        opps.sort((a, b) -> Integer.compare(a[0], b[0]));
        
        long maxItems = (long) budget / minPrice; // Baseline if we buy 0 value-2 items
        long currentBudget = budget;
        long currentItems = 0;
        
        // Greedily consume the cheapest value-2 items
        for (int[] opp : opps) {
            long price = opp[0];
            long amount = opp[1];
            
            if (currentBudget < price) {
                break; // If we can't afford this, we can't afford any subsequent more expensive ones
            }
            
            // Take as many as possible (bounded by available amount and remaining budget)
            long take = Math.min(amount, currentBudget / price);
            currentBudget -= take * price;
            currentItems += 2 * take; // Each taken item yields 2 total copies
            
            // Calculate the score if we spent all remaining budget on the minPrice item
            long score = currentItems + (currentBudget / minPrice);
            maxItems = Math.max(maxItems, score);
        }
        
        return (int) maxItems;
    }
}