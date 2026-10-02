// Last updated: 10/2/2026, 3:41:01 PM
class Solution {
public:
    int m, n;
    bool visited[105][105][205]; // Max grid is 100x100, max open count is (100+100-1)/2 ≈ 100

    bool dfs(int r, int c, int open, vector<vector<char>>& grid) {
        // Boundary check
        if (r >= m || c >= n) return false;
        
        // Update the balance of parentheses
        open += (grid[r][c] == '(' ? 1 : -1);
        
        // If closed parentheses exceed open ones, or open ones exceed the maximum possible pairs to close
        if (open < 0 || open > (m + n - 1) / 2) return false;
        
        // If we reached the bottom-right corner, check if the string is perfectly balanced
        if (r == m - 1 && c == n - 1) return open == 0;
        
        // If this state has been visited and didn't return true, skip recalculating
        if (visited[r][c][open]) return false;
        visited[r][c][open] = true;
        
        // Move down or right
        return dfs(r + 1, c, open, grid) || dfs(r, c + 1, open, grid);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // Optimization: A valid path must have an even length to be balanced
        if ((m + n - 1) % 2 != 0) return false;
        
        // A valid path must start with an opening parenthesis and end with a closing one
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        
        memset(visited, false, sizeof(visited));
        return dfs(0, 0, 0, grid);
    }
};