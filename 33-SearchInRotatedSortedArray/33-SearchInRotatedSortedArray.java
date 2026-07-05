// Last updated: 7/5/2026, 11:04:18 PM
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if we found the target
            if (nums[mid] == target) {
                return mid;
            }
            
            // Determine if the left half is strictly sorted
            if (nums[left] <= nums[mid]) {
                // Check if the target falls within the sorted left half
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1; // Target is in the left half
                } else {
                    left = mid + 1;  // Target must be in the right half
                }
            } 
            // Otherwise, the right half must be strictly sorted
            else {
                // Check if the target falls within the sorted right half
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;  // Target is in the right half
                } else {
                    right = mid - 1; // Target must be in the left half
                }
            }
        }
        
        // Target not found
        return -1;
    }
}