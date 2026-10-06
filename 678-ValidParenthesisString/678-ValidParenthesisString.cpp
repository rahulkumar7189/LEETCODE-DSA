// Last updated: 10/6/2026, 10:53:28 PM
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // Minimum possible open '(' brackets
        int high = 0;  // Maximum possible open '(' brackets

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else if (c == '*') {
                low--;   // Treat '*' as ')'
                high++;  // Treat '*' as '('
            }

            // More ')' than '(' and '*' combined
            if (high < 0) {
                return false;
            }

            // Open bracket count cannot drop below 0
            if (low < 0) {
                low = 0;
            }
        }

        return low == 0;
    }
};