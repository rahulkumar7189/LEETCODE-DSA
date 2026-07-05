// Last updated: 7/5/2026, 11:04:00 PM
class Solution {
public:
    int rotatedDigits(int n) {
        // Use a fixed-size stack array instead of a dynamic std::vector
        // 10001 safely covers the maximum constraint of n = 10^4
        int dp[10001] = {0}; 
        int valid_count = 0;
        
        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                // Base cases for single digits
                if (i == 0 || i == 1 || i == 8) {
                    dp[i] = 1;
                } else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    valid_count++;
                }
            } else {
                // Derive state from previously computed smaller numbers
                int prefix_state = dp[i / 10];
                int last_digit_state = dp[i % 10];
                
                if (prefix_state == 1 && last_digit_state == 1) {
                    dp[i] = 1;
                } else if (prefix_state >= 1 && last_digit_state >= 1) {
                    dp[i] = 2;
                    valid_count++;
                }
            }
        }
        
        return valid_count;
    }
};