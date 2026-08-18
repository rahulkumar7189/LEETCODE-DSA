// Last updated: 8/18/2026, 11:51:57 PM
class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        
        // Since constraints say 0 <= nums[i] <= 50, we can use a fixed-size array for frequencies
        int[] freq = new int[51];
        for (int num : nums) {
            freq[num]++;
        }
        
        // Case 1: k == 1
        if (k == 1) {
            int maxAlmostMissing = -1;
            for (int i = 50; i >= 0; i--) {
                if (freq[i] == 1) {
                    return i; // Since we are iterating downwards, the first one we find is the max
                }
            }
            return -1;
        } 
        
        // Case 2: k == n
        if (k == n) {
            int max = -1;
            for (int num : nums) {
                max = Math.max(max, num);
            }
            return max;
        } 
        
        // Case 3: 1 < k < n
        int maxAlmostMissing = -1;
        if (freq[nums[0]] == 1) {
            maxAlmostMissing = Math.max(maxAlmostMissing, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            maxAlmostMissing = Math.max(maxAlmostMissing, nums[n - 1]);
        }
        
        return maxAlmostMissing;
    }
}