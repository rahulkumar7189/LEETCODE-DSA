// Last updated: 10/11/2026, 10:51:10 PM
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        
        // The maximum possible difference is 10^5 based on the constraints.
        // We use a frequency array to count the occurrences of each difference.
        vector<long long> count(100001, 0);
        long long total_diff = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            total_diff += diff;
        }
        
        // We can combine k1 and k2 because modifying nums1 by +1 is the 
        // same as modifying nums2 by -1 in terms of the absolute difference.
        long long k = (long long)k1 + k2;
        
        // If we have enough operations to reduce all differences to 0
        if (total_diff <= k) {
            return 0;
        }
        
        // Greedily reduce the largest differences to the next smaller difference
        for (int i = 100000; i > 0 && k > 0; --i) {
            if (count[i] > 0) {
                // Determine how many elements we can reduce from difference `i` to `i-1`
                long long reduce = min(count[i], k);
                
                count[i] -= reduce;
                count[i - 1] += reduce;
                k -= reduce;
            }
        }
        
        // Calculate the final sum of squared differences
        long long min_sum_square = 0;
        for (long long i = 1; i <= 100000; ++i) {
            if (count[i] > 0) {
                min_sum_square += count[i] * i * i;
            }
        }
        
        return min_sum_square;
    }
};