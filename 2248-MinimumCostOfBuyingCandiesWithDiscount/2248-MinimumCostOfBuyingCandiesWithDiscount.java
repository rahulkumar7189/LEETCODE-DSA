// Last updated: 7/5/2026, 11:03:21 PM
import java.util.Arrays;

class Solution {
    public int minimumCost(int[] cost) {
        // Sort the array in ascending order
        Arrays.sort(cost);
        
        int totalCost = 0;
        int n = cost.length;
        
        // Start from the most expensive candy (end of the sorted array)
        for (int i = n - 1; i >= 0; i--) {
            // Buy the 1st most expensive candy available
            totalCost += cost[i];
            
            // Buy the 2nd most expensive candy available (if it exists)
            if (i - 1 >= 0) {
                totalCost += cost[i - 1];
            }
            
            // The 3rd candy (at index i - 2) is free! 
            // We skip it by adjusting our loop index.
            i -= 2;
        }
        
        return totalCost;
    }
}