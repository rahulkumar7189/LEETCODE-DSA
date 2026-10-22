// Last updated: 10/22/2026, 11:05:38 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }
        
        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (i - idx + n) % n) {
                is_inc = false;
                break;
            }
        }
        
        if (is_inc) {
            // Option 1: Rotate left until 0 is at index 0.
            // Option 2: Reverse, rotate left, and reverse again.
            return min(idx, 2 + (n - idx) % n);
        }
        
        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (idx - i + n) % n) {
                is_dec = false;
                break;
            }
        }
        
        if (is_dec) {
            // Option 1: Rotate left until 0 is at the end, then reverse.
            // Option 2: Reverse first, which places 0 at (n - 1 - idx), then rotate left.
            return min((idx + 1) % n + 1, 1 + (n - 1 - idx));
        }
        
        return -1;
    }
};