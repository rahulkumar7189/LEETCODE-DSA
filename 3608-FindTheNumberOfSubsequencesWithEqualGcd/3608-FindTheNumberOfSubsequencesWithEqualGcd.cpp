// Last updated: 7/14/2026, 2:31:48 PM
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int max_val = 0;
        
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        // dp[g1][g2] represents the number of ways to form two disjoint 
        // subsequences with GCD g1 and g2 respectively.
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        
        // Base case: both subsequences are empty (represented by GCD 0)
        dp[0][0] = 1;
        
        for (int x : nums) {
            // Copy current state to represent the "skip this element" choice
            vector<vector<int>> next_dp = dp;
            
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] > 0) {
                        // Choice 1: Add x to the first subsequence
                        int ng1 = (g1 == 0) ? x : std::gcd(g1, x);
                        next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % MOD;
                        
                        // Choice 2: Add x to the second subsequence
                        int ng2 = (g2 == 0) ? x : std::gcd(g2, x);
                        next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % MOD;
                    }
                }
            }
            // Move the calculated states to the primary dp array
            dp = move(next_dp);
        }
        
        int total_pairs = 0;
        
        // Sum up all valid pairs where g1 == g2 and both are non-empty (GCD > 0)
        for (int g = 1; g <= max_val; ++g) {
            total_pairs = (total_pairs + dp[g][g]) % MOD;
        }
        
        return total_pairs;
    }
};