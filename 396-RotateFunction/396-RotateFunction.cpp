// Last updated: 7/5/2026, 11:04:10 PM
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0;
        long long current_F = 0;
        long long n = nums.size();
        
        // Calculate the initial sum of the array and F(0)
        for (long long i = 0; i < n; i++) {
            sum += nums[i];
            current_F += i * nums[i];
        }
        
        long long max_F = current_F;
        
        // Calculate F(k) using the derived formula
        for (long long i = n - 1; i >= 1; i--) {
            current_F = current_F + sum - n * nums[i];
            max_F = max(max_F, current_F);
        }
        
        return max_F;
    }
};