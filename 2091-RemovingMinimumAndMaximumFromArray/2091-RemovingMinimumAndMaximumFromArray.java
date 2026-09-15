// Last updated: 9/15/2026, 11:54:51 PM
class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;
        if (n <= 2) return n; // Corner case for small arrays

        int minIdx = 0;
        int maxIdx = 0;

        // Step 1: Find the positions of the min and max elements
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) {
                minIdx = i;
            }
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        // Step 2: Sort indices to know which one is closer to the front
        int left = Math.min(minIdx, maxIdx);
        int right = Math.max(minIdx, maxIdx);

        // Step 3: Compute deletions for all 3 scenarios
        int fromFront = right + 1;
        int fromBack = n - left;
        int fromBoth = (left + 1) + (n - right);

        // Return the minimum of the three approaches
        return Math.min(fromFront, Math.min(fromBack, fromBoth));
    }
}
