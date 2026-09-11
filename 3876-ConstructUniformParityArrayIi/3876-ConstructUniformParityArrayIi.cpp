// Last updated: 9/11/2026, 11:31:16 PM
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        
        // Find the minimum element in the array
        for (int x : nums1) {
            if (x < min_val) {
                min_val = x;
            }
        }
        
        // If the minimum element is odd, we can always make everything odd
        if (min_val % 2 != 0) {
            return true;
        }
        
        // If the minimum element is even, we can't change it to odd.
        // Therefore, we must make everything even.
        // We can only do this if there are no odd elements present at all.
        for (int x : nums1) {
            if (x % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};