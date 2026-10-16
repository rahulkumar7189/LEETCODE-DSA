// Last updated: 10/16/2026, 7:07:05 AM
class Solution {
    struct Node {
        long long sq_sum = 0;
        long long sum = 0;
        long long lazy = 0;
    };
    
    vector<Node> tree;
    int MOD = 1e9 + 7;

    void push_up(int node) {
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
        tree[node].sq_sum = (tree[2 * node].sq_sum + tree[2 * node + 1].sq_sum) % MOD;
    }

    void apply(int node, int start, int end, long long val) {
        long long len = end - start + 1;
        // (x + val)^2 = x^2 + 2*val*x + val^2
        tree[node].sq_sum = (tree[node].sq_sum + 2 * val * tree[node].sum + val * val % MOD * len) % MOD;
        tree[node].sum = (tree[node].sum + val * len) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push_down(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            int mid = start + (end - start) / 2;
            apply(2 * node, start, mid, tree[node].lazy);
            apply(2 * node + 1, mid + 1, end, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (l > end || r < start) return;
        if (l <= start && end <= r) {
            apply(node, start, end, val);
            return;
        }
        push_down(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        push_up(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4 * n + 1);
        unordered_map<int, int> last_seen;
        long long total_ans = 0;

        for (int i = 0; i < n; ++i) {
            int last = last_seen.count(nums[i]) ? last_seen[nums[i]] : -1;
            
            // Update the segment tree for all starting indices from 'last + 1' to 'i'
            update(1, 0, n - 1, last + 1, i, 1);
            
             // tree[1].sq_sum contains the sum of squares of distinct counts for all subarrays ending at current index i
            total_ans = (total_ans + tree[1].sq_sum) % MOD;
            
            // Update the last seen position of the current element
            last_seen[nums[i]] = i;
        }

        return total_ans;
    }
};