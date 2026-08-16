// Last updated: 8/16/2026, 6:20:59 PM
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int max_len;
    int pref_len;
    int suff_len;
    int size;
};

class Solution {
private:
    vector<Node> tree;
    string str;

    // Helper function to merge two segment tree nodes
    Node merge(const Node& left, const Node& right, int mid) {
        Node parent;
        parent.size = left.size + right.size;
        parent.max_len = max(left.max_len, right.max_len);
        
        // Check if characters at the boundary can be merged
        if (str[mid] == str[mid + 1]) {
            parent.max_len = max(parent.max_len, left.suff_len + right.pref_len);
            
            // Update prefix length
            if (left.pref_len == left.size) {
                parent.pref_len = left.size + right.pref_len;
            } else {
                parent.pref_len = left.pref_len;
            }
            
            // Update suffix length
            if (right.suff_len == right.size) {
                parent.suff_len = right.size + left.suff_len;
            } else {
                parent.suff_len = right.suff_len;
            }
        } else {
            parent.pref_len = left.pref_len;
            parent.suff_len = right.suff_len;
        }
        
        return parent;
    }

    // Build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid);
    }

    // Update a character at a specific index
    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            str[idx] = ch;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        str = s;
        tree.resize(4 * n);
        
        build(1, 0, n - 1);
        
        int k = queryIndices.size();
        vector<int> ans(k);
        
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len; // Root node always holds global maximum
        }
        
        return ans;
    }
};
