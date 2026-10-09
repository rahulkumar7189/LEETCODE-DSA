// Last updated: 10/9/2026, 11:03:36 PM
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int needed_right = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If we have an odd number of needed right parentheses,
                // we must insert one ')' to complete the previous pair before adding a new '('.
                if (needed_right % 2 != 0) {
                    insertions++;
                    needed_right--;
                }
                needed_right += 2;
            } else { // c == ')'
                needed_right--;
                // If needed_right becomes negative, we have an excess of ')'
                // We must insert a matching '('
                if (needed_right < 0) {
                    insertions++;
                    // A newly inserted '(' requires two ')'. We just consumed one, so we still need one more.
                    needed_right += 2; 
                }
            }
        }
        
        // Add any remaining required right parentheses to the total insertions
        return insertions + needed_right;
    }
};