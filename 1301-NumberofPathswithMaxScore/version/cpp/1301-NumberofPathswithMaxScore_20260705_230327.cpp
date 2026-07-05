// Last updated: 7/5/2026, 11:03:27 PM
// Approach: Bottom-Up Dynamic Programming (Tabulation)State Representation: * We use a 2D DP table dp[r][c] storing a pair<int, int> representing {max_score, path_count} to reach cell (r, c) from the bottom-right corner 'S'.Initialized with -1 score to represent unreachable states.Transitions:Since we need to move from the bottom-right (n-1, n-1) to the top-left (0, 0), we iterate backwards.For each cell, we check its three valid predecessors (moving towards 'E'): Down (r+1, c), Right (r, c+1), and Down-Right (r+1, c+1).We track the maximum score achievable among valid neighbors. If there's a tie, we sum their path counts modulo $10^9 + 7$.Base Case: * dp[n-1][n-1] = {0, 1} (Start at 'S' with a score of 0 and 1 valid path).Complexity AnalysisTime Complexity: $\mathcal{O}(n^2)$ — We traverse the $n \times n$ board exactly once, exploring a constant number of neighbors (3) for each cell.Space Complexity: $\mathcal{O}(n^2)$ — Required to maintain the DP grid of pairs. (Can be optimized to $\mathcal{O}(n)$ space since each row only depends on the current and next row).
1#include <vector>
2#include <string>
3#include <algorithm>
4
5using namespace std;
6
7class Solution {
8public:
9    vector<int> pathsWithMaxScore(vector<string>& board) {
10        int n = board.size();
11        int MOD = 1e9 + 7;
12        
13        // dp[r][c] stores {max_score, path_count}
14        // Initialize with -1 score to represent unreachable states
15        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
16        
17        // Base case: Starting point 'S' at the bottom-right corner
18        dp[n-1][n-1] = {0, 1};
19        
20        // Iterate backwards from the bottom-right to the top-left
21        for (int r = n - 1; r >= 0; --r) {
22            for (int c = n - 1; c >= 0; --c) {
23                // Skip the starting square (already initialized) and obstacles
24                if ((r == n - 1 && c == n - 1) || board[r][c] == 'X') {
25                    continue;
26                }
27                
28                int max_prev_score = -1;
29                long long paths = 0;
30                
31                // Directions to look at (predecessors moving from S to E):
32                // Down, Right, Down-Right
33                int dirs[3][2] = {{1, 0}, {0, 1}, {1, 1}};
34                
35                for (auto& dir : dirs) {
36                    int nr = r + dir[0];
37                    int nc = c + dir[1];
38                    
39                    // Check boundaries and if the neighbor is reachable
40                    if (nr < n && nc < n && dp[nr][nc].first != -1) {
41                        int neighbor_score = dp[nr][nc].first;
42                        
43                        if (neighbor_score > max_prev_score) {
44                            max_prev_score = neighbor_score;
45                            paths = dp[nr][nc].second;
46                        } else if (neighbor_score == max_prev_score) {
47                            paths = (paths + dp[nr][nc].second) % MOD;
48                        }
49                    }
50                }
51                
52                // If at least one valid incoming path exists, update the current cell
53                if (max_prev_score != -1) {
54                    int current_val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
55                    dp[r][c] = {max_prev_score + current_val, paths};
56                }
57            }
58        }
59        
60        // If 'E' at (0,0) is unreachable, return {0, 0}
61        if (dp[0][0].first == -1) {
62            return {0, 0};
63        }
64        
65        return {dp[0][0].first, dp[0][0].second};
66    }
67};