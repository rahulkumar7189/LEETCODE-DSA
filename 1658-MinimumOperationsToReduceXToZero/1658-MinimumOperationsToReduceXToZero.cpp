// Last updated: 9/23/2026, 8:03:05 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int target = total_sum - x;
        
        // Edge cases
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        
        int max_len = -1;
        int current_sum = 0;
        int left = 0;
        
        // Sliding window
        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];
            
            // Shrink the window if the sum exceeds the target
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            // Update max_len if we found a valid subarray
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};