// Last updated: 7/5/2026, 11:02:49 PM
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        // Build adjacency list: adj[u] = {(v, cost), ...}
        vector<vector<pair<int, int>>> adj(n);
        int max_cost = 0;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
            max_cost = max(max_cost, cost);
        }

        // Helper lambda to check if a valid path exists where all edge costs >= mid
        auto check = [&](int mid) -> bool {
            // Min-priority queue for Dijkstra: {current_total_cost, node}
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            vector<long long> dist(n, -1);
            
            pq.push({0, 0});
            dist[0] = 0;
            
            while (!pq.empty()) {
                auto [curr_cost, u] = pq.top();
                pq.pop();
                
                if (curr_cost > dist[u]) continue;
                if (u == n - 1) return curr_cost <= k;
                
                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int edge_cost = neighbor.second;
                    
                    // Filter out edges that don't meet our minimum score requirement
                    // and skip offline intermediate nodes
                    if (edge_cost < mid || !online[v]) continue;
                    
                    long long next_cost = curr_cost + edge_cost;
                    if (dist[v] == -1 || next_cost < dist[v]) {
                        dist[v] = next_cost;
                        pq.push({next_cost, v});
                    }
                }
            }
            return dist[n - 1] != -1 && dist[n - 1] <= k;
        };

        // Binary search range for the maximum minimum-edge cost
        int low = 0, high = max_cost, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;       // Found a valid path with score >= mid, try for a higher score
                low = mid + 1;
            } else {
                high = mid - 1;  // Score too high or no valid path exists, lower the bar
            }
        }
        
        return ans;
    }
};