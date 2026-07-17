// Last updated: 7/17/2026, 1:31:57 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> gcdValues(std::vector<int>& nums, std::vector<long long>& queries) {
        // Find the maximum value in the array to size our frequency arrays
        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) {
                max_val = x;
            }
        }
        
        // Count frequencies of each number in nums
        std::vector<long long> count(max_val + 1, 0);
        for (int x : nums) {
            count[x]++;
        }
        
        // exact_pairs[i] will store the exact number of pairs with GCD == i
        std::vector<long long> exact_pairs(max_val + 1, 0);
        
        // Iterate backward to apply inclusion-exclusion
        for (int i = max_val; i >= 1; --i) {
            long long c = 0;
            // Count how many elements are multiples of i
            for (int j = i; j <= max_val; j += i) {
                c += count[j];
            }
            
            // Total pairs where both elements are multiples of i
            long long pairs = c * (c - 1) / 2;
            
            // Subtract pairs where the GCD is a strict multiple of i
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= exact_pairs[j];
            }
            exact_pairs[i] = pairs;
        }
        
        // Create a prefix sum of the pair counts to answer queries via binary search
        std::vector<long long> prefix(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix[i] = prefix[i - 1] + exact_pairs[i];
        }
        
        std::vector<int> ans;
        ans.reserve(queries.size());
        
        for (long long q : queries) {
            // Since it's sorted, query 'q' (0-indexed) asks for the first GCD 'g'
            // such that the cumulative number of pairs up to 'g' is strictly greater than q.
            auto it = std::lower_bound(prefix.begin(), prefix.end(), q + 1);
            ans.push_back(std::distance(prefix.begin(), it));
        }
        
        return ans;
    }
};