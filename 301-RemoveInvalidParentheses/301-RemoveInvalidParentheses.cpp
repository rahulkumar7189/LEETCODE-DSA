// Last updated: 10/8/2026, 11:12:55 PM
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        
        // Step 1: Count how many misplaced left and right parentheses need removal
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) {
                    left_rem--;
                } else {
                    right_rem++;
                }
            }
        }
        
        vector<string> result;
        dfs(s, 0, left_rem, right_rem, result);
        return result;
    }
    
private:
    // Helper function to check if the current string is valid
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
    
    // Backtracking function
    void dfs(string s, int start, int left_rem, int right_rem, vector<string>& result) {
        // If we have removed the required number of parentheses, check validity
        if (left_rem == 0 && right_rem == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            // Skip duplicates to prevent duplicate strings in the result
            if (i > start && s[i] == s[i - 1]) continue;
            
            if (s[i] == '(' || s[i] == ')') {
                // Form the new string by removing the character at index i
                string next_str = s.substr(0, i) + s.substr(i + 1);
                
                // Try removing a right parenthesis if needed
                if (right_rem > 0 && s[i] == ')') {
                    dfs(next_str, i, left_rem, right_rem - 1, result);
                } 
                // Try removing a left parenthesis if needed
                else if (left_rem > 0 && s[i] == '(') {
                    dfs(next_str, i, left_rem - 1, right_rem, result);
                }
            }
        }
    }
};