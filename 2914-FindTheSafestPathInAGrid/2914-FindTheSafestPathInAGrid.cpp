// Last updated: 7/5/2026, 11:03:07 PM
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If start or end cell has a thief, safeness factor is 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        // Step 1: Multi-source BFS to calculate distance to nearest thief
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Modified Dijkstra to find the path maximizing the minimum safeness factor
        // Priority Queue stores: {safeness_factor, {r, c}}
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({dist[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [sf, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            // Reached destination
            if (r == n - 1 && c == n - 1) {
                return sf;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // The safeness of a path is determined by its bottleneck (minimum safeness)
                    pq.push({min(sf, dist[nr][nc]), {nr, nc}});
                }
            }
        }

        return 0;
    }
};