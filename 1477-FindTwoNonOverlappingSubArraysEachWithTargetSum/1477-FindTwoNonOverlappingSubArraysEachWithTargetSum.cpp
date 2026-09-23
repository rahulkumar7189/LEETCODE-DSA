// Last updated: 9/23/2026, 8:03:21 PM
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] stores the minimum length of a valid subarray ending at or before index i
        vector<int> min_len(n, INT_MAX / 2);
        
        int left = 0, sum = 0;
        int best_two_sum = INT_MAX / 2;
        int current_min = INT_MAX / 2;
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink the window if the sum exceeds the target
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            
            // If we found a valid subarray
            if (sum == target) {
                int len = right - left + 1;
                
                // If there is a valid non-overlapping subarray before 'left'
                if (left > 0) {
                    best_two_sum = min(best_two_sum, len + min_len[left - 1]);
                }
                
                // Update the current minimum length found so far
                current_min = min(current_min, len);
            }
            
            // Populate the DP array for the current index
            min_len[right] = current_min;
        }
        
        return best_two_sum >= INT_MAX / 2 ? -1 : best_two_sum;
    }
};