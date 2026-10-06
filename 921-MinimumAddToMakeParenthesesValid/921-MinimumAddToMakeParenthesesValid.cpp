// Last updated: 10/6/2026, 10:53:17 PM
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;  // Tracks the number of '(' we need to add
        int close_needed = 0; // Tracks the number of ')' we need to add

        for (char c : s) {
            if (c == '(') {
                // We found an open parenthesis, so we will need a closing one for it
                close_needed++;
            } else if (c == ')') {
                // We found a closing parenthesis
                if (close_needed > 0) {
                    // It matches with a previous unmatched '(', so we need one less ')'
                    close_needed--;
                } else {
                    // No unmatched '(' available, so we MUST add a new '(' to make this valid
                    open_needed++;
                }
            }
        }

        // The total additions required are the missing open and missing close parentheses
        return open_needed + close_needed;
    }
};