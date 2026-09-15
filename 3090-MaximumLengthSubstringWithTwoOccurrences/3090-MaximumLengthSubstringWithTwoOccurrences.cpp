// Last updated: 9/15/2026, 11:53:14 PM
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLength = 0;
        vector<int> count(26, 0); // Frequency array for lowercase English letters
        
        int l = 0;
        for (int r = 0; r < s.length(); ++r) {
            count[s[r] - 'a']++; // Include the current character
            
            // Shrink the window from the left if any character appears more than twice
            while (count[s[r] - 'a'] > 2) {
                count[s[l] - 'a']--;
                l++;
            }
            
            // Update the maximum length of a valid substring found so far
            maxLength = max(maxLength, r - l + 1);
        }
        
        return maxLength;
    }
};
