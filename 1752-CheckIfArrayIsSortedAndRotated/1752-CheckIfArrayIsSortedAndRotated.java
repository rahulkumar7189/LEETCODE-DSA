// Last updated: 9/15/2026, 11:55:35 PM
class Solution {
    public boolean check(int[] nums) {
        int count = 0;
        int n = nums.length;
        
        for (int i = 0; i < n; i++) {
            // Check if the current element is strictly greater than the next element
            // Use modulo operator % to wrap around and compare the last element with the first
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // If there's more than one drop, it's not a sorted and rotated array
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
}