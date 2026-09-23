// Last updated: 9/23/2026, 8:01:36 PM
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> freq(k, 0);
        
        for (int num : nums) {
            int val = num % k;
            vector<long long> next_freq(k, 0);
            
            // Subarray starting and ending at the current element alone
            next_freq[val] += 1;
            
            // Subarrays extended by multiplying the current element
            for (int r = 0; r < k; ++r) {
                if (freq[r] > 0) {
                    next_freq[(1LL * r * val) % k] += freq[r];
                }
            }
            
            // Accumulate into the total result and update previous frequencies
            for (int r = 0; r < k; ++r) {
                result[r] += next_freq[r];
                freq[r] = next_freq[r];
            }
        }
        
        return result;
    }
};