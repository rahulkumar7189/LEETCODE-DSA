// Last updated: 7/5/2026, 11:03:14 PM
class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        // 1. Fast Fail: If the maximum value of one array is strictly less 
        // than the minimum value of the other, they cannot possibly overlap.
        if (nums1[nums1.length - 1] < nums2[0] || nums2[nums2.length - 1] < nums1[0]) {
            return -1; 
        }
        
        // 2. Micro-optimization: Store lengths in local variables.
        // This avoids calculating `.length` on every single iteration of the while loop.
        int n1 = nums1.length;
        int n2 = nums2.length;
        int i = 0;
        int j = 0;
        
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return -1;
    }
}