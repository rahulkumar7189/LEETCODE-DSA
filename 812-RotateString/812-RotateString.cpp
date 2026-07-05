// Last updated: 7/5/2026, 11:03:59 PM
class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths don't match, they can never be rotations of each other
        if (s.length() != goal.length()) return false;
        
        int n = s.length();
        
        // Try every possible starting position 'i' in string 's'
        for (int i = 0; i < n; i++) {
            bool is_match = true;
            
            // Check if the sequence matches 'goal' starting from offset 'i'
            for (int j = 0; j < n; j++) {
                // Use modulo 'n' to wrap around to the beginning of 's'
                if (s[(i + j) % n] != goal[j]) {
                    is_match = false;
                    break;
                }
            }
            
            // If we checked all characters and didn't break, we found a match
            if (is_match) return true;
        }
        
        return false;
    }
};
