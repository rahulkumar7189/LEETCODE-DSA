// Last updated: 10/22/2026, 11:08:21 PM
class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;

    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if (m <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < m; ++i) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_res = dfs(left) % MOD;
        long long right_res = dfs(right) % MOD;
        
        int left_len = left.size();
        
        // Number of ways = (Combinations of interleaving) * (ways to form left) * (ways to form right)
        long long ans = table[m - 1][left_len];
        ans = (ans * left_res) % MOD;
        ans = (ans * right_res) % MOD;
        
        return ans;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute combinations (Pascal's Triangle) up to n
        table.resize(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            table[i][0] = 1;
            table[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
        
        // The problem asks for the number of ways to reorder, excluding the original array itself
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};