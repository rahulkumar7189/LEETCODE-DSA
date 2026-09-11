// Last updated: 9/11/2026, 11:31:14 PM
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        
        vector<int> suffix_min(n);
        
        // Precompute the minimums from right to left
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = min(suffix_min[i + 1], nums[i]);
        }
        
        int current_max = nums[0];
        
        // Iterate left to right to find the first index that satisfies the condition
        for (int i = 0; i < n; ++i) {
            current_max = max(current_max, nums[i]);
            
            // Calculate instability score
            if (current_max - suffix_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};
