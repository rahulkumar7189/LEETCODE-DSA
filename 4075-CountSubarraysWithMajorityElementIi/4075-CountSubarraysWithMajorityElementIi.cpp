// Last updated: 7/5/2026, 11:02:31 PM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Standard Fenwick Tree implementation
    void update(vector<int>& bit, int idx, int val, int n) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(vector<int>& bit, int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Step 1: Generate all possible prefix sums
        vector<int> pref_sums(n + 1, 0);
        int current = 0;
        pref_sums[0] = 0;
        for (int i = 0; i < n; i++) {
            current += (nums[i] == target) ? 1 : -1;
            pref_sums[i + 1] = current;
        }

        // Step 2: Coordinate Compression
        vector<int> ranks = pref_sums;
        sort(ranks.begin(), ranks.end());
        ranks.erase(unique(ranks.begin(), ranks.end()), ranks.end());
        int m = ranks.size();

        auto get_rank = [&](int val) {
            return lower_bound(ranks.begin(), ranks.end(), val) - ranks.begin() + 1;
        };

        // Step 3: Count inversions via Fenwick Tree
        vector<int> bit(m + 1, 0);
        long long total_subarrays = 0;

        // Insert the initial prefix sum P[0] = 0
        update(bit, get_rank(0), 1, m);

        // Process prefix sums P[1] to P[n]
        current = 0;
        for (int i = 0; i < n; i++) {
            current += (nums[i] == target) ? 1 : -1;
            int r = get_rank(current);
            
            // Query how many previous prefix sums have a rank strictly less than r
            total_subarrays += query(bit, r - 1);
            
            // Add the current prefix sum rank to the Fenwick Tree
            update(bit, r, 1, m);
        }

        return total_subarrays;
    }
};