// Last updated: 7/9/2026, 8:49:57 PM
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to optimize binary search runtime to O(log(min(m, n)))
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            // If partition1 is 0, nothing is on the left side of nums1. Use INT_MIN.
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            // If partition1 is m, nothing is on the right side of nums1. Use INT_MAX.
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            // If partition2 is 0, nothing is on the left side of nums2. Use INT_MIN.
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            // If partition2 is n, nothing is on the right side of nums2. Use INT_MAX.
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            // Check if we found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is odd
                if ((m + n) % 2 != 0) {
                    return std::max(maxLeft1, maxLeft2);
                }
                // If total number of elements is even
                return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
            }
            else if (maxLeft1 > minRight2) {
                // We are too far right in nums1, shift left
                high = partition1 - 1;
            }
            else {
                // We are too far left in nums1, shift right
                low = partition1 + 1;
            }
        }
        
        return 0.0; // Fallback case if arrays aren't sorted (guaranteed not to hit based on constraints)
    }
};