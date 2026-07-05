// Last updated: 7/5/2026, 11:03:46 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        // Array to store the last seen positions of 'a', 'b', and 'c'
        vector<int> lastPos(3, -1);
        int count = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // Update the last seen position of the current character
            lastPos[s[right] - 'a'] = right;
            
            // If all three characters have been seen at least once
            if (lastPos[0] != -1 && lastPos[1] != -1 && lastPos[2] != -1) {
                // The number of valid substrings ending at 'right' is determined
                // by the minimum index among the last seen positions of 'a', 'b', and 'c'.
                count += min({lastPos[0], lastPos[1], lastPos[2]}) + 1;
            }
        }
        
        return count;
    }
};