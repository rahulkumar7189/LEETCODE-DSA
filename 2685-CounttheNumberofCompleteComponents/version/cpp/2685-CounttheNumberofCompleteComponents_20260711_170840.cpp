// Last updated: 7/11/2026, 5:08:40 PM
1class Solution {
2public:
3    int countCompleteComponents(int n, vector<vector<int>>& edges) {
4        vector<vector<int>> adj(n);
5        for (const auto& edge : edges) {
6            adj[edge[0]].push_back(edge[1]);
7            adj[edge[1]].push_back(edge[0]);
8        }
9
10        vector<bool> visited(n, false);
11        int completeComponents = 0;
12
13        for (int i = 0; i < n; ++i) {
14            if (!visited[i]) {
15                vector<int> component;
16                queue<int> q;
17                
18                q.push(i);
19                visited[i] = true;
20                
21                while (!q.empty()) {
22                    int u = q.front();
23                    q.pop();
24                    component.push_back(u);
25                    
26                    for (int v : adj[u]) {
27                        if (!visited[v]) {
28                            visited[v] = true;
29                            q.push(v);
30                        }
31                    }
32                }
33
34                // Check completeness
35                long long v = component.size();
36                long long e2 = 0; // 2 * number of edges
37                for (int node : component) {
38                    e2 += adj[node].size();
39                }
40
41                if (e2 == v * (v - 1)) {
42                    completeComponents++;
43                }
44            }
45        }
46
47        return completeComponents;
48    }
49};