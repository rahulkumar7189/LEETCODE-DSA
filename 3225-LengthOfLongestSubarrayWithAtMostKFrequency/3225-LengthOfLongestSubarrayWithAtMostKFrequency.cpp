// Last updated: 8/16/2026, 6:20:46 PM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // Include the current element in the window
            count[nums[right]]++;
            
            // Shrink window from the left if frequency exceeds k
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }
            
            // Update the maximum length of a valid subarray
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};
