// Last updated: 7/5/2026, 11:02:46 PM
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int M = r - l + 1;
        long long MOD = 1e9 + 7;
        
        // Allocate DP arrays outside the loop to prevent repeated heap allocations
        vector<vector<long long>> dp(2, vector<long long>(M, 1));
        vector<vector<long long>> next_dp(2, vector<long long>(M, 0));
        
        vector<long long> pref_up(M, 0);
        vector<long long> suff_down(M, 0);
        
        // Iteratively build up to length n
        for (int i = 2; i <= n; ++i) {
            // Compute prefix sums for dir = 1 (Up)
            pref_up[0] = dp[1][0];
            for (int x = 1; x < M; ++x) {
                pref_up[x] = (pref_up[x - 1] + dp[1][x]) % MOD;
            }
            
            // Compute suffix sums for dir = 0 (Down)
            suff_down[M - 1] = dp[0][M - 1];
            for (int x = M - 2; x >= 0; --x) {
                suff_down[x] = (suff_down[x + 1] + dp[0][x]) % MOD;
            }
            
            // Populate the next DP state
            for (int x = 0; x < M; ++x) {
                next_dp[0][x] = (x > 0) ? pref_up[x - 1] : 0;
                next_dp[1][x] = (x < M - 1) ? suff_down[x + 1] : 0;
            }
            
            // Shallow swap vectors instead of deep copying or moving into new allocations
            dp.swap(next_dp);
        }
        
        // Accumulate the answers from both direction states across all ending values
        long long total_valid_arrays = 0;
        for (int x = 0; x < M; ++x) {
            total_valid_arrays = (total_valid_arrays + dp[0][x] + dp[1][x]) % MOD;
        }
        
        return total_valid_arrays;
    }
};