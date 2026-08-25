// Last updated: 8/25/2026, 3:06:26 PM
class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int s1 = 0, s2 = 0;
        int q1 = 0, q2 = 0;
        
        // Count sums and '?' for the left half
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                q1++;
            } else {
                s1 += (num[i] - '0');
            }
        }
        
        // Count sums and '?' for the right half
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                q2++;
            } else {
                s2 += (num[i] - '0');
            }
        }
        
        // If the total number of '?' is odd, Alice gets the last move and always wins
        if ((q1 + q2) % 2 != 0) {
            return true;
        }
        
        // Check if Bob can perfectly balance the sums
        if ((s1 - s2) * 2 == (q2 - q1) * 9) {
            return false; // Bob wins
        }
        
        return true; // Alice wins
    }
};