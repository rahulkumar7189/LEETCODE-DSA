// Last updated: 7/5/2026, 11:03:56 PM
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        // dp[r][c] stores {max_score, path_count}
        // Initialize with -1 score to represent unreachable states
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        
        // Base case: Starting point 'S' at the bottom-right corner
        dp[n-1][n-1] = {0, 1};
        
        // Iterate backwards from the bottom-right to the top-left
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                // Skip the starting square (already initialized) and obstacles
                if ((r == n - 1 && c == n - 1) || board[r][c] == 'X') {
                    continue;
                }
                
                int max_prev_score = -1;
                long long paths = 0;
                
                // Directions to look at (predecessors moving from S to E):
                // Down, Right, Down-Right
                int dirs[3][2] = {{1, 0}, {0, 1}, {1, 1}};
                
                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    // Check boundaries and if the neighbor is reachable
                    if (nr < n && nc < n && dp[nr][nc].first != -1) {
                        int neighbor_score = dp[nr][nc].first;
                        
                        if (neighbor_score > max_prev_score) {
                            max_prev_score = neighbor_score;
                            paths = dp[nr][nc].second;
                        } else if (neighbor_score == max_prev_score) {
                            paths = (paths + dp[nr][nc].second) % MOD;
                        }
                    }
                }
                
                // If at least one valid incoming path exists, update the current cell
                if (max_prev_score != -1) {
                    int current_val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                    dp[r][c] = {max_prev_score + current_val, paths};
                }
            }
        }
        
        // If 'E' at (0,0) is unreachable, return {0, 0}
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        
        return {dp[0][0].first, dp[0][0].second};
    }
};