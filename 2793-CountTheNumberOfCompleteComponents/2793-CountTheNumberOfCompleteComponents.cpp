// Last updated: 7/14/2026, 2:31:57 PM
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                queue<int> q;
                
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    component.push_back(u);
                    
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }

                // Check completeness
                long long v = component.size();
                long long e2 = 0; // 2 * number of edges
                for (int node : component) {
                    e2 += adj[node].size();
                }

                if (e2 == v * (v - 1)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};