// Last updated: 9/23/2026, 8:01:34 PM
class Solution {
    struct Node {
        int prod;
        int freq[5];
        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) freq[i] = 0;
        }
    };

    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right, int k) {
        Node res;
        res.prod = (left.prod * right.prod) % k;
        
        // Inherit prefixes completely from the left child
        for (int i = 0; i < k; ++i) {
            res.freq[i] = left.freq[i];
        }
        
        // Add prefixes that span across the left child and into the right child
        for (int i = 0; i < k; ++i) {
            if (right.freq[i] > 0) {
                int new_val = (left.prod * i) % k;
                res.freq[new_val] += right.freq[i];
            }
        }
        return res;
    }

    void build(int node, int l, int r, const vector<int>& nums, int k) {
        if (l == r) {
            tree[node].prod = nums[l] % k;
            tree[node].freq[nums[l] % k] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node + 1, l, mid, nums, k);
        build(2 * node + 2, mid + 1, r, nums, k);
        tree[node] = mergeNodes(tree[2 * node + 1], tree[2 * node + 2], k);
    }

    void update(int node, int l, int r, int idx, int val, int k) {
        if (l == r) {
            tree[node] = Node(); // Reset the frequency map
            tree[node].prod = val % k;
            tree[node].freq[val % k] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node + 1, l, mid, idx, val, k);
        } else {
            update(2 * node + 2, mid + 1, r, idx, val, k);
        }
        tree[node] = mergeNodes(tree[2 * node + 1], tree[2 * node + 2], k);
    }

    Node query(int node, int l, int r, int ql, int qr, int k) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if (qr <= mid) {
            return query(2 * node + 1, l, mid, ql, qr, k);
        }
        if (ql > mid) {
            return query(2 * node + 2, mid + 1, r, ql, qr, k);
        }
        return mergeNodes(query(2 * node + 1, l, mid, ql, qr, k),
                          query(2 * node + 2, mid + 1, r, ql, qr, k), k);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, nums, k);

        vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // 1. Update the tree permanently for the given index
            update(0, 0, n - 1, index, value, k);
            
            // 2. Query the subtree bounded by [start, n - 1]
            Node resNode = query(0, 0, n - 1, start, n - 1, k);
            result.push_back(resNode.freq[x]);
        }
        
        return result;
    }
};