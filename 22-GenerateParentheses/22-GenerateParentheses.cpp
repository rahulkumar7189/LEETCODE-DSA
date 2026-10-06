// Last updated: 10/6/2026, 10:54:13 PM
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // Base case: if the current string length is 2*n, it's a valid combination
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }
        
        // If we can still add an open parenthesis, do so
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        
        // If there are more open parentheses than close ones, we can add a close parenthesis
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};