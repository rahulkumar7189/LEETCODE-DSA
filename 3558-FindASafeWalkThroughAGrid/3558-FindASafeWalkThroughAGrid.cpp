// Last updated: 7/5/2026, 11:02:58 PM
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Corrected initialization: an m x n matrix initialized to 10^9
        vector<vector<int>> min_health_loss(m, vector<int>(n, 1000000000));
        
        deque<pair<int, int>> dq;
        
        min_health_loss[0][0] = grid[0][0];
        dq.push_back({0, 0});
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                return (health - min_health_loss[r][c]) >= 1;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    
                    if (min_health_loss[r][c] + weight < min_health_loss[nr][nc]) {
                        min_health_loss[nr][nc] = min_health_loss[r][c] + weight;
                        
                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        
        return (health - min_health_loss[m - 1][n - 1]) >= 1;
    }
};