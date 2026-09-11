// Last updated: 9/11/2026, 11:31:13 PM
class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        
        // Step 1: Precompute suffix minimums
        int[] suffMin = new int[n];
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = Math.min(suffMin[i + 1], nums[i]);
        }
        
        // Step 2: Traverse from left to right tracking prefix maximum
        int currentMax = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            currentMax = Math.max(currentMax, nums[i]);
            
            // Check if the instability score meets the stability criteria
            if (currentMax - suffMin[i] <= k) {
                return i; // Return the first (smallest) stable index
            }
        }
        
        return -1; // If no stable index is found
    }
}
