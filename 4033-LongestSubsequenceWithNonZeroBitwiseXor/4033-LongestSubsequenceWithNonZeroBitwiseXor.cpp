// Last updated: 8/16/2026, 6:19:50 PM
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool has_nonzero = false;
        
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                has_nonzero = true;
            }
        }
        
        // If the entire array has a non-zero XOR
        if (total_xor != 0) {
            return nums.size();
        }
        
        // If total XOR is 0, check if we can remove 1 element
        return has_nonzero ? nums.size() - 1 : 0;
    }
};
