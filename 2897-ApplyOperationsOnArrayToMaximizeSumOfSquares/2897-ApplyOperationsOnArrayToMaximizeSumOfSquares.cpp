// Last updated: 10/12/2026, 4:24:56 PM
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_counts(32, 0);
        long long mod = 1e9 + 7;
        
        // Count the occurrences of each bit across all numbers
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num >> i) & 1) {
                    bit_counts[i]++;
                }
            }
        }
        
        long long max_sum = 0;
        
        // Greedily construct the k largest possible numbers
        for (int i = 0; i < k; ++i) {
            long long current_num = 0;
            for (int bit = 0; bit < 32; ++bit) {
                if (bit_counts[bit] > 0) {
                    current_num |= (1LL << bit);
                    bit_counts[bit]--;
                }
            }
            max_sum = (max_sum + (current_num * current_num) % mod) % mod;
        }
        
        return max_sum;
    }
};