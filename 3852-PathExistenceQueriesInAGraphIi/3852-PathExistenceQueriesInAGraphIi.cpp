// Last updated: 7/10/2026, 2:56:07 PM
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int maxL = 32 - __builtin_clz(n);
        vector<pair<int, int>> xId(n);
        for (int i = 0; i < n; i++) xId[i] = {nums[i], i};
        sort(xId.begin(), xId.end());
        
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[xId[i].second] = i;
        
        // Build the sparse table for binary lifting
        vector<vector<int>> up(maxL, vector<int>(n));
        for (int l = 0, r = 0; l < n; l++) {
            while (r + 1 < n && xId[r + 1].first - xId[l].first <= maxDiff) r++;
            up[0][l] = r;
        }
        
        for (int j = 1; j < maxL; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            if (u == v) { ans.push_back(0); continue; }
            if (u > v) swap(u, v);
            
            // 1. Check if direct edge exists (Distance 1)
            if (up[0][u] >= v) { 
                ans.push_back(1); 
                continue; 
            }
            
            // 2. Binary Lifting to find distance
            int steps = 0;
            for (int j = maxL - 1; j >= 0; j--) {
                if (up[j][u] < v) {
                    steps += (1 << j);
                    u = up[j][u];
                }
            }
            
            // 3. Final Reachability Check
            // After the loop, u is the furthest node strictly < v. 
            // If one more jump still doesn't reach v, it's truly unreachable.
            if (up[0][u] < v) {
                ans.push_back(-1);
            } else {
                ans.push_back(steps + 1); 
            }
        }
        return ans;
    }
};