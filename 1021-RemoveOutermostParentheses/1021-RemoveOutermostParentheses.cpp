// Last updated: 10/8/2026, 11:12:26 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If depth is greater than 0, it's not an outermost '('
                if (depth > 0) {
                    result += c;
                }
                depth++;
            } else {
                depth--;
                // If depth is greater than 0 after decrementing, it's not an outermost ')'
                if (depth > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};