// Last updated: 10/11/2026, 10:50:58 PM
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        // Iterate through the 0-indexed array
        for (int i = 0; i < n; ++i) {
            // Check if the 1-based index (i + 1) divides n
            if (n % (i + 1) == 0) {
                sum += nums[i] * nums[i];
            }
        }
        
        return sum;
    }
};