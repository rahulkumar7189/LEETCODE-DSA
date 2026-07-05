// Last updated: 7/5/2026, 11:02:40 PM
class Solution {
    public long maxTotalValue(int[] nums, int k) {
        int maxVal = Integer.MIN_VALUE;
        int minVal = Integer.MAX_VALUE;
        
        // Find the global maximum and minimum in the array
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
            if (num < minVal) {
                minVal = num;
            }
        }
        
        // Calculate the maximum possible difference for a single subarray
        long maxDifference = (long) maxVal - minVal;
        
        // Multiply by k since we can pick the same subarray k times
        return maxDifference * k;
    }
}