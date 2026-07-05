// Last updated: 7/5/2026, 11:03:15 PM
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Step 1: Build the adjacency list
        // Each node stores a list of pairs: {neighbor, road_distance}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        // Step 2: BFS to traverse the connected component starting from city 1
        queue<int> q;
        vector<bool> visited(n + 1, false);
        
        q.push(1);
        visited[1] = true;
        
        int min_score = 1e9; // Initialize with a large value

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Check all roads connected to the current city
            for (const auto& neighbor : adj[curr]) {
                int next_city = neighbor.first;
                int weight = neighbor.second;

                // Update the minimum score seen so far in this component
                min_score = min(min_score, weight);

                // If the next city hasn't been visited, push it to the queue
                if (!visited[next_city]) {
                    visited[next_city] = true;
                    q.push(next_city);
                }
            }
        }

        return min_score;
    }
};